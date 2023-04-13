/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:29:20 by felicia           #+#    #+#             */
/*   Updated: 2023/04/13 16:33:31 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reset_piles(t_stack **stack_a) // move to different file? // delete? maybe not needed
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
		if (check->number > check->next->number || check->number > top_of_a || check->next->number > top_of_a)
			return (false);
		check = check->next;
	}
	return (true);
}

bool	check_for_duplicate_numbers(int argc, char **argv, int i)
{
	int	j;

	j = i + 1;
	while (j < argc && argv[j])
	{
		if (ft_strncmp(argv[i], argv[j], 11) == 0)
			return (false);
		j++;
	}
	return (true);
}

bool	check_for_non_integers(char **argv, int i)
{
	int	j;

	j = 0;
	if (argv[i][j] == '-')
		j++;
	if (ft_isdigit(argv[i][j]) == 0)
		return (false);
	while (argv[i][j])
	{
		if (ft_isdigit(argv[i][j]) == 0)
			return (false);
		j++;
	}
	i++;
	j = 0;
	return (true);
}

void	validate_input(int argc, char **argv)
{
	int			i;
	long long	number;

	if (argc <= 1)
		ft_error_message("too few arguments");
	i = 1;
	while (i < argc)
	{
		if (!check_for_non_integers(argv, i))
			ft_error_message("arguments should only be integers");
		if (!check_for_duplicate_numbers(argc, argv, i))
			ft_error_message("duplicte numbers not allowed");
		number = ft_atol(argv[i]);
		if (number < INT_MIN)
			ft_error_message("argument(s) smaller than INT_MAX");
		if (number > INT_MAX)
			ft_error_message("argument(s) bigger than INT_MAX");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	validate_input(argc, argv);
	if (argc == 2)
		return (EXIT_SUCCESS);
	initialize_stack(&stack_a, argc, argv);
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
	// printf("\nAT END\n");
	// print_linked_list(stack_a);
	// ft_printf("~~~~~~~~~~~~~\n");
	// print_linked_list(stack_b);
	return (EXIT_SUCCESS);
}
