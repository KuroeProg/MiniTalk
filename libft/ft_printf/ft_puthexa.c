/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:14:32 by cfiachet          #+#    #+#             */
/*   Updated: 2024/11/11 20:20:38 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uphexa(unsigned int c)
{
	int	len;

	len = 0;
	if (c >= 16)
	{
		len += ft_uphexa(c / 16);
		len += ft_uphexa(c % 16);
	}
	else
	{
		write(1, &"0123456789ABCDEF"[c], 1);
		len++;
	}
	return (len);
}

int	ft_lowhexa(unsigned int c)
{
	int	len;

	len = 0;
	if (c >= 16)
	{
		len += ft_lowhexa(c / 16);
		len += ft_lowhexa(c % 16);
	}
	else
	{
		write(1, &"0123456789abcdef"[c], 1);
		len++;
	}
	return (len);
}

int	ft_puthexa(unsigned int c, char letter)
{
	int	len;

	len = 0;
	if (letter == 'X')
		len = ft_uphexa(c);
	else if (letter == 'x')
		len = ft_lowhexa(c);
	return (len);
}
