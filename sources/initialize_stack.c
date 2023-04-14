/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:45:21 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/04/14 19:45:52 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create_new_node(int content)
{
	t_stack	*new_node;

	new_node = ft_calloc(1, sizeof(t_stack));
	if (new_node == NULL)
		ft_error_message("failed to alloc for new node");
	new_node->number = content;
	new_node->next = NULL;
	new_node->left_pile_top = NULL;
	new_node->right_pile_top = NULL;
	new_node->part_of_ascending_list = false;
	new_node->part_of_descending_list = false;
	return (new_node);
}

void	initialize_stack(t_stack **stack, int argc, char **arguments)
{
	t_stack	*new_node;
	int		number;
	int		i;

	i = 1;
	while (i < argc)
	{
		number = ft_atoi(arguments[i]);
		new_node = create_new_node(number);
		append_node(stack, new_node);
		i++;
	}
}
