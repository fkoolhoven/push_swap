/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:50:05 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/04/14 20:03:11 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	calculate_stack_size(t_stack *stack)
{
	int		stack_size;

	if (stack == NULL)
		return (0);
	stack_size = 1;
	while (stack->next != NULL)
	{
		stack = stack->next;
		stack_size++;
	}
	return (stack_size);
}

t_stack	*find_last_node(t_stack *stack)
{
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	append_node(t_stack **stack, t_stack *new_node)
{
	t_stack	*last_node;

	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last_node = find_last_node(*stack);
	new_node->next = NULL;
	last_node->next = new_node;
	new_node->previous = last_node;
}

void	prepend_node(t_stack **stack, t_stack *new_node)
{
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	if (new_node->next) // if node was at start of list
		new_node->next->previous = NULL;
	new_node->next = *stack;
	if (new_node->previous) // if node was at end of list
		new_node->previous->next = NULL;
	new_node->previous = NULL;
	new_node->next->previous = new_node;
	*stack = new_node;
}

void	print_linked_list(t_stack *stack)
{
	int i = 0;
	while (stack)
	{
		ft_printf("number at index %i =", i);
		ft_printf(" %i\n", stack->number);
		stack = stack->next;
		i++;
	}
}
