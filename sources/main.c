/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:29:20 by felicia           #+#    #+#             */
/*   Updated: 2023/03/06 15:05:39 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*initialize_list(int argc, char **argv)
{
	t_list	*new_node;
	t_list	*stack;
	int		i;

	
	i = 1;
	while (i < argc - 1)
	{
		new_node = ft_lstnew(argv[i]);
		if (!stack)
			stack = new_node;
		else
			ft_lstadd_back(&stack, new_node);
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_list	*list;
	if (argc <= 1)
	{
		ft_putendl_fd("Error: too few arguments", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	list = initialize_list(argc, argv);
	// initialize list a
	// store int values in list
	// initliaze list b
	// print list a
	// print list b
	// code various actions
}