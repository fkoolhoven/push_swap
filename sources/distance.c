/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:03:01 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/28 16:16:07 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_distance(t_stack **stack_a, t_stack *current_node, t_merge *merge) // now only tooking top to bottom but also wanna check bottom to top incase reverse rotate a is more efficient
{
	t_stack	*a_compare;
	int		total_distance;

	if (in_ideal_position(stack_a, current_node))
	{
		merge->a_distance = 0;
		return (merge->b_distance);
	}
	a_compare = *stack_a;
	total_distance = merge->b_distance + 1;
	merge->a_distance = 1;
	while (total_distance < merge->stored_optimal && a_compare->next)
	{
		if (found_right_position(current_node, a_compare))
			break ;
		a_compare = a_compare->next;
		merge->a_distance++;
		total_distance++;
	}
	return (total_distance);
}

void	look_for_better_option(t_stack **stack_a, t_stack *current_node, t_merge *merge) // perhaps also check a from bottom 
{
	while (merge->b_distance < merge->stored_optimal && current_node->next)
	{
		current_node = current_node->next;
		merge->b_distance++;
		merge->optimal = find_distance(stack_a, current_node, merge);
		if (merge->optimal < merge->stored_optimal)
		{
			merge->stored_optimal = merge->optimal;
			merge->a_moves = merge->a_distance;
			merge->b_moves = merge->b_distance;
		}
		merge->a_distance = 0;
	}
}

// check if option at bottom is more efficient
// works exactly the same way as top
// but if bottom is more efficient than should rotate b up, set some variable for tis DO THIS IN EXECUTE MERGE!!!
// but check if double moves of top isn't more efficient! how to calculate this? amount_of_moves_needed

void	look_for_better_option_bottom(t_stack **stack_a, t_stack **stack_b, t_merge *merge)
{
	t_stack	*current_node;

	current_node = find_last_node(*stack_b);
	merge->b_distance = 0;
	while (merge->b_distance < merge->stored_optimal && current_node->previous)
	{
		merge->b_distance++;
		merge->optimal = find_distance(stack_a, current_node, merge);
		if (merge->optimal < merge->stored_optimal && merge->optimal < merge->amount_of_moves_needed)
		{
			merge->stored_optimal = merge->optimal;
			merge->a_moves = merge->a_distance;
			merge->b_moves = merge->b_distance;
			merge->b_up_or_down = 'd';
		}
		merge->a_distance = 0;
		current_node = current_node->previous;
	}
}

void	find_distance_of_first_node(t_stack **stack_a, t_stack *current_node, t_merge *merge)
{
	merge->b_distance = 0;
	merge->b_up_or_down = 'u';
	merge->stored_optimal = merge->stack_a_length;
	merge->stored_optimal = find_distance(stack_a, current_node, merge);
	merge->a_moves = merge->a_distance;
	merge->b_moves = merge->b_distance;
	merge->a_distance = 0;
}