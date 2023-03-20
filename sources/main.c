/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:29:20 by felicia           #+#    #+#             */
/*   Updated: 2023/03/20 19:54:57 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	// stack_a->previous = NULL;
	// stack_a->next = NULL;
	// stack_b->previous = NULL;
	// stack_b->next = NULL;


	if (argc <= 1)
	{
		ft_putendl_fd("Error: too few arguments", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	stack_a = initialize_stack(argc, argv);
	print_linked_list(stack_a);
	swap_a(&stack_a);
	print_linked_list(stack_a);
	rotate_a(&stack_a);
	print_linked_list(stack_a);
	reverse_rotate_a(&stack_a);
	print_linked_list(stack_a);
	push_b(&stack_a, &stack_b);
	print_linked_list(stack_a);
	ft_printf("-------------\n");
	print_linked_list(stack_b);
	// initialize list a
	// store int values in list
	// initliaze list b
	// print list a
	// print list b
	// code various actions
	// modify atoi
}