/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:50:05 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/04/13 16:33:42 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	calculate_stack_size(t_stack *stack)
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
	int		store;

	if (!stack)
		return (NULL);
	search = stack;
	store = search->number;
	while (search->next != NULL && search->next->number != store)
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
	new_node->next = NULL;
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
	if (new_node->next) // if node was at start of list
		new_node->next->previous = NULL;
	new_node->next = *stack;
	if (new_node->previous) // if node was at end of list
		new_node->previous->next = NULL;
	new_node->previous = NULL;
	new_node->next->previous = new_node;
	*stack = new_node;
}

t_stack	*create_new_node(int content)
{
	t_stack	*new_node;

	new_node = ft_calloc(1, sizeof(t_stack));
	if (new_node == NULL)
		ft_error_message("failed to alloc for new node");
	new_node->number = content;
	new_node->next = NULL;
	new_node->left_pile_top = NULL;
	new_node->right_pile_top = NULL;
	new_node->part_of_ascending_list = false;
	new_node->part_of_descending_list = false;
	return (new_node);
}

void	initialize_stack(t_stack **stack, int argc, char **argv)
{
	t_stack	*new_node;
	int		number;
	int		i;

	i = 1;
	while (i < argc)
	{
		number = ft_atoi(argv[i]);
		new_node = create_new_node(number);
		append_node(stack, new_node);
		i++;
	}
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
