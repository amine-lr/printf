/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:27:05 by mlarioui          #+#    #+#             */
/*   Updated: 2024/10/01 15:50:19 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		count;
	int		i;

	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i +1])
		{
			i++;
			count += ft_format(args, str[i]);
		}
		else
			count += putchar(str[i]);
		i++;
		va_end(args);
		return (count);
	}
}
