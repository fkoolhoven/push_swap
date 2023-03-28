/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:03:01 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/28 15:03:11 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_distance(t_stack **stack_a, t_stack *current_node, t_merge *merge)
{
	t_stack	*a_compare;
	int		total_distance;

	if (in_ideal_position(stack_a, current_node))
	{
		merge->a_distance = 0;
		return (merge->b_distance);
	}
	a_compare = *stack_a;
	total_distance = merge->b_distance + 1;
	merge->a_distance = 1;
	while (total_distance < merge->stored_optimal && a_compare->next)
	{
		if (found_right_position(current_node, a_compare))
			break ;
		a_compare = a_compare->next;
		merge->a_distance++;
		total_distance++;
	}
	return (total_distance);
}

void	look_for_better_option(t_stack **stack_a, t_stack *current_node, t_merge *merge)
{
	while (merge->b_distance < merge->stored_optimal && current_node->next) // next or current node? // what if at end of list?
	{
		current_node = current_node->next;
		merge->b_distance++;
		merge->optimal = find_distance(stack_a, current_node, merge);
		if (merge->optimal < merge->stored_optimal)
		{
			merge->stored_optimal = merge->optimal;
			merge->a_moves = merge->a_distance;
			merge->b_moves = merge->b_distance;
		}
		merge->a_distance = 0;
	}
}

void	find_distance_of_first_node(t_stack **stack_a, t_stack *current_node, t_merge *merge)
{
	merge->b_distance = 0;
	merge->stored_optimal = merge->stack_a_length;
	merge->stored_optimal = find_distance(stack_a, current_node, merge);
	merge->a_moves = merge->a_distance;
	merge->b_moves = merge->b_distance;
	merge->a_distance = 0;
}