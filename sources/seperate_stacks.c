/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:24:51 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/04/17 13:33:13 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_rest(t_stack *current_node,
	t_stack **stack_a, t_stack **stack_b, int previous)
{
	push_b(stack_a, stack_b);
	if (current_node->number > previous)
		rotate_b(stack_b);
}

static int	push_desc_list(t_stack *current_node,
	t_stack **stack_a, t_stack **stack_b)
{
	int	previous_push;

	previous_push = 0;
	if (!current_node->left_pile_top)
		previous_push = current_node->number;
	else
		previous_push = current_node->left_pile_top->number;
	push_b(stack_a, stack_b);
	return (previous_push);
}

void	seperate_lists(t_stack **stack_a,
	t_stack **stack_b)
{
	t_stack	*current_node;
	int		previous;
	int		stack_size;
	int		i;

	stack_size = calculate_stack_size(*stack_a);
	i = 0;
	current_node = *stack_a;
	previous = current_node->number;
	while (i < stack_size && *stack_a)
	{
		if (stack_a_already_sorted(*stack_a))
			break ;
		current_node = *stack_a;
		if (current_node->part_of_ascending_list)
			rotate_a(stack_a);
		else if (current_node->part_of_descending_list)
			previous = push_desc_list(current_node, stack_a, stack_b);
		else
			push_rest(current_node, stack_a, stack_b, previous);
		i++;
	}
}
