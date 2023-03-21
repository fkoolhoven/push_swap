/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:09:43 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/21 12:20:04 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap_top_nodes(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;
	int		store_content;

	first_node = *stack;
	if (first_node == NULL || first_node->next == NULL)
		return ;
	second_node = first_node->next;
	store_content = first_node->content;
	first_node->content = second_node->content;
	second_node->content = store_content;
}

void	swap_a(t_stack **stack_a)
{
	ft_printf("\n\nExecuting swap_a\n");
	swap_top_nodes(stack_a);
}

void	swap_b(t_stack **stack_b)
{
	ft_printf("\n\nExecuting swap_b\n");
	swap_top_nodes(stack_b);
}

void	swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("\n\nExecuting swap_ab\n");
	swap_top_nodes(stack_a);
	swap_top_nodes(stack_b);
}
