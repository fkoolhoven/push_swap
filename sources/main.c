/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:29:20 by felicia           #+#    #+#             */
/*   Updated: 2023/04/18 17:25:31 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	print_linked_list(t_stack *stack)
// {
// 	int	i;

// 	i = 0;
// 	while (stack)
// 	{
// 		ft_printf("number at index %i =", i);
// 		ft_printf(" %i\n", stack->number);
// 		stack = stack->next;
// 		i++;
// 	}
// }



static bool	no_algorithm_needed(int argc, t_stack *stack_a)
{
	if (argc == 2)
	{
		free (stack_a);
		return (true);
	}
	else if (stack_a_already_sorted(stack_a))
	{
		final_rotate(stack_a);
		return (true);
	}
	else if (argc == 4)
	{
		swap_a(&stack_a);
		final_rotate(stack_a);
		return (true);
	}
	return (false);
}

static char	**split_arguments(int *argc, char **argv)
{
	char	**old_argv;
	char	**arguments;
	int		i;
	int		j;

	old_argv = ft_split(argv[1], ' ');
	i = 0;
	while (old_argv[i])
		i++;
	arguments = ft_calloc(i + 1, sizeof(char *));
	if (arguments == NULL)
		ft_error_message("failed to allocate memory for arguments");
	j = 1;
	i = 0;
	while (old_argv[i])
	{
		arguments[j] = old_argv[i];
		j++;
		i++;
	}
	*argc = j;
	free (old_argv);
	return (arguments);
}

static bool	get_arguments(int *argc, char **argv, char ***arguments)
{
	if (*argc == 2)
	{
		*arguments = split_arguments(argc, argv);
		return (true);
	}
	else
	{
		*arguments = argv;
		return (false);
	}
}
// void	check_leaks(void)
// {
// 	system("leaks -q push_swap");
// }

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**arguments;
	bool	arguments_allocated;

	//atexit(check_leaks);
	arguments_allocated = get_arguments(&argc, argv, &arguments);
	validate_input(argc, arguments);
	initialize_stack(&stack_a, argc, arguments, arguments_allocated);
	if (no_algorithm_needed(argc, stack_a))
		return (EXIT_SUCCESS);
	find_longest_list(&stack_a, 'a');
	find_longest_list(&stack_a, 'd');
	seperate_lists(&stack_a, &stack_b);
	merge_stacks(&stack_a, &stack_b);
	final_rotate(stack_a);
	return (EXIT_SUCCESS);
}
