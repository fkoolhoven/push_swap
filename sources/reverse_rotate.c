/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:17:44 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/21 12:18:52 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_elements_down(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*last_node;

	first_node = *stack;
	if (first_node == NULL || first_node->next == NULL)
		return ;
	last_node = find_last_node(*stack);
	prepend_node(stack, last_node);
	reset_indexes(*stack);
}

void	reverse_rotate_a(t_stack **stack_a)
{
	ft_printf("\n\nExecuting reverse_rotate_a\n");
	rotate_elements_down(stack_a);
}

void	reverse_rotate_b(t_stack **stack_b)
{
	ft_printf("\n\nExecuting reverse_rotate_b\n");
	rotate_elements_down(stack_b);
}

void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("\n\nExecuting reverse_rotate_ab\n");
	rotate_elements_down(stack_a);
	rotate_elements_down(stack_b);
}
