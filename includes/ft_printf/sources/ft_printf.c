/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:58:39 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/20 14:00:04 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion(const char *str, va_list list)
{
	int	bytes;

	bytes = 0;
	if (*str == 'c')
		bytes = putchar_printf(va_arg(list, int));
	else if (*str == 's')
		bytes = putstr_printf(va_arg(list, char *));
	else if (*str == 'p')
		bytes = putptr(va_arg(list, void *));
	else if (*str == 'i' || *str == 'd')
		bytes = putstr_free_printf(ft_itoa(va_arg(list, int)));
	else if (*str == 'u')
		bytes = putstr_free_printf(uitoa(va_arg(list, unsigned int)));
	else if (*str == 'x' || *str == 'X')
		bytes = putstr_free_printf(uitoa_hex(va_arg(list, unsigned int), *str));
	else if (*str == '%')
		bytes = putchar_printf('%');
	return (bytes);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		return_value;

	va_start(list, str);
	return_value = 0;
	while (*str != '\0')
	{
		while (*str == '%')
		{
			str++;
			if (*str != 'c' && *str != 's' && *str != 'p'
				&& *str != 'i' && *str != 'd' && *str != 'u'
				&& *str != 'x' && *str != 'X' && *str != '%')
				break ;
			return_value += conversion(str, list);
			str++;
		}
		if (*str == '\0')
			break ;
		putchar_printf(*str);
		return_value++;
		str++;
	}
	va_end(list);
	return (return_value);
}
