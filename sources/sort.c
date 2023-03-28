/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:24:51 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/28 14:28:42 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_unsorted_numbers(t_stack *current_node, t_stack **stack_a, t_stack **stack_b, int previous_value_pushed)
{
	push_b(stack_a, stack_b);
	if (current_node->number < previous_value_pushed)
		rotate_b(stack_b);	
}

int	push_descending_list(t_stack *current_node, t_stack **stack_a, t_stack **stack_b)
{
	int	previous_value_pushed;

	previous_value_pushed = 0;
	if (current_node->left_pile_top)
		previous_value_pushed = current_node->left_pile_top->number;
	else
		previous_value_pushed = current_node->number;
    push_b(stack_a, stack_b);
	rotate_b(stack_b);
	return (previous_value_pushed);
}

void	seperate_list_from_rest(t_stack **stack_a, t_stack **stack_b, t_stack *list_start)
{
	t_stack	*current_node;
	int		previous_value_pushed;
	int		final_a;
	bool	found_list_start;

	found_list_start = false;
	current_node = *stack_a;
	previous_value_pushed = current_node->number;
	while (*stack_a)
	{
		current_node = *stack_a;
		if (current_node->number == final_a && found_list_start) // break when found list start again
			break ;
		if (current_node == list_start) // first occurence of list start
		{
			found_list_start = true;
			final_a = list_start->number;
		}
		if (!current_node->part_of_ascending_list && current_node->part_of_descending_list) // part of ascending list
			previous_value_pushed = push_descending_list(current_node, stack_a, stack_b);
        else if (!current_node->part_of_ascending_list && !current_node->part_of_descending_list) // random numbers
			push_unsorted_numbers(current_node, stack_a, stack_b, previous_value_pushed);
		else // part of asecnding list
			rotate_a(stack_a);
	}
}
