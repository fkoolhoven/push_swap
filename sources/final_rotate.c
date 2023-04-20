/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:29:18 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/04/20 13:29:12 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_stack(t_stack *stack_a)
{
	t_stack	*temp;

	while (stack_a)
	{
		temp = stack_a;
		stack_a = stack_a->next;
		free (temp);
	}
}

static int	find_lowest_number(t_stack *stack_a)
{
	t_stack	*last_node;
	int		top_distance;

	last_node = find_last_node(stack_a);
	top_distance = 0;
	if (stack_a->number < last_node->number)
		return (top_distance);
	top_distance++;
	while (stack_a->number < stack_a->next->number && stack_a)
	{
		stack_a = stack_a->next;
		top_distance++;
	}
	return (top_distance);
}

void	final_rotate(t_stack *stack_a)
{
	int	stack_size;
	int	top_distance;
	int	moves_needed;

	stack_size = calculate_stack_size(stack_a);
	top_distance = find_lowest_number(stack_a);
	if (top_distance <= stack_size / 2)
	{
		moves_needed = top_distance;
		while (moves_needed > 0)
		{
			rotate_a(&stack_a);
			moves_needed--;
		}
	}
	else
	{
		moves_needed = stack_size - top_distance;
		while (moves_needed > 0)
		{
			reverse_rotate_a(&stack_a);
			moves_needed--;
		}
	}
	free_stack(stack_a);
}
