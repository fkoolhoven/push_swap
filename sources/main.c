/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:29:20 by felicia           #+#    #+#             */
/*   Updated: 2023/04/14 19:46:09 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reset_piles(t_stack **stack_a) // move to different file?
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

bool	stack_a_already_sorted(t_stack **stack_a)
{
	t_stack	*check;
	int		top_of_a;

	check = *stack_a;
	top_of_a = check->number;
	while (check->next != NULL)
	{
		if (check->number > check->next->number)
			break ;
		check = check->next;
	}
	if (check->next == NULL)
		return (true);
	check = check->next;
	if (check->number > top_of_a)
		return (false);
	while (check->next != NULL)
	{
		if (check->number > check->next->number
			|| check->number > top_of_a
			|| check->next->number > top_of_a)
			return (false);
		check = check->next;
	}
	return (true);
}

char	**split_arguments(int *argc, char **argv)
{
	char	**old_argv;
	char	**arguments;
	int		i;
	int		j;

	old_argv = ft_split(argv[1], ' ');
	j = 0;
	i = 0;
	while (old_argv[i])
		i++;
	arguments = ft_calloc(i + 1, sizeof(char *));
	if (arguments == NULL)
		ft_error_message("failed to alloc for arguments");
	arguments[j] = ft_calloc(12, sizeof(char));
	if (arguments[j] == NULL)
		ft_error_message("failed to alloc for arguments");
	arguments[j] = "./push_swap";
	j++;
	i = 0;
	while (old_argv[i])
	{
		arguments[j] = old_argv[i];
		j++;
		i++;
	}
	*argc = j;
	// free old argv that has memory allocated from splitting
	return (arguments);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**arguments;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
		arguments = split_arguments(&argc, argv);
	else
		arguments = argv;
	validate_input(argc, arguments);
	if (argc == 2)
		return (EXIT_SUCCESS);
	initialize_stack(&stack_a, argc, arguments);
	if (stack_a_already_sorted(&stack_a))
	{
		final_rotate(&stack_a);
		// printf("\nALREADY SORTED BEFORE PATIENCE\n");
		// print_linked_list(stack_a);
		// ft_printf("~~~~~~~~~~~~~\n");
		// print_linked_list(stack_b);
		return (EXIT_SUCCESS);
	}
	if (argc == 4)
	{
		swap_a(&stack_a);
		final_rotate(&stack_a);
		// printf("\nLIST OF THREE\n");
		// print_linked_list(stack_a);
		// ft_printf("~~~~~~~~~~~~~\n");
		// print_linked_list(stack_b);
		return (EXIT_SUCCESS);
	}
	find_longest_list(&stack_a, 'a');
	reset_piles(&stack_a);
	find_longest_list(&stack_a, 'd');
	seperate_lists(&stack_a, &stack_b);
	// printf("\nBEFORE MERGING\n");
	// print_linked_list(stack_a);
	// ft_printf("~~~~~~~~~~~~~\n");
	// print_linked_list(stack_b);
	merge_stacks(&stack_a, &stack_b);
	final_rotate(&stack_a);
	printf("\nAT END\n");
	print_linked_list(stack_a);
	ft_printf("~~~~~~~~~~~~~\n");
	print_linked_list(stack_b);
	// free struct and arguments
	return (EXIT_SUCCESS);
}
