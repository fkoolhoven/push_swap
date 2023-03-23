/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:24:51 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/23 18:50:03 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


// moves_a = calculate rotates or reverse rotates of a necessary
// moves_b = calculate rotates or reverse rotates of b necessary
// if moves_a == moves_b THEN rotate_ab or reverse_rotate_ab && push_b
// if moves_a < moves_b THEN rotate_a or reverse_rotate_a && push_b
// if moves_b == 0 || moves_b == 0 THEN push_b

// void	find_optimal_merge_move(t_stack *current_top_a, t_stack *current_top_b, t_merge **m)
// {
// 	t_merge	*merge;

// 	merge = *m;
// 	calculate_moves_a();
// 	calculate_moves_b();
// 	if (merge->a_moves < merge->b_moves)
// 	{
// 		merge->move_amount = merge->a_moves;
// 		merge->operation = merge->a_operation;
// 	}
// 	else if (merge->a_moves > merge->b_moves)
// 	{
// 		merge->move_amount = merge->b_moves;
// 		merge->operation = merge->b_operation;
// 	}
// 	else if (merge->a_moves == merge->b_moves)
// 	{
// 		if (merge->a_operation == merge->b_operation && merge->operation == "rotate") // strncompare
// 		{
// 			merge->move_amount = merge->a_moves;
// 			merge->operation = "rotate";
// 		}
// 		else if (merge->a_operation == merge->b_operation && merge->operation == "reverse_rotate") // strncompare
// 		{
// 			merge->move_amount = merge->a_moves;
// 			merge->operation = "reverse_rotate";
// 		}
// 		else
// 		{
// 			merge->move_amount = merge->a_moves;
// 			merge->operation = merge->a_operation;
// 		}
// 	}
// }

// void	merge_stacks(t_stack **stack_a, t_stack **stack_b)
// {
// 	t_stack	*current_top_a;
// 	t_stack	*current_top_b;
// 	t_merge	*merge;

// 	while ()
// 	{
// 		current_top_a = *stack_a;
// 		current_top_b = *stack_b;
// 		find_optimal_merge_move(current_top_a, current_top_b, &merge);
// 		execute_merge_move(current_top_a, current_top_b, &merge);
// 	}
// }

// void	merge_sorted_parts(t_stack **stack_a, t_stack **stack_b, t_stack *descend_start, t_stack *ascend_start)
// {
// 	t_stack	*current_node;
// 	t_stack	*top_of_stack_a;
//     int     moves;

// 	moves = 0;
// 	current_node = *stack_b;
// 	while (current_node != descend_start->next)
// 	{
// 		top_of_stack_a = *stack_a;
// 		while (current_node->number > top_of_stack_a->number && current_node->number != descend_start->number)
// 		{
// 			if (top_of_stack_a->number == ascend_start->number)
// 				break ;
// 			moves++;
// 			rotate_a(stack_a);
// 			top_of_stack_a = *stack_a;
// 		}
// 		if (current_node->number != descend_start->number)
// 		{

// 			current_node = current_node->next;
// 			moves++;
// 			push_a(stack_b, stack_a);
// 		}
// 		else if (current_node->number == descend_start->number)
// 		{
// 			moves++;
// 			moves++;
// 			push_a(stack_b, stack_a);
// 			rotate_a(stack_a);
// 			break ;
// 		}
// 		if (top_of_stack_a->number == ascend_start->number)
// 		{
// 			moves++;
// 			rotate_a(stack_a);
// 		}

// 	}
// 	printf("merging moves 2 = %i\n", moves);
// }

void	push_unsorted_numbers(t_stack *current_node, t_stack **stack_a, t_stack **stack_b, int previous_value_pushed)
{
	push_b(stack_a, stack_b);
	if (current_node->number < previous_value_pushed)
		rotate_b(stack_b);	
}

int	push_descending_list(t_stack *current_node, t_stack **stack_a, t_stack **stack_b)
{
	int	previous_value_pushed;

	previous_value_pushed = 0;
	if (current_node->left_pile_top)
		previous_value_pushed = current_node->left_pile_top->number;
	else
		previous_value_pushed = current_node->number;
    push_b(stack_a, stack_b);
	rotate_b(stack_b);
	return (previous_value_pushed);
}

void	seperate_list_from_rest(t_stack **stack_a, t_stack **stack_b, t_stack *list_start)
{
	t_stack	*current_node;
	int		previous_value_pushed;
	int		final_a;
	bool	found_list_start;

	found_list_start = false;
	current_node = *stack_a;
	previous_value_pushed = current_node->number;
	while (*stack_a)
	{
		current_node = *stack_a;
		if (current_node->number == final_a && found_list_start) // break when found list start again
			break ;
		if (current_node == list_start) // first occurence of list start
		{
			found_list_start = true;
			final_a = list_start->number;
		}
		if (!current_node->part_of_ascending_list && current_node->part_of_descending_list) // part of ascending list
			previous_value_pushed = push_descending_list(current_node, stack_a, stack_b);
        else if (!current_node->part_of_ascending_list && !current_node->part_of_descending_list) // random numbers
			push_unsorted_numbers(current_node, stack_a, stack_b, previous_value_pushed);
		else // part of asecnding list
			rotate_a(stack_a);
	}
}
