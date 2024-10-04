/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:15:01 by mlarioui          #+#    #+#             */
/*   Updated: 2024/10/04 22:07:50 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
	if (n == -2147483648)
	{
		count = ft_putchar('-');
		count += ft_putstr("2147483648");
		return (count);
	}
	else if (n < 0)
	{
		count = ft_putchar('-');
		n = -n;
		count = ft_putnbr(n, count);
	}
	else if (n > 9)
	{
		count = ft_putnbr(n / 10, count);
		count = ft_putnbr(n % 10, count);
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}

int	ft_putnbr_pos(unsigned int n, int count)
{
	if (n > 9)
	{
		count = ft_putnbr_pos(n / 10, count);
		count = ft_putnbr_pos(n % 10, count);
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}
/*
int putpointer
int puthexadecimal
int checklist */