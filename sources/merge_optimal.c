/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_optimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:06:47 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/31 17:05:12 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	calculate_amount_of_moves_needed(t_merge *merge, int merge_pattern)
{
	int	amount_of_moves_needed;

	amount_of_moves_needed = 0;
	if (merge_pattern == 2 || merge_pattern == 4)
	{
		if (merge->a_distance == merge->b_distance)
			amount_of_moves_needed = merge->a_distance;
		else if (merge->a_distance > merge->b_distance)
			amount_of_moves_needed = merge->a_distance;
		else if (merge->b_distance > merge->a_distance)
			amount_of_moves_needed = merge->b_distance;
	}
	else if (merge_pattern == 1 || merge_pattern == 3)
		amount_of_moves_needed = merge->a_distance + merge->b_distance;
	return (amount_of_moves_needed);
}

void	check_if_optimal(t_merge *merge, char a_direction, char b_direction)
{
	int	new_move_amount;

	new_move_amount = 0;
	if (a_direction == 'u' && b_direction == 'd')
		new_move_amount = calculate_amount_of_moves_needed(merge, 1);
	else if (a_direction == 'd' && b_direction == 'd')
		new_move_amount = calculate_amount_of_moves_needed(merge, 2);
	else if (a_direction == 'd' && b_direction == 'u')
		new_move_amount = calculate_amount_of_moves_needed(merge, 3);
	else if (a_direction == 'u' && b_direction == 'u')
		new_move_amount = calculate_amount_of_moves_needed(merge, 4);
	if (new_move_amount < merge->move_amount_optimal)
	{
		merge->a_up_or_down = a_direction;
		merge->b_up_or_down = b_direction;
		merge->a_moves = merge->a_distance;
		merge->b_moves = merge->b_distance;
		merge->move_amount_optimal = new_move_amount;
	}
}
