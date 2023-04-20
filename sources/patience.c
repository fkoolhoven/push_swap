/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patience.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:50:33 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/04/20 14:20:17 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	tag_nodes_as_part_of_list(t_stack **top, char asc_or_desc)
{
	t_stack	*current_node;

	current_node = *top;
	while (current_node && current_node->right_pile_top)
		current_node = current_node->right_pile_top;
	while (current_node)
	{
		if (asc_or_desc == "ascending"[0])
			current_node->part_of_ascending_list = true;
		else if (asc_or_desc == "descending"[0])
			current_node->part_of_descending_list = true;
		if (!current_node->left_pile_top)
			break ;
		current_node = current_node->left_pile_top;
	}
}

static void	find_longest_list(t_stack *stack_a, char asc_or_desc)
{
	t_stack	*current_node;
	t_stack	*pile_top;
	t_stack	*first_top;
	bool	pile;

	pile_top = NULL;
	current_node = stack_a;
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

void	perform_patience(t_stack *stack_a)
{
	find_longest_list(stack_a, "ascending"[0]);
	reset_piles(stack_a);
	find_longest_list(stack_a, "descending"[0]);
}
