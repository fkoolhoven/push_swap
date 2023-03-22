/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patience.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:50:33 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/22 15:19:22 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	tag_nodes_as_part_of_list(t_stack **top)
{
	t_stack	*item;

	item = *top;
	while (item && item->right_pile_top) // move through all the top and find last one
	{
		item = item->right_pile_top;
	}
	while (item) // follow way back to find list
	{
		item->part_of_list = true;
		ft_printf("%i ", item->number);
		item = item->left_pile_top;
	}
	ft_printf("\n");
}

void	create_new_pile(t_stack *current_node, t_stack *pile_top, t_stack **first_top)
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

void	put_current_node_on_pile(t_stack *current_node, t_stack *pile_top, t_stack *stored, t_stack **first_top)
{
	current_node->right_pile_top = pile_top->right_pile_top;
	pile_top = current_node; 
	pile_top->left_pile_top = stored;
	if (pile_top->left_pile_top)
		pile_top->left_pile_top->right_pile_top = pile_top;
	else
		*first_top = pile_top;
}

bool	find_pile(t_stack *current_node, t_stack *pile_top, t_stack **first_top)
{
	t_stack	*stored;

	stored = NULL;
	if (current_node == 0)
		return (NULL);
	while (pile_top)
	{
		if (current_node->number < pile_top->number)
		{
			put_current_node_on_pile(current_node, pile_top, stored, first_top);
			return (true);
		}
		stored = pile_top;
		pile_top = pile_top->right_pile_top;
	}
	return (false);
}

void	find_longest_list(t_stack **stack_a)
{
	t_stack	*current_node;
	t_stack	*pile_top;
	t_stack	*first_top;
	bool	found_pile;

	pile_top = NULL;
	current_node = *stack_a;
	while (current_node)
	{
		found_pile = find_pile(current_node, pile_top, &first_top);
		if (!found_pile)
			create_new_pile(current_node, pile_top, &first_top);
		pile_top = first_top;
		current_node = current_node->next;
	}
	tag_nodes_as_part_of_list(&pile_top);
}
