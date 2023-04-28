/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurimot <rkurimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 04:36:10 by rkurimot          #+#    #+#             */
/*   Updated: 2023/04/29 06:12:46 by rkurimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isnumeral(char *str)
{
	if (!str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\r')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\v')
		return (1);
	return (0);
}

ssize_t	ft_strtol_ten(const char *str)
{
	ssize_t	i;
	ssize_t	neg;

	while (ft_isspace(*str))
		str++;
	i = 0;
	neg = -1;
	if (*str == '-')
		neg = 0;
	if (*str == '+' || *str == '-')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		if (i < (((ssize_t)(SIZE_MAX / 2) * -1) + (*str - '0')) / 10)
			return (neg);
		i = i * 10 - (*str - '0');
		str++;
	}
	if (!neg)
		return (i);
	return (-i);
}

void	dispatch(pid_t pid, char c)
{
	size_t	i;

	i = 0;
	while (i < 8)
	{
		if (c & (0b1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		i++;
	}
}

int	main(int argc, char **argv)
{
	ssize_t	pid;
	char	*w;

	if (argc != 3)
		return (1);
	if (!ft_isnumeral(argv[1]))
		return (1);
	pid = ft_strtol_ten(argv[1]);
	if (pid < (ssize_t)100 || (ssize_t)99999 < pid)
		return (1);
	w = argv[2];
	while (*w != '\0')
		dispatch((pid_t)pid, *w++);
	return (0);
}
