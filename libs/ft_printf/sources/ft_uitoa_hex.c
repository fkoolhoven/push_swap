/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:56:56 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/20 14:00:15 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*convert(int size, unsigned int n, char *s, char x_X)
{
	int	storage;

	while (size > 0 && n != 0)
	{
		size--;
		storage = 48 + (n % 16);
		if (storage >= 10 + 48)
		{
			if (x_X == 'X')
				storage += 7;
			else if (x_X == 'x')
				storage += 39;
		}	
		s[size] = storage;
		n = n / 16;
	}
	return (s);
}

static size_t	calc_size(unsigned int n)
{
	size_t	size;

	size = 0;
	while (n != 0)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

char	*uitoa_hex(unsigned int n, char x_X)
{
	char	*s;
	size_t	size;

	size = calc_size(n);
	if (n == 0)
		size++;
	s = malloc(sizeof(char) * size + 1);
	if (s == NULL)
		return (NULL);
	s[size] = '\0';
	if (n == 0)
	{
		s[0] = '0';
		return (s);
	}	
	s = convert(size, n, s, x_X);
	return (s);
}
