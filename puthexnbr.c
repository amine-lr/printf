/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthexnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:37:38 by mlarioui          #+#    #+#             */
/*   Updated: 2024/10/04 22:07:41 by mlarioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	puthexnbr(size_t arg, int count, char n_type)
{
	char	*hex_digits;

	if (n_type == 'X')
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	if (arg >= 16)
	{
		count = puthexnbr(arg / 16, count, n_type);
		count = puthexnbr(arg % 16, count, n_type);
	}
	else
		count += ft_putchar(hex_digits[arg]);
	return (count);
}
