/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurimot <rkurimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 04:36:15 by rkurimot          #+#    #+#             */
/*   Updated: 2023/04/29 06:03:48 by rkurimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal)
{
	static size_t	lit = 0;
	static size_t	bit = 0;

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
	pid_t	pid;

	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (1)
		pause();
	return (0);
}
