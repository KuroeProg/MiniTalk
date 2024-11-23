/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiachet <cfiachet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:09:29 by cfiachet          #+#    #+#             */
/*   Updated: 2024/11/23 17:47:00 by cfiachet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_displaynbr(pid_t pid)
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

void    get_pid()
{
    pid_t pid;

    pid = getpid();
    if (pid != -1)
    {
        ft_displaynbr(pid);
    }

}

int main(void)
{
    get_pid();
    return 0;
}