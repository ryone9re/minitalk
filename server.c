/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurimot <rkurimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 04:36:15 by rkurimot          #+#    #+#             */
/*   Updated: 2023/04/29 06:42:34 by rkurimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal)
{
	static size_t	lit;
	static size_t	bit;

	if (signal == SIGUSR1)
		lit |= (0b1 << bit);
	bit++;
	if (bit < 8)
		return ;
	ft_printf("%c", lit);
	lit = 0;
	bit = 0;
}

int	main(void)
{
	static struct sigaction	sa1;
	static struct sigaction	sa2;
	pid_t					pid;

	sa1.sa_handler = signal_handler;
	sa2.sa_handler = signal_handler;
	sigaddset(&sa1.sa_mask, SIGUSR2);
	sigaddset(&sa2.sa_mask, SIGUSR1);
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (1)
		pause();
	return (0);
}
