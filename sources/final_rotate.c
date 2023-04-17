/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:29:18 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/04/17 14:19:16 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_arguments(char **arguments)
{
	arguments = NULL;
	// int	i;

	// i = 0;
	// // while (arguments[i])
	// // {
	// // 	printf("i = %i\n", i);
	// // 	free (arguments[i]);
	// // 	i++;
	// // }
	// free (arguments);
}

void	free_linked_list(t_stack *stack_a)
{
	while (stack_a)
	{
		free (stack_a);
		stack_a = stack_a->next;
	}
}

int	find_lowest_number(t_stack *stack_a)
{
	t_stack	*last_node;
	int		top_distance;

	last_node = find_last_node(stack_a);
	top_distance = 0;
	if (stack_a->number < last_node->number)
		return (top_distance);
	top_distance++;
	while (stack_a->number < stack_a->next->number && stack_a)
	{
		stack_a = stack_a->next;
		top_distance++;
	}
	return (top_distance);
}

void	final_rotate(t_stack *stack_a, char **arguments)
{
	int		stack_size;
	int		top_distance;
	int		moves_needed;
	char	up_or_down;

	stack_size = calculate_stack_size(stack_a);
	top_distance = find_lowest_number(stack_a);
	if (top_distance <= stack_size / 2)
	{
		moves_needed = top_distance;
		up_or_down = 'u';
	}
	else
	{
		moves_needed = stack_size - top_distance;
		up_or_down = 'd';
	}
	while (moves_needed > 0)
	{
		if (up_or_down == 'u')
			rotate_a(&stack_a);
		else if (up_or_down == 'd')
			reverse_rotate_a(&stack_a);
		moves_needed--;
	}
	free_linked_list(stack_a);
	free_arguments(arguments);
}
