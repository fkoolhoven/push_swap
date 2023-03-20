/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:29:20 by felicia           #+#    #+#             */
/*   Updated: 2023/03/20 16:48:29 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc <= 1)
	{
		ft_putendl_fd("Error: too few arguments", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	stack = initialize_stack(argc, argv);
	print_linked_list(stack);
	swap_a(&stack);
	print_linked_list(stack);
	rotate_a(&stack);
	print_linked_list(stack);
	// initialize list a
	// store int values in list
	// initliaze list b
	// print list a
	// print list b
	// code various actions
	// modify atoi
}
