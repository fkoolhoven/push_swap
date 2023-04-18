/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:01:15 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/04/18 16:23:27 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	no_need_to_rotate_a(t_stack **stack_a, t_stack *current_node)
{
	t_stack	*last_node;

	last_node = find_last_node(*stack_a);
	if (current_node->number < (*stack_a)->number
		&& current_node->number < last_node->number
		&& (*stack_a)->number < last_node->number)
		return (true);
	else if (current_node->number > (*stack_a)->number
		&& current_node->number > last_node->number
		&& (*stack_a)->number < last_node->number)
		return (true);
	else if (current_node->number < (*stack_a)->number
		&& current_node->number > last_node->number)
		return (true);
	return (false);
}

bool	found_right_position(t_stack *current_node, t_stack *a_compare)
{
	if (current_node->number > a_compare->number
		&& current_node->number < a_compare->next->number)
		return (true);
	else if (current_node->number > a_compare->number
		&& current_node->number > a_compare->next->number
		&& a_compare->next->number < a_compare->number)
		return (true);
	else if (current_node->number < a_compare->number
		&& current_node->number < a_compare->next->number
		&& a_compare->next->number < a_compare->number)
		return (true);
	return (false);
}
