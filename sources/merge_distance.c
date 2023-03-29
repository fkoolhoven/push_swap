/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_distance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:03:01 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/29 17:00:00 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_distance(t_stack **stack_a, t_stack *current_node, t_merge *merge)
{
	t_stack	*a_compare;
	int		total_distance;

	if (in_ideal_position(stack_a, current_node))
	{
		merge->a_distance = 0;
		return ;
	}
	merge->up_down_switch = 'u';
	a_compare = *stack_a;
	total_distance = merge->b_distance + 1;
	merge->a_distance = 1;
	while (total_distance < merge->amount_of_moves_needed_stored && a_compare->next) // check from top
	{
		if (found_right_position(current_node, a_compare))
			return ;
		a_compare = a_compare->next;
		merge->a_distance++;
		total_distance++;
	}
	merge->up_down_switch = 'd';
	a_compare = find_last_node(*stack_a);
	total_distance = merge->b_distance + 1;
	total_distance = 0; // this is the problem, get rid of all optimal stuff? // total_distance is not representing amount of moves needed
	merge->a_distance = 1;
	while (total_distance < merge->amount_of_moves_needed_stored && a_compare->previous) // check from bottom
	{
		printf("\nmerge->stored_optimal = %i\n", merge->stored_optimal);
		if (found_right_position(current_node, a_compare->previous))
			return ;
		a_compare = a_compare->previous;
		merge->a_distance++;
		total_distance++;
	}
	printf("\nbottom a_distance for number %i = %i\n", current_node->number, merge->a_distance);
}

void	search_better_option_bottom(t_stack **stack_a, t_stack **stack_b, t_merge *merge)
{
	int		new_move_amount;
	t_stack	*current_node;

	current_node = find_last_node(*stack_b);
	merge->b_distance = 0;
	while (merge->b_distance < merge->stored_optimal && current_node->previous)
	{
		merge->b_distance++;
		find_distance(stack_a, current_node, merge);
		if (merge->up_down_switch == 'u')
		{
			new_move_amount = calculate_amount_of_moves_needed(merge, 3);
			if (new_move_amount < merge->amount_of_moves_needed_stored)
			{
				printf("\nfound better option!\n");
				merge->a_moves = merge->a_distance;
				merge->b_moves = merge->b_distance;
				merge->a_up_or_down = 'u';
				merge->b_up_or_down = 'd';
				merge->amount_of_moves_needed_stored = new_move_amount;
			}
		}
		else if (merge->up_down_switch == 'd')
		{
			new_move_amount = calculate_amount_of_moves_needed(merge, 4);
			printf("\n\nnew_move_amount = %i\nmerge->optimal = %i\na_distance = %i\nb_distance = %i\n", new_move_amount, merge->optimal, merge->a_distance, merge->b_distance);
			if (new_move_amount < merge->amount_of_moves_needed_stored)
			{
				printf("\nfound better option!\n");
				merge->a_moves = merge->a_distance;
				merge->b_moves = merge->b_distance;
				merge->a_up_or_down = 'd';
				merge->b_up_or_down = 'd';
				merge->amount_of_moves_needed_stored = new_move_amount;
			}
		}
		merge->a_distance = 0;
		current_node = current_node->previous;
	}
}

void	search_better_option_top(t_stack **stack_a, t_stack *current_node, t_merge *merge)
{
	int	new_move_amount;

	printf("amount of moves stored = %i\n", merge->amount_of_moves_needed_stored);
	while (merge->b_distance < merge->stored_optimal && current_node->next)
	{
		current_node = current_node->next;
		merge->b_distance++;
		find_distance(stack_a, current_node, merge);
		if (merge->up_down_switch == 'u')
		{
			new_move_amount = calculate_amount_of_moves_needed(merge, 1);
			if (new_move_amount < merge->amount_of_moves_needed_stored)
			{
				printf("\nfound better option!\n");
				merge->a_moves = merge->a_distance;
				merge->b_moves = merge->b_distance;
				merge->a_up_or_down = 'u';
				merge->b_up_or_down = 'u';
				merge->amount_of_moves_needed_stored = new_move_amount;
			}
		}
		else if (merge->up_down_switch == 'd')
		{
			new_move_amount = calculate_amount_of_moves_needed(merge, 2);
			if (new_move_amount < merge->amount_of_moves_needed_stored)
			{
				printf("\nfound better option!\n");
				merge->a_moves = merge->a_distance;
				merge->b_moves = merge->b_distance;
				merge->a_up_or_down = 'd';
				merge->b_up_or_down = 'u';
				merge->amount_of_moves_needed_stored = new_move_amount;
			}
		}
		merge->a_distance = 0;
	}
}

void	find_distance_first_node(t_stack **stack_a, t_stack *current_node, t_merge *merge)
{
	merge->b_up_or_down = 'u';
	merge->b_distance = 0;
	merge->amount_of_moves_needed_stored = merge->stack_a_length;
	find_distance(stack_a, current_node, merge);
	merge->amount_of_moves_needed_stored = merge->a_moves;
	if (merge->amount_of_moves_needed_stored > merge->stack_a_length / 2)
	{
		merge->a_moves = merge->stack_a_length - merge->a_distance;
		merge->amount_of_moves_needed_stored = merge->a_moves;
		merge->a_up_or_down = 'd';
	}
	else
	{
		merge->a_moves = merge->a_distance;
		merge->a_up_or_down = 'u';
	}
	merge->amount_of_moves_needed_stored = merge->a_moves;
	merge->b_moves = merge->b_distance;
	merge->a_distance = 0;
}
