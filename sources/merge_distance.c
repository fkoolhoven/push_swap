/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_distance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:03:01 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/03/03 22:46:51 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_distance_from_bottom_of_a(t_stack *current_node,
			t_merge *merge, t_stack *stack_a)
{
	t_stack	*a_compare;

	a_compare = find_last_node(stack_a);
	merge->a_distance = 1;
	while (merge->a_distance < merge->move_amount_optimal)
	{
		if (found_right_position(current_node, a_compare->previous))
			return ;
		a_compare = a_compare->previous;
		merge->a_distance++;
	}
}

static bool	find_distance_from_top_of_a(t_stack *current_node,
			t_merge *merge, t_stack *a_compare)
{
	merge->a_distance = 1;
	while (merge->a_distance < merge->move_amount_optimal)
	{
		if (found_right_position(current_node, a_compare))
			return (true);
		a_compare = a_compare->next;
		merge->a_distance++;
	}
	return (false);
}	

void	find_distance(t_stack *stack_a, t_stack *current_node, t_merge *merge)
{
	merge->up_down_switch = "up"[0];
	if (no_need_to_rotate_a(stack_a, current_node))
		return ;
	else if (!find_distance_from_top_of_a(current_node, merge, stack_a))
	{
		merge->up_down_switch = "down"[0];
		find_distance_from_bottom_of_a(current_node, merge, stack_a);
	}
}
