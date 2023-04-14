/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:50:25 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/04/14 19:42:53 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_merge	*initialize_merge_struct(t_stack **stack_a)
{
	t_merge	*merge;

	merge = ft_calloc(1, sizeof(t_merge));
	if (merge == NULL)
		ft_error_message("failed to alloc for merge struct");
	merge->up_down_switch = 'u';
	merge->a_up_or_down = 'u';
	merge->b_up_or_down = 'u';
	merge->a_distance = 0;
	merge->b_distance = 0;
	merge->move_amount_optimal = 0;
	merge->a_moves = 0;
	merge->b_moves = 0;
	merge->stack_a_length = calculate_stack_size(*stack_a);
	return (merge);
}

void	merge_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_merge	*merge;
	t_stack	*current_node;

	merge = initialize_merge_struct(stack_a);
	while (*stack_b)
	{
		current_node = *stack_b;
		find_distance_first_number(stack_a, current_node, merge);
		if (merge->move_amount_optimal < 2
			|| current_node == current_node->next)
			execute_merge(stack_a, stack_b, merge);
		else
		{	
			search_better_option_top(stack_a, current_node, merge);
			if (merge->move_amount_optimal < 2)
				execute_merge(stack_a, stack_b, merge);
			else
			{
				search_better_option_bottom(stack_a, stack_b, merge);
				execute_merge(stack_a, stack_b, merge);
			}
		}
	}
}
