/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:26:53 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/29 13:28:48 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	handle_errors(char *message)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	exit (EXIT_FAILURE);
}
