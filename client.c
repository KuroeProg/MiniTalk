/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:49:45 by cfiachet          #+#    #+#             */
/*   Updated: 2024/12/12 14:54:38 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("SIGUSR1 failed\n");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("SIGUSR2 failed\n");
				exit(EXIT_FAILURE);
			}
		}
		usleep(300);
		bit++;
	}
}

void	send_str(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		return (ft_printf("./client <PID> <Message>\n"), 1);
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(2, "INVALID PID \n", 13);
		return (1);
	}
	signal(SIGUSR2, SIG_IGN);
	ft_printf("Sending message to PID: %d\n", pid);
	send_str(pid, argv[2]);
	ft_printf("Message sent\n");
	return (0);
}
