/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:29:18 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/29 12:11:30 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_lowest_number(t_stack **stack_a)
{
	t_stack	*search;
	int		top_location;

	search = *stack_a;
	top_location = 1;
	while (search->number < search->next->number && search)
	{
		search = search->next;
		top_location++;
	}
	return (top_location);
}

void	final_rotate(t_stack **stack_a)
{
	int		stack_size;
	int		top_location;
	int		moves_needed;
	char	up_or_down;

	stack_size = calculate_stack_size(*stack_a);
	top_location = find_lowest_number(stack_a);
	if (top_location <= stack_size / 2)
	{
		moves_needed = top_location;
		up_or_down = 'u';
	}
	else
	{
		moves_needed = stack_size - top_location;
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
