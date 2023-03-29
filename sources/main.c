/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:29:20 by felicia           #+#    #+#             */
/*   Updated: 2023/03/29 12:28:42 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


// void	validate_input()
// {
// 	check for
// 	- at least 2 args
// 	- args aren't integers
// 	- there are duplicates
// 	- args are bigger than an int
// 	In case of error, it must display "Error" followed by a ’\n’ on the standard error.
// 	Errors include for example: some arguments aren’t integers, some arguments are
// 	bigger than an integer and/or there are duplicates.
// }

void	reset_piles(t_stack **stack_a)
{
	t_stack	*current_node;

	current_node = *stack_a;
	while (current_node)
	{
		current_node->left_pile_top = NULL;
		current_node->right_pile_top = NULL;
		current_node = current_node->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*ascending_list_start;
	t_stack *descending_list_start;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
	{
		ft_putendl_fd("Error: too few arguments", STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	initialize_stack(&stack_a, argc, argv);
	ascending_list_start = find_longest_list(&stack_a, 'a');
	reset_piles(&stack_a);
	descending_list_start = find_longest_list(&stack_a, 'd');
	seperate_lists(&stack_a, &stack_b, ascending_list_start);
	// printf("\nBEFORE MERGING\n");
	// print_linked_list(stack_a);
	// ft_printf("~~~~~~~~~~~~~\n");
	// print_linked_list(stack_b);
	merge_stacks(&stack_a, &stack_b);
	final_rotate(&stack_a);
	//merge_sorted_parts(&stack_a, &stack_b, descending_list_start, ascending_list_start);
	// printf("\nAT END\n");
	// print_linked_list(stack_a);
	// ft_printf("~~~~~~~~~~~~~\n");
	// print_linked_list(stack_b);

	return (EXIT_SUCCESS);
}
