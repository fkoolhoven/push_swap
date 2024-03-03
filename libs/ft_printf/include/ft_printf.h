/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:08:43 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/03/20 13:51:23 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "../../libft/libft.h"

int		ft_printf(const char *str, ...);
int		putchar_printf(char c);
int		putstr_printf(char *s);
int		putstr_free_printf(char *s);
int		putptr(void *ptr);
char	*uitoa(unsigned int n);
char	*uitoa_hex(unsigned int n, char x_X);

#endif