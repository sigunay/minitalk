/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigunay <sigunay@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:51:13 by sigunay           #+#    #+#             */
/*   Updated: 2024/02/29 13:45:45 by sigunay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "minitalk.h"

void	ft_handler(int signum)
{
	static int	bits = 128;
	static char	c = 0;

	if (signum == SIGUSR1)
		c += bits;
	bits /= 2;
	if (bits <= 0)
	{
		write(1, &c, 1);
		bits = 128;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("PID: ");
	ft_putnbr(pid);
	ft_putstr("\n");
	while (42)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause();
	}
}
