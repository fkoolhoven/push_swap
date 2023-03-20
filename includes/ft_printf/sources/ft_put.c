/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:42:46 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/20 14:00:11 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putptr_conversion(unsigned long ptr_as_int)
{
	int	bytes;

	bytes = 0;
	if (ptr_as_int >= 16)
		bytes += putptr_conversion(ptr_as_int / 16);
	bytes += putchar_printf("0123456789abcdef"[ptr_as_int % 16]);
	return (bytes);
}

int	putptr(void *ptr)
{
	unsigned long	ptr_as_int;
	int				bytes;

	ptr_as_int = (unsigned long)ptr;
	bytes = putstr_printf("0x") + putptr_conversion(ptr_as_int);
	return (bytes);
}

int	putstr_free_printf(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	free (s);
	return (i);
}

int	putstr_printf(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		s = "(null)";
		return (putstr_printf(s));
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	putchar_printf(char c)
{
	write(1, &c, 1);
	return (1);
}
