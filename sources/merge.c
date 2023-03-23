/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:50:25 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/23 19:42:25 by fkoolhov         ###   ########.fr       */
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

void	execute_merge(t_merge *merge)
{
	// rotate a 
	// or rotate b
	// or rotate a and b
	// or reverse
	push_b();
	merge->stack_a_length++;
}

int	find_distance(t_stack **stack_a, t_stack *current_node, t_merge *merge)
{
	t_stack	*a_compare;
	int		distance;

	a_compare = *stack_a;
	distance = merge->b_distance;
	merge->a_distance = 0;
	while (distance < merge->optimal)
	{
		if (current_node->number > a_compare->number && current_node->number < a_compare->next->number)
			break ;
		a_compare = a_compare->next;
		distance++;
	}
	merge->a_distance = distance - merge->b_distance;
	return (distance);
}

void	merge_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_merge	*merge;
	t_stack	*current_node;
	int		i;

	current_node = *stack_b;
	merge->stored_optimal = 0;
	merge->optimal = 0;
	merge->stack_a_length = calculate_stack_size(*stack_a);
	while (*stack_b)
	{
		current_node = *stack_b;
		merge->b_distance = 0;
		merge->stored_optimal = find_distance(stack_a, current_node, merge);
		merge->best_option = current_node;
		merge->a_moves = merge->a_distance;
		merge->b_moves = merge->b_distance;
		if (merge->stored_optimal < 3)
			execute_merge(merge);
		while (merge->b_distance < merge->stored_optimal)
		{
			current_node = current_node->next;
			merge->b_distance++;
			merge->optimal = find_distance(stack_a, current_node, merge);
			if (merge->optimal < merge->stored_optimal)
			{
				merge->stored_optimal = merge->optimal;
				merge->best_option = current_node;
				merge->a_moves = merge->a_distance;
				merge->b_moves = merge->b_distance;
			}
			current_node = current_node->next;
			i++;
		}
	}
}