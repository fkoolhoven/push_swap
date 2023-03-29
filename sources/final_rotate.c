/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:29:18 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/29 14:17:38 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_lowest_number(t_stack **stack_a)
{
	t_stack	*last_node;
	t_stack	*search;
	int		top_distance;

	last_node = find_last_node(*stack_a);
	search = *stack_a;
	top_distance = 0;
	if (search->number < last_node->number)
		return (top_distance);
	top_distance++;
	while (search->number < search->next->number && search)
	{
		search = search->next;
		top_distance++;
	}
	return (top_distance);
}

void	final_rotate(t_stack **stack_a)
{
	int		stack_size;
	int		top_distance;
	int		moves_needed;
	char	up_or_down;

	stack_size = calculate_stack_size(*stack_a);
	top_distance = find_lowest_number(stack_a);
	if (top_distance <= stack_size / 2)
	{
		moves_needed = top_distance;
		up_or_down = 'u';
	}
	else
	{
		moves_needed = stack_size - top_distance;
		up_or_down = 'd';
	}
	while (moves_needed > 0)
	{
		if (up_or_down == 'u')
			rotate_a(stack_a);
		else if (up_or_down == 'd')
			reverse_rotate_a(stack_a);
		moves_needed--;
	}
}
