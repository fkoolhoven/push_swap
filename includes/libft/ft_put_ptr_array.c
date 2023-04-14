/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:47:42 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/04/14 18:09:41 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_ptr_array_fd(char **two_d_array, int fd)
{
	int	i;

	i = 0;
	while (two_d_array[i])
	{
		ft_putendl_fd(two_d_array[i], fd);
		i++;
	}
}
