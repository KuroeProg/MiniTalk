/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:39:56 by cfiachet          #+#    #+#             */
/*   Updated: 2024/11/11 20:20:48 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lowhexauwu(unsigned long long c)
{
	int	len;

	len = 0;
	if (c >= 16)
	{
		len += ft_lowhexauwu(c / 16);
		len += ft_lowhexauwu(c % 16);
	}
	else
	{
		write(1, &"0123456789abcdef"[c], 1);
		len++;
	}
	return (len);
}

int	ft_putptr(void	*ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	else
	{
		len = ft_putstr("0x");
		len += ft_lowhexauwu((unsigned long long)ptr);
	}
	return (len);
}
