/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:09:29 by cfiachet          #+#    #+#             */
/*   Updated: 2024/11/28 18:01:53 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	signal_handler(int signal, siginfo_t *info, void *str)
{
	static int	i;
	static int	bit;

	(void)info;
	(void)str;

}


int	main(int argc, char **argv)
{
	if (argc != 1)
		return (printf("Error, number of arguments invalid.\n"), 0);
	struct sigaction	s_sa;

	s_sa.sa_sigaction = &signal_handler;
	s_sa.sa_flags = 0;
	sigemptyset(&s_sa.sa_mask);

	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL);
	printf("Hello! The PID is : %d\nWaiting for a message\n", getpid());
	while (1)
		pause();
	return (0);
}
