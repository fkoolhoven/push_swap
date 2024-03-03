/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:29:20 by felicia           #+#    #+#             */
/*   Updated: 2024/03/03 22:46:23 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	bool	args_allocated;

	stack_a = NULL;
	stack_b = NULL;
	args_allocated = get_arguments(&argc, argv, &args);
	validate_input(argc, args);
	initialize_stack(&stack_a, argc, args, args_allocated);
	if (no_algorithm_needed(argc, stack_a))
		return (EXIT_SUCCESS);
	else
	{
		perform_patience(stack_a);
		seperate_stacks(&stack_a, &stack_b);
		perform_merge(&stack_a, &stack_b);
		final_rotate(stack_a);
	}
	return (EXIT_SUCCESS);
}
