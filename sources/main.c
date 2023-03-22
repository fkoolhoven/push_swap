/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:29:20 by felicia           #+#    #+#             */
/*   Updated: 2023/03/22 12:31:10 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
	{
		ft_putendl_fd("Error: too few arguments", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	initialize_stack(&stack_a, argc, argv);
	//print_linked_list(stack_a);
	longest_list(&stack_a);
	// swap_a(&stack_a);
	// print_linked_list(stack_a);

	// rotate_a(&stack_a);
	// print_linked_list(stack_a);

	// reverse_rotate_a(&stack_a);
	// print_linked_list(stack_a);

	// push_b(&stack_a, &stack_b);
	// print_linked_list(stack_a);
	// ft_printf("~~~~~~~~~~~~~\n");
	// print_linked_list(stack_b);

	// push_b(&stack_a, &stack_b);
	// print_linked_list(stack_a);
	// ft_printf("~~~~~~~~~~~~~\n");
	// print_linked_list(stack_b);

	// swap_a(&stack_a);
	// print_linked_list(stack_a);
	// ft_printf("~~~~~~~~~~~~~\n");
	// print_linked_list(stack_b);

	// push_b(&stack_a, &stack_b);
	// print_linked_list(stack_a);
	// ft_printf("~~~~~~~~~~~~~\n");
	// print_linked_list(stack_b);

	// swap_ab(&stack_a, &stack_b);
	// print_linked_list(stack_a);
	// ft_printf("~~~~~~~~~~~~~\n");
	// print_linked_list(stack_b);

	// push_a(&stack_b, &stack_a);
	// print_linked_list(stack_a);
	// ft_printf("~~~~~~~~~~~~~\n");
	// print_linked_list(stack_b);

	// rotate_b(&stack_b);
	// print_linked_list(stack_a);
	// ft_printf("~~~~~~~~~~~~~\n");
	// print_linked_list(stack_b);

	// rotate_a(&stack_a);
	// print_linked_list(stack_a);
	// ft_printf("~~~~~~~~~~~~~\n");
	// print_linked_list(stack_b);

	// rotate_ab(&stack_a, &stack_b);
	// print_linked_list(stack_a);
	// ft_printf("~~~~~~~~~~~~~\n");
	// print_linked_list(stack_b);

	// reverse_rotate_ab(&stack_a, &stack_b);
	// print_linked_list(stack_a);
	// ft_printf("~~~~~~~~~~~~~\n");
	// print_linked_list(stack_b);


	return (EXIT_SUCCESS);
}
