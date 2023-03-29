/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patience_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:24:51 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/29 12:28:13 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_unsorted_numbers(t_stack *current_node, t_stack **stack_a, t_stack **stack_b, int previous_value_pushed)
{
	push_b(stack_a, stack_b);
	if (current_node->number > previous_value_pushed)
		rotate_b(stack_b);
}

int	push_desc_list(t_stack *current_node, t_stack **stack_a, t_stack **stack_b)
{
	int	previous_value_pushed;

	previous_value_pushed = 0;
	if (current_node->left_pile_top)
		previous_value_pushed = current_node->left_pile_top->number;
	else
		previous_value_pushed = current_node->number;
	push_b(stack_a, stack_b);
	return (previous_value_pushed);
}

void	seperate_lists(t_stack **stack_a, t_stack **stack_b, t_stack *list_start)
{
	t_stack	*current_node;
	int		previous;
	int		final_a;
	bool	found_list_start;

	found_list_start = false;
	current_node = *stack_a;
	previous = current_node->number;
	while (*stack_a)
	{
		current_node = *stack_a;
		if (current_node->number == final_a && found_list_start)
			break ;
		if (current_node == list_start)
		{
			found_list_start = true;
			final_a = list_start->number;
		}
		if (current_node->part_of_ascending_list)
			rotate_a(stack_a);
		else if (current_node->part_of_descending_list)
			previous = push_desc_list(current_node, stack_a, stack_b);
		else
			push_unsorted_numbers(current_node, stack_a, stack_b, previous);
	}
}
