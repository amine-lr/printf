/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:51:17 by mlarioui          #+#    #+#             */
/*   Updated: 2024/10/01 15:48:50 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_format(va_list args, char *s)
{
	int	count;

	count = 0;
	if (*s == 'c')
		count += putchar(va_arg(args, int));
	else if (*s == 's')
		count += putstr(va_arg(args, char *));
	else if (*s == 'd' || *s == 'i')
		count += putnbr(va_arg(args, int));
	else if (*s == 'u')
		count += putnbr_pos(va_arg(args, unsigned int));
	else if (*s == 'x')
		count += puthexnbr(va_arg(args, unsigned int), 0);
	else if (*s == 'X')
		count += puthexnbr(va_arg(args, unsigned int), 1);
	else if (*s == 'p')
	{
		count += putstr("0x");
		count += puthexnbr(va_arg(args, size_t), 0, 'x');
	}
	else if (*s == '%')
		count += putchar('%');
	return (count);
}
