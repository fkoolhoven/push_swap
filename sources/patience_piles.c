/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patience_piles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:02:25 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/03/03 22:48:51 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_piles(t_stack *stack_a)
{
	while (stack_a)
	{
		stack_a->left_pile_top = NULL;
		stack_a->right_pile_top = NULL;
		stack_a = stack_a->next;
	}
}

void	create_new_pile(t_stack *current_node,
	t_stack *pile_top, t_stack **first_top)
{
	while (pile_top && pile_top->right_pile_top)
		pile_top = pile_top->right_pile_top;
	if (!pile_top)
	{
		pile_top = current_node;
		*first_top = pile_top;
	}
	else
	{
		pile_top->right_pile_top = current_node;
		current_node->left_pile_top = pile_top;
	}
}

static void	put_current_node_on_pile(t_stack *current_node, t_stack *pile_top,
	t_stack *stored, t_stack **first_top)
{
	current_node->right_pile_top = pile_top->right_pile_top;
	pile_top = current_node;
	pile_top->left_pile_top = stored;
	if (!pile_top->left_pile_top)
		*first_top = pile_top;
	else
		pile_top->left_pile_top->right_pile_top = pile_top;
}

bool	find_pile(t_stack *current_node, t_stack *pile_top,
	t_stack **first_top, int asc_or_desc)
{
	t_stack	*stored;

	stored = NULL;
	while (pile_top)
	{
		if ((current_node->number < pile_top->number && asc_or_desc == ASCENDING)
			|| (current_node->number > pile_top->number && asc_or_desc == DESCENDING))
		{
			put_current_node_on_pile(current_node, pile_top, stored, first_top);
			return (true);
		}
		stored = pile_top;
		pile_top = pile_top->right_pile_top;
	}
	return (false);
}
