/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:30:07 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/04/16 17:46:53 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
