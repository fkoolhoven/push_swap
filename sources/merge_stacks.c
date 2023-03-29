/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:50:25 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/29 16:47:50 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	execute_merge(t_stack **stack_a, t_stack **stack_b, t_merge *merge)
{
	// printf("\nBEFORE PUSHING\n");
	// print_linked_list(*stack_a);
	// ft_printf("~~~~~~~~~~~~~\n");
	// print_linked_list(*stack_b);
	if (merge->b_up_or_down == 'u' && merge->a_up_or_down == 'u')
		merge_ra_rb(stack_a, stack_b, merge);
	else if (merge->b_up_or_down == 'd' && merge->a_up_or_down == 'u')
		merge_ra_rrb(stack_a, stack_b, merge);
	else if (merge->b_up_or_down == 'u' && merge->a_up_or_down == 'd')
		merge_rra_rb(stack_a, stack_b, merge);
	else if (merge->b_up_or_down == 'd' && merge->a_up_or_down == 'd')
		merge_rra_rrb(stack_a, stack_b, merge);
	push_a(stack_b, stack_a);
	merge->stack_a_length++;
}

int	calculate_amount_of_moves_needed(t_merge *merge, int merge_pattern)
{
	int	amount_of_moves_needed;

	amount_of_moves_needed = 0;
	if (merge_pattern == 1 || merge_pattern == 4)
	{
		if (merge->a_distance == merge->b_distance)
			amount_of_moves_needed = merge->a_distance;
		else if (merge->a_distance > merge->b_distance)
			amount_of_moves_needed = merge->a_distance;
		else if (merge->b_distance > merge->a_distance)
			amount_of_moves_needed = merge->b_distance;
	}
	else if (merge_pattern == 2 || merge_pattern == 3)
		amount_of_moves_needed = merge->a_distance + merge->b_distance;
	return (amount_of_moves_needed);
}

void	initialize_merge_parameters(t_merge *merge, t_stack **stack_a)
{
	merge->optimal = 0;
	merge->stored_optimal = 0;
	merge->up_down_switch = 'u';
	merge->a_up_or_down = 'u';
	merge->b_up_or_down = 'u';
	merge->a_distance = 0;
	merge->b_distance = 0;
	merge->amount_of_moves_needed_stored = 0;
	merge->a_moves = 0;
	merge->b_moves = 0;
	merge->stack_a_length = calculate_stack_size(*stack_a);
}

void	merge_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_merge	*merge;
	t_stack	*current_node;

	merge = ft_calloc(1, sizeof(t_merge));
	if (merge == NULL)
		handle_errors("failed to alloc for merge struct");
	initialize_merge_parameters(merge, stack_a);
	while (*stack_b)
	{
		current_node = *stack_b;
		find_distance_first_node(stack_a, current_node, merge);
		if (merge->amount_of_moves_needed_stored < 2 || current_node == current_node->next)
			execute_merge(stack_a, stack_b, merge);
		else
		{	
			search_better_option_top(stack_a, current_node, merge);
			if (merge->amount_of_moves_needed_stored < 2)
				execute_merge(stack_a, stack_b, merge);
			else
			{
				search_better_option_bottom(stack_a, stack_b, merge);
				execute_merge(stack_a, stack_b, merge);
			}
		}
	}
}
