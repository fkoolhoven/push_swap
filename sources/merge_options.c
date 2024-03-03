/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:07:26 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/03/03 22:47:05 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_better_option_bottom_of_b(t_stack *stack_a,
	t_stack *stack_b, t_merge *merge)
{
	t_stack	*current_node;

	current_node = find_last_node(stack_b);
	merge->b_distance = 1;
	while (merge->b_distance < merge->move_amount_optimal
		&& current_node->previous)
	{
		find_distance(stack_a, current_node, merge);
		if (merge->up_down_switch == "up"[0])
			check_if_optimal(merge, "up"[0], "down"[0]);
		else if (merge->up_down_switch == "down"[0])
			check_if_optimal(merge, "down"[0], "down"[0]);
		merge->a_distance = 0;
		merge->b_distance++;
		current_node = current_node->previous;
	}
}

void	search_better_option_top_of_b(t_stack *stack_a,
	t_stack *current_node, t_merge *merge)
{
	while (merge->b_distance < merge->move_amount_optimal && current_node->next)
	{
		current_node = current_node->next;
		merge->b_distance++;
		find_distance(stack_a, current_node, merge);
		if (merge->up_down_switch == "up"[0])
			check_if_optimal(merge, "up"[0], "up"[0]);
		else if (merge->up_down_switch == "down"[0])
			check_if_optimal(merge, "down"[0], "up"[0]);
		merge->a_distance = 0;
	}
}

void	check_option_first_number(t_stack *stack_a,
	t_stack *current_node, t_merge *merge)
{
	merge->b_direction = "up"[0];
	merge->b_distance = 0;
	merge->move_amount_optimal = merge->stack_a_length;
	find_distance(stack_a, current_node, merge);
	merge->move_amount_optimal = merge->a_distance;
	if (merge->move_amount_optimal > merge->stack_a_length / 2)
	{
		merge->a_moves = merge->stack_a_length - merge->a_distance;
		merge->move_amount_optimal = merge->a_moves;
		merge->a_direction = "down"[0];
	}
	else
	{
		merge->a_moves = merge->a_distance;
		merge->a_direction = "up"[0];
	}
	merge->move_amount_optimal = merge->a_moves;
	merge->b_moves = merge->b_distance;
	merge->a_distance = 0;
}
