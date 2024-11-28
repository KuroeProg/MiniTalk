/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:11:39 by cfiachet          #+#    #+#             */
/*   Updated: 2024/11/04 21:48:42 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_format(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 'd' || c == 'i')
		len += ft_integers(va_arg(args, int));
	else if (c == 'c')
		len += ft_putchar((char)va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (c == 'u')
		len += ft_unsignednbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_puthexa(va_arg(args, unsigned int), c);
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		return_value;
	int		i;
	va_list	args;

	va_start(args, str);
	return_value = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			return_value += ft_format(args, str[i + 1]);
			i++;
		}
		else
			return_value += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (return_value);
}

/** 
int main()

{
	printf("printf :  \n");
	printf("Hello %c!\n", 'u');
	printf("ft_printf :  \n");
	ft_printf("Hello %c!\n",'u');
}
**/