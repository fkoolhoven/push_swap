/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patience.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:50:33 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/22 13:38:24 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_list(t_stack **top)
{
	t_stack	*item;

	item = *top;
	while (item && item->right_pile_top) // move through all the top and find last one
	{
		item = item->right_pile_top;
	}
	while (item) // follow way back to find list
	{
		ft_printf("%i ", item->content);
		item = item->left_pile_top;
	}
	ft_printf("\n");
}


t_stack	*find_pile(t_stack *current_node, t_stack **tops, t_stack **first_top)
{
	int		check_top;
	t_stack	*top;
	t_stack	*stored;

	stored = NULL;
	top = *tops;
	check_top = 0;
	if (current_node == 0)
		return (NULL);
	while (top)
	{
		if (current_node->content < top->content)
		{
			current_node->right_pile_top = top->right_pile_top;
			top = current_node; 
			top->left_pile_top = stored;
			if (top->left_pile_top)
				top->left_pile_top->right_pile_top = top;
			else
				*first_top = top;
			return (top);
		}
		stored = top;
		top = top->right_pile_top;
	}
	return (NULL);
}

void	longest_list(t_stack **stack_a)
{
	t_stack	*top;
	t_stack	*first_top;
	t_stack	*found_pile;
	t_stack	*current_node;

	top = NULL;
	current_node = *stack_a;
	while (current_node)
	{
		found_pile = find_pile(current_node, &top, &first_top);
		if (!found_pile)
		{
			while (top && top->right_pile_top) // move through all the top and find last one
			{
				top = top->right_pile_top;
			}
			if (top)
			{
				top->right_pile_top = current_node; // make last top point to current node as new pile top
				current_node->left_pile_top = top; // make new top point to correct left pile top
			}
			else
			{
				top = current_node;
				first_top = top;
			}
		}
		top = first_top;
		current_node = current_node->next;
	}
	print_list(&top);
}
