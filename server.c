/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:09:29 by cfiachet          #+#    #+#             */
/*   Updated: 2024/11/29 18:43:45 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	reset(t_str *str)
{
	free(str->str);
	str->str = NULL;
	str->i = 0;
}

void	add_char(t_str *str, char c)
{
	char	*new;
	int		size;

	size = str->i++;
	new = malloc(sizeof(int) * size + 1);
	if (!new)
	{
		reset(str);
		exit(EXIT_FAILURE);
	}
	if (str->str)
	{
		while(str->i--)
			new[str->i] = str->str[str->i];
		free(str->str);
	}
	new[size - 1] = c;
	new[size] = '\0';
	str->str = new;
	str->i = size;
}

void	signal_handler(int signal, siginfo_t *info, void *s)
{
	static char		c;
	static t_str 	str;

	(void)s;
	c = 0;
	if (signal == SIGUSR1)
		c |= (0x01 << str.bit);
	str.bit++;
	if (str.bit == 8)
	{
		str.bit = 0;
		if (c == '\0')
		{
			printf("%s\n", str.str);
			reset(&str);
		}
		else
			add_char(&str, i);
		c = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	signal;

	(void)argv;
	if (argc != 1)
		return (printf("Error, number of arguments invalid.\n"), 0);
	signal.sa_sEsigaction = signal_handler;
	signal.sa_flags = 0;
	sigemptyset(&signal.sa_mask);
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	printf("Hello! The PID is : %d\nWaiting for a message\n", getpid());
	while (1)
		pause();
	return (0);
}
