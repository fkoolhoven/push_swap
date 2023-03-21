/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:50:05 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/21 11:56:23 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reset_indexes(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

int	stack_size(t_stack *stack)
{
	t_stack	*search;
	int		count;

	search = stack;
	if (stack == NULL)
		return (0);
	count = 1;
	while (search->next != '\0')
	{
		search = search->next;
		count++;
	}
	return (count);
}

t_stack	*find_last_node(t_stack *stack)
{
	t_stack	*search;

	if (!stack)
		return (NULL);
	search = stack;
	while (search->next != NULL)
		search = search->next;
	return (search);
}

void	append_node(t_stack **stack, t_stack *new_node)
{
	t_stack	*last_node;

	if (new_node == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last_node = find_last_node(*stack);
	last_node->next = new_node;
	new_node->previous = last_node;
}

void	prepend_node(t_stack **stack, t_stack *new_node)
{
	if (new_node == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	if (new_node->next)
		new_node->next->previous = NULL;
	new_node->next = *stack;
	if (new_node->previous)
		new_node->previous->next = NULL;
	new_node->previous = NULL;
	new_node->next->previous = new_node;
	*stack = new_node;
}

t_stack	*create_new_node(int content, int index)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->index = index;
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	initialize_stack(t_stack **stack, int argc, char **argv)
{
	t_stack	*new_node;
	int		number;
	int		i;
	int		index;

	index = 0;
	i = 1;
	while (i < argc)
	{
		number = ft_atoi(argv[i]);
		new_node = create_new_node(number, index);
		append_node(stack, new_node);
		index++;
		i++;
	}
}

void	print_linked_list(t_stack *stack)
{
	while (stack)
	{
		ft_printf("number at index %i =", stack->index);
		ft_printf(" %i\n", stack->content);
		stack = stack->next;
	}
}
