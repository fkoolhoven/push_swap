/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:17:17 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/27 17:40:08 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_top_node(t_stack **stack_origin, t_stack **stack_destination)
{
	t_stack	*node_to_push;

	node_to_push = *stack_origin; 
	if (node_to_push == NULL)
		return ;
	if (node_to_push->next) // if not last node to push
	{
		*stack_origin = node_to_push->next;
		node_to_push->next->previous = NULL;
	}
	else // last note to push after which stack empty
	{
		*stack_origin = NULL;
	}
	if (*stack_destination) // destination already exists
	{
		node_to_push->next = *stack_destination;
		node_to_push->next->previous = node_to_push;
		*stack_destination = node_to_push;
	}
	else // destination doesnt exist yet (empty stack)
	{
		node_to_push->previous = NULL;
		node_to_push->next = NULL;
		*stack_destination = node_to_push;
	}
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
