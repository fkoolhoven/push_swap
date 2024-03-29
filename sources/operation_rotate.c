/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:17:46 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/03/03 22:47:24 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_elements_up(t_stack **stack)
{
	t_stack	*first_node;

	first_node = *stack;
	if (first_node == NULL || first_node->next == NULL)
		return ;
	*stack = first_node->next;
	(*stack)->previous = NULL;
	first_node->next = NULL;
	append_node(stack, first_node);
}

void	rotate_a(t_stack **stack_a)
{
	ft_printf("ra\n");
	rotate_elements_up(stack_a);
}

void	rotate_b(t_stack **stack_b)
{
	ft_printf("rb\n");
	rotate_elements_up(stack_b);
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("rr\n");
	rotate_elements_up(stack_a);
	rotate_elements_up(stack_b);
}
