/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:01:12 by cfiachet          #+#    #+#             */
/*   Updated: 2024/11/04 21:25:38 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_integers(int d)
{
	int	len;

	len = 0;
	if (d == -2147483648)
		return (write(1, "-2147483648", 11), 11);
	if (d < 0)
	{
		d = -d;
		write(1, "-", 1);
		len++;
	}
	if (d > 9)
	{
		len += ft_integers(d / 10);
		len += ft_integers(d % 10);
	}
	else
	{
		write(1, &"0123456789"[d], 1);
		len++;
	}
	return (len);
}
