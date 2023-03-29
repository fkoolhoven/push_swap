/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_distance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:03:01 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/29 12:31:52 by fkoolhov         ###   ########.fr       */
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
	merge->up_down_switch = 'u';
	a_compare = *stack_a;
	total_distance = merge->b_distance + 1;
	merge->a_distance = 1;
	while (total_distance < merge->stored_optimal && a_compare->next) // check from top
	{
		if (found_right_position(current_node, a_compare))
			return (total_distance);
		a_compare = a_compare->next;
		merge->a_distance++;
		total_distance++;
	}
	merge->up_down_switch = 'd';
	a_compare = find_last_node(*stack_a);
	total_distance = merge->b_distance + 1;
	merge->a_distance = 1;
	while (total_distance < merge->stored_optimal && a_compare->previous) // check from bottom
	{
		if (found_right_position(current_node, a_compare->previous))
			return (total_distance);
		a_compare = a_compare->previous;
		merge->a_distance++;
		total_distance++;
	}
	return (total_distance);
}

void	search_better_option_bottom(t_stack **stack_a, t_stack **stack_b, t_merge *merge)
{
	t_stack	*current_node;

	current_node = find_last_node(*stack_b);
	merge->b_distance = 0;
	while (merge->b_distance < merge->stored_optimal && current_node->previous)
	{
		merge->b_distance++;
		merge->optimal = find_distance(stack_a, current_node, merge);
		if (merge->optimal < merge->stored_optimal && merge->up_down_switch == 'u' && merge->optimal < merge->amount_of_moves_needed) // condition maybe wrong
		{
			merge->stored_optimal = merge->optimal;
			merge->a_moves = merge->a_distance;
			merge->b_moves = merge->b_distance;
			merge->a_up_or_down = 'u';
			merge->b_up_or_down = 'd';
			calculate_amount_of_moves_needed(merge, 3);
		}
		else if (merge->optimal < merge->stored_optimal && merge->up_down_switch == 'd' && merge->optimal < merge->amount_of_moves_needed) // but amount of moved needed could be smaller than merge->optimal
		{
			merge->stored_optimal = merge->optimal;
			merge->a_moves = merge->a_distance;
			merge->b_moves = merge->b_distance;
			merge->a_up_or_down = 'd';
			merge->b_up_or_down = 'd';
			calculate_amount_of_moves_needed(merge, 4);
		}
		merge->a_distance = 0;
		current_node = current_node->previous;
	}
}

void	search_better_option_top(t_stack **stack_a, t_stack *current_node, t_merge *merge)
{
	while (merge->b_distance < merge->stored_optimal && current_node->next)
	{
		current_node = current_node->next;
		merge->b_distance++;
		merge->optimal = find_distance(stack_a, current_node, merge);
		if (merge->optimal < merge->stored_optimal && merge->up_down_switch == 'u') // but amount of moved needed could be smaller than merge->optimal
		{
			merge->stored_optimal = merge->optimal;
			merge->a_moves = merge->a_distance;
			merge->b_moves = merge->b_distance;
			merge->a_up_or_down = 'u';
			merge->b_up_or_down = 'u';
			calculate_amount_of_moves_needed(merge, 1);
		}
		else if (merge->optimal < merge->stored_optimal && merge->up_down_switch == 'd' && merge->optimal < merge->amount_of_moves_needed) // condition maybe wrong
		{
			merge->stored_optimal = merge->optimal;
			merge->a_moves = merge->a_distance;
			merge->b_moves = merge->b_distance;
			merge->a_up_or_down = 'd';
			merge->b_up_or_down = 'u';
			calculate_amount_of_moves_needed(merge, 2);
		}
		merge->a_distance = 0;
	}
}

void	find_distance_first_node(t_stack **stack_a, t_stack *current_node, t_merge *merge)
{
	merge->a_up_or_down = 'u';
	merge->b_up_or_down = 'u';
	merge->b_distance = 0;
	merge->stored_optimal = merge->stack_a_length;
	merge->stored_optimal = find_distance(stack_a, current_node, merge);
	merge->amount_of_moves_needed = merge->a_distance;
	if (merge->stored_optimal > merge->stack_a_length / 2)
	{
		merge->a_moves = merge->stack_a_length - merge->a_distance;
		merge->stored_optimal = merge->a_moves;
		merge->a_up_or_down = 'd';
	}
	else
		merge->a_moves = merge->a_distance;
	merge->b_moves = merge->b_distance;
	merge->a_distance = 0;
}
