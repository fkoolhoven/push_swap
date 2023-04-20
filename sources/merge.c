/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:50:25 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/04/20 14:11:39 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	merge_stacks(t_merge *merge, t_stack **stack_a, t_stack **stack_b)
{	
	t_stack	*current_node;

	while (*stack_b)
	{
		current_node = *stack_b;
		check_option_first_number(*stack_a, current_node, merge);
		if (merge->move_amount_optimal < 2
			|| current_node == current_node->next)
			execute_merge(stack_a, stack_b, merge);
		else
		{	
			search_better_option_top_of_b(*stack_a, current_node, merge);
			if (merge->move_amount_optimal < 2)
				execute_merge(stack_a, stack_b, merge);
			else
			{
				search_better_option_bottom_of_b(*stack_a, *stack_b, merge);
				execute_merge(stack_a, stack_b, merge);
			}
		}
	}
}

static t_merge	*initialize_merge_struct(t_stack **stack_a)
{
	t_merge	*merge;

	merge = ft_calloc(1, sizeof(t_merge));
	if (merge == NULL)
		ft_error_message("failed to allocate memory for merge struct");
	merge->up_down_switch = "up"[0];
	merge->a_direction = "up"[0];
	merge->b_direction = "up"[0];
	merge->a_distance = 0;
	merge->b_distance = 0;
	merge->move_amount_optimal = 0;
	merge->a_moves = 0;
	merge->b_moves = 0;
	merge->stack_a_length = calculate_stack_size(*stack_a);
	return (merge);
}

void	perform_merge(t_stack **stack_a, t_stack **stack_b)
{
	t_merge	*merge;

	merge = initialize_merge_struct(stack_a);
	merge_stacks(merge, stack_a, stack_b);
	free (merge);
}
