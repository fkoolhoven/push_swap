/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:30:07 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/04/20 14:41:57 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	check_for_duplicate_numbers(int argc, char **args, int i)
{
	int	j;

	j = i + 1;
	while (j < argc && args[j])
	{
		if (ft_strncmp(args[i], args[j], 11) == 0)
			return (false);
		j++;
	}
	return (true);
}

static bool	check_for_non_integers(char **args, int i)
{
	int	j;

	j = 0;
	if (args[i][j] == '-')
		j++;
	if (ft_isdigit(args[i][j]) == 0)
		return (false);
	while (args[i][j])
	{
		if (ft_isdigit(args[i][j]) == 0)
			return (false);
		j++;
	}
	i++;
	j = 0;
	return (true);
}

void	validate_input(int argc, char **args)
{
	int			i;
	long long	number;

	if (argc <= 1)
		exit (EXIT_SUCCESS);
	i = 1;
	while (i < argc)
	{
		if (!check_for_non_integers(args, i))
			ft_error_message("arguments should only be integers");
		if (!check_for_duplicate_numbers(argc, args, i))
			ft_error_message("duplicte numbers not allowed");
		number = ft_atol(args[i]);
		if (number < INT_MIN)
			ft_error_message("argument(s) smaller than INT_MIN");
		if (number > INT_MAX)
			ft_error_message("argument(s) bigger than INT_MAX");
		i++;
	}
}
