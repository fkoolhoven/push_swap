/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:45:21 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/03/03 22:46:19 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_new_node(int number)
{
	t_stack	*new_node;

	new_node = ft_calloc(1, sizeof(t_stack));
	if (new_node == NULL)
		ft_error_message("failed to allocate memory for new node");
	new_node->number = number;
	return (new_node);
}

void	initialize_stack(t_stack **stack, int argc, char **args,
	bool args_allocated)
{
	t_stack	*new_node;
	int		number;
	int		i;

	i = 1;
	while (i < argc)
	{
		number = ft_atoi(args[i]);
		new_node = create_new_node(number);
		append_node(stack, new_node);
		if (args_allocated)
			free (args[i]);
		i++;
	}
	if (args_allocated)
		free (args);
}
