/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 16:20:21 by molariou          #+#    #+#             */
/*   Updated: 2026/05/01 16:20:22 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}

int	ft_putnbr(int n, int count)
{
	if (n == 0)
		return (ft_putchar('0'));
	if (n == -2147483648)
	{
		count += ft_putchar('-');
		count += ft_putstr("2147483648");
		return (count);
	}
	else if (n < 0)
	{
		count += ft_putchar('-');
		count = ft_putnbr(-n, count);
	}
	else if (n > 9)
	{
		count = ft_putnbr(n / 10, count);
		count += ft_putchar((n % 10) + '0');
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_putnbr_pos(unsigned int n, int count)
{
	if (n == 0)
		return (ft_putchar('0'));
	if (n > 9)
	{
		count = ft_putnbr_pos(n / 10, count);
		count += ft_putchar((n % 10) + '0');
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}
