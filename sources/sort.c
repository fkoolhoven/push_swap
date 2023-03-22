/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:24:51 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/22 20:03:56 by fkoolhov         ###   ########.fr       */
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

// void	seperate_list_from_rest(t_stack **stack_a, t_stack **stack_b, t_stack *list_start)
// {
// 	t_stack	*current_node;

// 	while (*stack_a)
// 	{
// 		current_node = *stack_a;
// 		if (!current_node->part_of_list)
// 			push_b(stack_a, stack_b);
// 		else
// 		{
// 			rotate_a(stack_a);
// 			if (*stack_a == list_start)
// 				break ;
// 		}
// 	}
// }
