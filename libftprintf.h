/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:29:06 by mlarioui          #+#    #+#             */
/*   Updated: 2024/10/01 15:40:24 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_format(va_list args, char *s);
int	putchar(char c);
int	putstr(char *str);
int	putnbr(int n, int count);
int	putnbr_pos(unsigned int n, int count);
int	puthexnbr(size_t arg, int count, char n_type);
#endif