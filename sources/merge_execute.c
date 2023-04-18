/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:56:39 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/04/18 16:24:01 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	merge_rra_rrb(t_stack **stack_a, t_stack **stack_b, t_merge *merge)
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

static void	merge_rra_rb(t_stack **stack_a, t_stack **stack_b, t_merge *merge)
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

static void	merge_ra_rrb(t_stack **stack_a, t_stack **stack_b, t_merge *merge)
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

static void	merge_ra_rb(t_stack **stack_a, t_stack **stack_b, t_merge *merge)
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

void	execute_merge(t_stack **stack_a, t_stack **stack_b, t_merge *merge)
{
	if (merge->a_up_or_down == 'u' && merge->b_up_or_down == 'u')
		merge_ra_rb(stack_a, stack_b, merge);
	else if (merge->a_up_or_down == 'u' && merge->b_up_or_down == 'd')
		merge_ra_rrb(stack_a, stack_b, merge);
	else if (merge->a_up_or_down == 'd' && merge->b_up_or_down == 'u')
		merge_rra_rb(stack_a, stack_b, merge);
	else if (merge->a_up_or_down == 'd' && merge->b_up_or_down == 'd')
		merge_rra_rrb(stack_a, stack_b, merge);
	push_a(stack_b, stack_a);
	merge->stack_a_length++;
}
