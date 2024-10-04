/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:27:05 by mlarioui          #+#    #+#             */
/*   Updated: 2024/10/04 22:06:19 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_format(va_list args, const char *s)
{
    int count;

    count = 0;
    if (*s == 'c')
        count += ft_putchar(va_arg(args, int));
    else if (*s == 's')
        count += ft_putstr(va_arg(args, char *));
    else if (*s == 'd' || *s == 'i')
        count += ft_putnbr(va_arg(args, int), 0); // Added second argument
    else if (*s == 'u')
        count += ft_putnbr_pos(va_arg(args, unsigned int), 0); // Added second argument
    else if (*s == 'x')
        count += puthexnbr(va_arg(args, unsigned int), 0, 'x'); // Added third argument
    else if (*s == 'X')
        count += puthexnbr(va_arg(args, unsigned int), 1, 'X'); // Added third argument
    else if (*s == 'p')
    {
        count += ft_putstr("0x");
        count += puthexnbr(va_arg(args, size_t), 0, 'x'); // Added third argument
    }
    else if (*s == '%')
        count += ft_putchar('%');
    return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, str); 
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i +1])
		{
			i++;
			count += ft_format(args, &str[i]);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
