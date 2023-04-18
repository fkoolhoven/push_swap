/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:50:05 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/04/18 17:29:20 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	stack_still_seems_sorted(t_stack *stack_a, int top_of_a)
{
	if (stack_a->number > top_of_a)
		return (false);
	else if (stack_a->next == NULL)
		return (true);
	else if (stack_a->number > stack_a->next->number)
		return (false);
	return (true);
}

bool	stack_a_already_sorted(t_stack *stack_a)
{
	int		top_of_a;

	top_of_a = stack_a->number;
	while (stack_a->next != NULL && stack_a->number < stack_a->next->number)
		stack_a = stack_a->next;
	if (stack_a->next == NULL)
		return (true);
	stack_a = stack_a->next;
	while (stack_a && stack_still_seems_sorted(stack_a, top_of_a))
		stack_a = stack_a->next;
	if (stack_a == NULL)
		return (true);
	else
		return (false);
}

int	calculate_stack_size(t_stack *stack)
{
	int		stack_size;

	stack_size = 0;
	if (stack == NULL)
		return (stack_size);
	while (stack)
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
