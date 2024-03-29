/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:17:17 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/03/03 22:47:13 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_top_node(t_stack **stack_source, t_stack **stack_destination)
{
	t_stack	*node_to_push;

	node_to_push = *stack_source;
	if (node_to_push->next)
	{
		*stack_source = node_to_push->next;
		node_to_push->next->previous = NULL;
	}
	else
		*stack_source = NULL;
	if (*stack_destination)
	{
		node_to_push->next = *stack_destination;
		node_to_push->next->previous = node_to_push;
	}
	else
	{
		node_to_push->previous = NULL;
		node_to_push->next = NULL;
	}
	*stack_destination = node_to_push;
	node_to_push->previous = NULL;
}

void	push_a(t_stack **stack_b, t_stack **stack_a)
{
	ft_printf("pa\n");
	push_top_node(stack_b, stack_a);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("pb\n");
	push_top_node(stack_a, stack_b);
}
