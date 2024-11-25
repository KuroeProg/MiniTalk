/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:09:29 by cfiachet          #+#    #+#             */
/*   Updated: 2024/11/25 11:44:10 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int ft_checkpid(pid_t pid, argv[1])
{
    if (pid == argv[1])
	{
		return (1);
	}
	else
		return (0);
}


void	ft_displaynbr(pid_t pid)
{
	if (pid > 9)
	{
		ft_displaynbr(pid / 10);
		ft_displaynbr(pid % 10);
	}
	else
	{
		pid = pid + '0';
		write(1, &pid, 1);
	}
}

void	get_pid()
{
	pid_t pid;

	pid = getpid();
	if (pid != -1)
	{
		ft_displaynbr(pid);
	}
}

int	main(void)
{
	get_pid();
	return (0);
}