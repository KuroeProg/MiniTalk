/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignednbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:12:02 by cfiachet          #+#    #+#             */
/*   Updated: 2024/11/04 21:56:28 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsignednbr(unsigned int d)
{
	int		len;
	char	c;

	len = 0;
	if (d > 9)
	{
		len += ft_unsignednbr(d / 10);
		len += ft_unsignednbr(d % 10);
	}
	else
	{
		c = d + '0';
		write(1, &c, 1);
		len++;
	}
	return (len);
}
