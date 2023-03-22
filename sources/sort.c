/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:24:51 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/22 16:13:23 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	seperate_list_from_rest(t_stack **stack_a, t_stack **stack_b, t_stack *list_start)
{
	t_stack	*current_node;

	while (*stack_a)
	{
		current_node = *stack_a;
		if (!current_node->part_of_list)
			push_b(stack_a, stack_b);
		else
		{
			rotate_a(stack_a);
			if (*stack_a == list_start)
				break ;
		}
	}
}
