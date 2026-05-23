/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthexnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molariou <molariou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 16:20:27 by molariou          #+#    #+#             */
/*   Updated: 2026/05/01 16:20:28 by molariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthexnbr(size_t arg, int count, char n_type)
{
	if (arg >= 16)
	{
		count = puthexnbr(arg / 16, count, n_type);
	}
	if (n_type == 'x')
		count += ft_putchar("0123456789abcdef"[arg % 16]);
	if (n_type == 'X')
		count += ft_putchar("0123456789ABCDEF"[arg % 16]);
	return (count);
}
