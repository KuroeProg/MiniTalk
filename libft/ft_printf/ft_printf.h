/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:14:02 by cfiachet          #+#    #+#             */
/*   Updated: 2024/11/04 21:53:03 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);

int	ft_integers(int d);
int	ft_putstr(char *str);
int	ft_unsignednbr(unsigned int d);
int	ft_puthexa(unsigned int c, char letter);
int	ft_putptr(void	*ptr);

#endif