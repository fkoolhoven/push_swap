/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:17:17 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/23 17:07:19 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_top_node(t_stack **stack_origin, t_stack **stack_destination)
{
	t_stack	*first_node;

	if (*stack_origin == NULL)
		return ;
	first_node = *stack_origin;
	*stack_origin = first_node->next;
	reset_indexes(*stack_origin);
	if (*stack_destination == NULL)
		first_node->next = NULL;
	prepend_node(stack_destination, first_node);
	reset_indexes(*stack_destination);
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
