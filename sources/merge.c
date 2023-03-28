/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:50:25 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/28 15:09:40 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	execute_merge(t_stack **stack_a, t_stack **stack_b, t_merge *merge) // potentially check best direction
{
	while (merge->a_moves > 0 && merge->b_moves > 0)
	{
		rotate_ab(stack_a, stack_b);
		merge->a_moves--;
		merge->b_moves--;
	}
	while (merge->a_moves > 0)
	{
		rotate_a(stack_a);
		merge->a_moves--;
	}
	while (merge->b_moves > 0 )
	{
		rotate_b(stack_b);
		merge->b_moves--;
	}
	push_a(stack_b, stack_a);
	merge->stack_a_length++;
}

void	initialize_merge_parameters(t_merge *merge, t_stack **stack_a)
{
	merge->a_distance = 0;
	merge->b_distance = 0;
	merge->a_moves = 0;
	merge->b_moves = 0;
	merge->stored_optimal = 0;
	merge->optimal = 0;
	merge->stack_a_length = calculate_stack_size(*stack_a);
}

void	merge_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_merge	*merge;
	t_stack	*current_node;

	merge = ft_calloc(1, sizeof(t_merge));
	if (merge == NULL)
		exit (1);
	initialize_merge_parameters(merge, stack_a);
	current_node = *stack_b;
	while (*stack_b)
	{
		current_node = *stack_b;
		find_distance_of_first_node(stack_a, current_node, merge);
		if (merge->stored_optimal < 3 || current_node == current_node->next)
			execute_merge(stack_a, stack_b, merge);
		else
		{
			look_for_better_option(stack_a, current_node, merge);
			//look_for_better_option_bottom(stack_a, current_node, merge);
			execute_merge(stack_a, stack_b, merge);
		}
	}
}
