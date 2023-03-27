/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:50:25 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/27 17:39:55 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// check top value of b
// iterate over a (top and bottom)
// find distance (amount of moves necessary) always starts at 1 because push
// optimal = distance
// if distance < 3 THEN execute 
// else check next value in b
// find distance (always starts at 2!)
// check only for nodes within original distance!
// if found a closer node execute

void	final_rotate(t_stack **stack_a)
{
	while (1) // check which way is most efficient to rotate // now only rotating up
	{
		if ((*stack_a)->number > (*stack_a)->next->number)
		{
			rotate_a(stack_a);
			break;
		}
		rotate_a(stack_a);
	}
}

void	execute_merge(t_stack **stack_a, t_stack **stack_b, t_merge *merge)
{
	if (!*stack_b)
		exit (1);
	while (merge->a_moves > 0 && merge->b_moves > 0)
	{
		rotate_ab(stack_a, stack_b);
		merge->a_moves--;
		merge->b_moves--;
	}
	while (merge->a_moves > 0)
	{
		rotate_a(stack_a);
		merge->a_moves--;
	}
	while (merge->b_moves > 0 )
	{
		rotate_b(stack_b);
		merge->b_moves--;
	}
	push_a(stack_b, stack_a);
	merge->stack_a_length++;
}

bool	in_ideal_position(t_stack **stack_a, t_stack *current_node)
{
	t_stack	*last_node;

	last_node = find_last_node(*stack_a);

	if (current_node->number < (*stack_a)->number && current_node->number < last_node->number && (*stack_a)->number < last_node->number) // it's beginning of list
		return (true);
	if (current_node->number > (*stack_a)->number && current_node->number > last_node->number && (*stack_a)->number < last_node->number) // it end of list
		return (true);
	if (current_node->number < (*stack_a)->number && current_node->number > last_node->number) // middle of list
		return (true);
	return (false);
}

int	find_distance(t_stack **stack_a, t_stack *current_node, t_merge *merge)
{
	t_stack	*a_compare;
	int		total_distance;

	if (current_node == NULL)
		return -1;
	if (in_ideal_position(stack_a, current_node))
	{
		merge->a_distance = 0;
		return (merge->b_distance);
	}
	a_compare = *stack_a;
	total_distance = merge->b_distance;
	total_distance++;
	merge->a_distance = 1;
	while (total_distance < merge->stored_optimal && a_compare && a_compare->next)
	{
		if (current_node->number > a_compare->number && current_node->number < a_compare->next->number)
		{
			break ;
		}
		else if (current_node->number > a_compare->number && current_node->number > a_compare->next->number && a_compare->next->number < a_compare->number)
		{
			break ;
		}
		else if (current_node->number < a_compare->number && current_node->number < a_compare->next->number && a_compare->next->number < a_compare->number)
		{
			break ;
		}
		a_compare = a_compare->next;
		merge->a_distance++;
		total_distance++;
	}
	return (total_distance);
}

int	find_first_distance(t_stack **stack_a, t_stack *current_node, t_merge *merge) // what if node should be inmeadiately at top? // also search from bottom now only rotating up but could be faster to rotate down
{
	t_stack	*a_compare;
	int		total_distance;

	if (current_node == NULL)
		return -1;
	if (in_ideal_position(stack_a, current_node) == true)
	{
		merge->a_distance = 0;
		return (merge->b_distance);
	}
	a_compare = *stack_a;
	total_distance = merge->b_distance;
	total_distance++;
	merge->a_distance = 1;
	while (a_compare && a_compare->next)
	{
		if (current_node->number > a_compare->number && current_node->number < a_compare->next->number)
		{
			break ;
		}
		else if (current_node->number > a_compare->number && current_node->number > a_compare->next->number && a_compare->next->number < a_compare->number)
		{
			break ;
		}
		else if (current_node->number < a_compare->number && current_node->number < a_compare->next->number && a_compare->next->number < a_compare->number)
		{
			break ;
		}
		a_compare = a_compare->next;
		merge->a_distance++;
		total_distance++;
	}
	return (total_distance);
}

void	merge_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_merge	*merge;
	t_stack	*current_node;

	// printf("\nBEFORE MERGING\n");
	// print_linked_list(*stack_a);
	// ft_printf("~~~~~~~~~~~~~\n");
	// print_linked_list(*stack_b);
	merge = ft_calloc(1, sizeof(t_merge));
	merge->a_distance = 0;
	merge->b_distance = 0;
	merge->a_moves = 0;
	merge->b_moves = 0;
	merge->stored_optimal = 0;
	merge->optimal = 0;
	merge->stack_a_length = calculate_stack_size(*stack_a);
	current_node = *stack_b;
	while (*stack_b)
	{
		current_node = *stack_b;
		//printf("\ncurrent top of b = %i\n", current_node->number);
		merge->b_distance = 0;
		merge->stored_optimal = find_first_distance(stack_a, current_node, merge);
		merge->a_moves = merge->a_distance;
		merge->b_moves = merge->b_distance;
		//printf("\ncurrent_top stored_optimal = %i and a_moves = %i and b_moves = %i\n", merge->stored_optimal, merge->a_moves, merge->b_moves);
		merge->a_distance = 0;
		// printf("\nfirst stored_optimal = %i\nmerge->a_moves = %i, merge->b_moves = %i\n", merge->stored_optimal, merge->a_moves, merge->b_moves);
		if (merge->stored_optimal < 3 || current_node == current_node->next)
		{
			//printf("\nSTORED OPTIMAL < 3, GOINT TO EXECUTE\n");
			execute_merge(stack_a, stack_b, merge);
		}
		else
		{
			while (merge->b_distance < merge->stored_optimal && current_node->next) // next or current node? // what if at end of list?
			{
				current_node = current_node->next;
				merge->b_distance++;
				merge->optimal = find_distance(stack_a, current_node, merge);
				if (merge->optimal < merge->stored_optimal)
				{
					//printf("\nFOUND BETTER NODE = %i\n", current_node->number);
					merge->stored_optimal = merge->optimal;
					merge->a_moves = merge->a_distance;
					merge->b_moves = merge->b_distance;
				}
				merge->a_distance = 0;
			}
			//printf("\nGOING TO EXECUTE AFTER LOOKING FOR BETTER NODE\n");
			execute_merge(stack_a, stack_b, merge);
		}

	}
}