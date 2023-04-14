/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:09:43 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/04/14 19:41:06 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap_top_nodes(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;
	int		store_content;

	first_node = *stack;
	second_node = first_node->next;
	store_content = first_node->number;
	first_node->number = second_node->number;
	second_node->number = store_content;
}

void	swap_a(t_stack **stack_a)
{
	ft_printf("sa\n");
	swap_top_nodes(stack_a);
}

void	swap_b(t_stack **stack_b)
{
	ft_printf("sb\n");
	swap_top_nodes(stack_b);
}

void	swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("ss\n");
	swap_top_nodes(stack_a);
	swap_top_nodes(stack_b);
}
