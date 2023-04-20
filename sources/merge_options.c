/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:07:26 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/04/20 12:22:50 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	search_better_option_bottom_of_b(t_stack **stack_a,
	t_stack **stack_b, t_merge *merge)
{
	t_stack	*current_node;

	current_node = find_last_node(*stack_b);
	merge->b_distance = 1;
	while (merge->b_distance < merge->move_amount_optimal
		&& current_node->previous)
	{
		find_distance(stack_a, current_node, merge);
		if (merge->up_down_switch == 'u')
			check_if_optimal(merge, 'u', 'd');
		else if (merge->up_down_switch == 'd')
			check_if_optimal(merge, 'd', 'd');
		merge->a_distance = 0;
		merge->b_distance++;
		current_node = current_node->previous;
	}
}

void	search_better_option_top_of_b(t_stack **stack_a,
	t_stack *current_node, t_merge *merge)
{
	while (merge->b_distance < merge->move_amount_optimal && current_node->next)
	{
		current_node = current_node->next;
		merge->b_distance++;
		find_distance(stack_a, current_node, merge);
		if (merge->up_down_switch == 'u')
			check_if_optimal(merge, 'u', 'u');
		else if (merge->up_down_switch == 'd')
			check_if_optimal(merge, 'd', 'u');
		merge->a_distance = 0;
	}
}

void	check_option_first_number(t_stack **stack_a,
	t_stack *current_node, t_merge *merge)
{
	merge->b_up_or_down = 'u';
	merge->b_distance = 0;
	merge->move_amount_optimal = merge->stack_a_length;
	find_distance(stack_a, current_node, merge);
	merge->move_amount_optimal = merge->a_distance;
	if (merge->move_amount_optimal > merge->stack_a_length / 2)
	{
		merge->a_moves = merge->stack_a_length - merge->a_distance;
		merge->move_amount_optimal = merge->a_moves;
		merge->a_up_or_down = 'd';
	}
	else
	{
		merge->a_moves = merge->a_distance;
		merge->a_up_or_down = 'u';
	}
	merge->move_amount_optimal = merge->a_moves;
	merge->b_moves = merge->b_distance;
	merge->a_distance = 0;
}
