/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_patterns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:56:39 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/29 12:17:24 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	merge_rra_rrb(t_stack **stack_a, t_stack **stack_b, t_merge *merge)
{
	while (merge->a_moves > 0 && merge->b_moves > 0)
	{
		reverse_rotate_ab(stack_a, stack_b);
		merge->a_moves--;
		merge->b_moves--;
	}
	while (merge->a_moves > 0)
	{
		reverse_rotate_a(stack_a);
		merge->a_moves--;
	}
	while (merge->b_moves > 0)
	{
		reverse_rotate_b(stack_b);
		merge->b_moves--;
	}
}

void	merge_rra_rb(t_stack **stack_a, t_stack **stack_b, t_merge *merge)
{
	while (merge->a_moves > 0)
	{
		reverse_rotate_a(stack_a);
		merge->a_moves--;
	}
	while (merge->b_moves > 0)
	{
		rotate_b(stack_b);
		merge->b_moves--;
	}
}

void	merge_ra_rrb(t_stack **stack_a, t_stack **stack_b, t_merge *merge)
{
	while (merge->a_moves > 0)
	{
		rotate_a(stack_a);
		merge->a_moves--;
	}
	while (merge->b_moves > 0)
	{
		reverse_rotate_b(stack_b);
		merge->b_moves--;
	}
}

void	merge_ra_rb(t_stack **stack_a, t_stack **stack_b, t_merge *merge)
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
	while (merge->b_moves > 0)
	{
		rotate_b(stack_b);
		merge->b_moves--;
	}
}
