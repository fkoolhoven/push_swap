/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patience_piles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:50:33 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/29 15:32:44 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*tag_nodes_as_part_of_list(t_stack **top, char asc_or_desc)
{
	t_stack	*current_node;

	current_node = *top;
	while (current_node && current_node->right_pile_top)
		current_node = current_node->right_pile_top;
	while (current_node)
	{
		if (asc_or_desc == 'a')
			current_node->part_of_ascending_list = true;
		else if (asc_or_desc == 'd')
			current_node->part_of_descending_list = true;
		if (!current_node->left_pile_top)
			return (current_node);
		current_node = current_node->left_pile_top;
	}
	return (NULL);
}

static void	create_new_pile(t_stack *current_node,
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

static bool	find_pile(t_stack *current_node, t_stack *pile_top,
	t_stack **first_top, char asc_or_desc)
{
	t_stack	*stored;

	stored = NULL;
	while (pile_top)
	{
		if ((current_node->number < pile_top->number && asc_or_desc == 'a')
			|| (current_node->number > pile_top->number && asc_or_desc == 'd'))
		{
			put_current_node_on_pile(current_node, pile_top, stored, first_top);
			return (true);
		}
		stored = pile_top;
		pile_top = pile_top->right_pile_top;
	}
	return (false);
}

void	find_longest_list(t_stack **stack_a, char asc_or_desc)
{
	t_stack	*current_node;
	t_stack	*pile_top;
	t_stack	*first_top;
	bool	pile;

	pile_top = NULL;
	current_node = *stack_a;
	while (current_node)
	{
		if (!current_node->part_of_ascending_list)
		{
			pile = find_pile(current_node, pile_top, &first_top, asc_or_desc);
			if (!pile)
				create_new_pile(current_node, pile_top, &first_top);
			pile_top = first_top;
		}
		current_node = current_node->next;
	}
	tag_nodes_as_part_of_list(&pile_top, asc_or_desc);
}