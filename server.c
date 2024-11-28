/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:09:29 by cfiachet          #+#    #+#             */
/*   Updated: 2024/11/28 18:21:24 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	signal_handler(int signal, siginfo_t *info, void *str)
{
	static int	i;
	static int	bit;

	(void)str;
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	if (bit == 8)
	{
		bit = 0;
		printf("%c", i);
		i = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	signal;

	(void)argv;
	if (argc != 1)
		return (printf("Error, number of arguments invalid.\n"), 0);
	signal.sa_sigaction = signal_handler;
	signal.sa_flags = 0;
	sigemptyset(&signal.sa_mask);
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	printf("Hello! The PID is : %d\nWaiting for a message\n", getpid());
	while (1)
		pause();
	return (0);
}
