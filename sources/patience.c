/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patience_ascending.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:50:33 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/27 18:13:22 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*tag_nodes_as_part_of_list(t_stack **top, char asc_or_desc)
{
	t_stack	*item;

	item = *top;
	while (item && item->right_pile_top)
	{
		item = item->right_pile_top;
	}
	while (item)
	{
		if (asc_or_desc == 'a')
			item->part_of_ascending_list = true;
		else if (asc_or_desc == 'd')
			item->part_of_descending_list = true;
		if (!item->left_pile_top)
			return (item);
		item = item->left_pile_top;
	}
	return (NULL);
}

static void	create_new_pile(t_stack *current_node, t_stack *pile_top, t_stack **first_top)
{
	while (pile_top && pile_top->right_pile_top)
		pile_top = pile_top->right_pile_top;
	if (pile_top)
	{
		pile_top->right_pile_top = current_node;
		current_node->left_pile_top = pile_top;
	}
	else
	{
		pile_top = current_node;
		*first_top = pile_top;
	}
}

static void	put_current_node_on_pile(t_stack *current_node, t_stack *pile_top, t_stack *stored, t_stack **first_top)
{
	current_node->right_pile_top = pile_top->right_pile_top;
	pile_top = current_node; 
	pile_top->left_pile_top = stored;
	if (pile_top->left_pile_top)
		pile_top->left_pile_top->right_pile_top = pile_top;
	else
		*first_top = pile_top;
}

static bool	find_pile(t_stack *current_node, t_stack *pile_top, t_stack **first_top, char asc_or_desc)
{
	t_stack	*stored;

	stored = NULL;
	if (current_node == 0)
		return (NULL);
	while (pile_top)
	{
		if (current_node->number < pile_top->number && asc_or_desc == 'a')
		{
			put_current_node_on_pile(current_node, pile_top, stored, first_top);
			return (true);
		}
		else if (current_node->number > pile_top->number && asc_or_desc == 'd')
		{
			put_current_node_on_pile(current_node, pile_top, stored, first_top);
			return (true);
		}
		stored = pile_top;
		pile_top = pile_top->right_pile_top;
	}
	return (false);
}

t_stack	*find_longest_ascending_list(t_stack **stack_a)
{
	t_stack	*current_node;
	t_stack	*pile_top;
	t_stack	*first_top;
	t_stack	*list_start;
	bool	found_pile;

	pile_top = NULL;
	current_node = *stack_a;
	while (current_node)
	{
		found_pile = find_pile(current_node, pile_top, &first_top, 'a');
		if (!found_pile)
			create_new_pile(current_node, pile_top, &first_top);
		pile_top = first_top;
		current_node = current_node->next;
	}
	list_start = tag_nodes_as_part_of_list(&pile_top, 'a');
	return (list_start);
}

t_stack	*find_longest_descending_list(t_stack **stack_a)
{
	t_stack	*current_node;
	t_stack	*pile_top;
	t_stack	*first_top;
	t_stack	*list_start;
	bool	found_pile;

	pile_top = NULL;
	current_node = *stack_a;
	while (current_node)
	{
		if (!current_node->part_of_ascending_list)
		{
			found_pile = find_pile(current_node, pile_top, &first_top, 'd');
			if (!found_pile)
				create_new_pile(current_node, pile_top, &first_top);
			pile_top = first_top;
		}
		current_node = current_node->next;
	}
	list_start = tag_nodes_as_part_of_list(&pile_top, 'd');
	return (list_start);
}
