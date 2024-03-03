/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:17:44 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/03/03 22:47:20 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_elements_down(t_stack **stack)
{
	t_stack	*last_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	if (last_node->previous)
		last_node->previous->next = NULL;
	last_node->previous = NULL;
	last_node->next->previous = last_node;
	*stack = last_node;
}

void	reverse_rotate_a(t_stack **stack_a)
{
	ft_printf("rra\n");
	rotate_elements_down(stack_a);
}

void	reverse_rotate_b(t_stack **stack_b)
{
	ft_printf("rrb\n");
	rotate_elements_down(stack_b);
}

void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("rrr\n");
	rotate_elements_down(stack_a);
	rotate_elements_down(stack_b);
}
