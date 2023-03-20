/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:03:20 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/20 14:00:20 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*convert(int size, unsigned int n, char *s)
{
	while (size > 0 && n != 0)
	{
		size--;
		s[size] = 48 + (n % 10);
		n = n / 10;
	}
	return (s);
}

static size_t	calc_size(unsigned int n)
{
	size_t	size;

	size = 0;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*uitoa(unsigned int n)
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
	s = convert(size, n, s);
	return (s);
}
