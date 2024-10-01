/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:15:01 by mlarioui          #+#    #+#             */
/*   Updated: 2024/10/01 14:42:28 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		count += putchar(*str);
		str++;
	}
	return (count);
}

int	putnbr(int n, int count)
{
	if (n == -2147483648)
	{
		count = putchar('-');
		count += putstr("2147483648");
		return (count);
	}
	else if (n < 0)
	{
		count = putchar('-');
		n = -n;
		count = putnbr(n, count);
	}
	else if (n > 9)
	{
		count = putnbr(n / 10, count);
		count = putnbr(n % 10, count);
	}
	else
		count += putchar(n + '0');
	return (count);
}

int	putnbr_pos(unsigned int n, int count)
{
	if (n > 9)
	{
		count = putnbr_pos(n / 10, count);
		count = putnbr_pos(n % 10, count);
	}
	else
		count += putchar(n + '0');
	return (count);
}
/*
int putpointer
int puthexadecimal
int checklist */