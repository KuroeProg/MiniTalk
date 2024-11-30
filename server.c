/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:09:29 by cfiachet          #+#    #+#             */
/*   Updated: 2024/11/30 12:17:06 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reset(char **str, int *i, int *bit)
{
    if (*str)
        free(*str);
    *str = NULL;
    *i = 0;
    *bit = 0;
}

void	add_char(char **str, char c, int *i)
{
    char	*new;
    int		len;

    len = *i + 1;
    new = malloc(sizeof(char) * (len + 1));
    if (!new)
        return ;
    if (*str)
    {
        ft_memcpy(new, *str, *i);
        free(*str);
    }
    new[*i] = c;
    new[len] = '\0';
    *str = new;
    (*i)++;
}

void	signal_handler(int signal, siginfo_t *info, void *s)
{
    static char		c = 0;
    static char		*str = NULL;
    static int		i = 0;
    static int		bit = 0;

    (void)s;
    if (signal == SIGUSR1)
        c |= (0x01 << bit);
    bit++;
    if (bit == 8)
    {
        bit = 0;
        if (c == '\0')
        {
            ft_printf("%s\n", str);
            reset(&str, &i, &bit);
        }
        else
            add_char(&str, c, &i);
        c = 0;
        kill(info->si_pid, SIGUSR2);
    }
}

int	main(int argc, char **argv)
{
    struct sigaction	signal;

    (void)argv;
    if (argc != 1)
        return (ft_printf("Error, number of arguments invalid.\n"), 0);
    signal.sa_sigaction = signal_handler;
    signal.sa_flags = SA_SIGINFO;
    sigemptyset(&signal.sa_mask);
    sigaction(SIGUSR1, &signal, NULL);
    sigaction(SIGUSR2, &signal, NULL);
    ft_printf("Hello! The PID is : %d\nWaiting for a message\n", getpid());
    while (1)
        pause();
    return (0);
}