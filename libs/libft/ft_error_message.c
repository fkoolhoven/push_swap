/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:34:13 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/04/13 16:34:26 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error_message(char *message)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	exit (EXIT_FAILURE);
}
