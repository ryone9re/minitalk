/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurimot <rkurimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 04:57:26 by rkurimot          #+#    #+#             */
/*   Updated: 2023/02/13 05:36:06 by rkurimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	char	buf[1];

	buf[0] = (char)c;
	return (write(1, buf, 1));
}

int	ft_putstr(char *str)
{
	size_t	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = 0;
	while (str[len])
		len++;
	return (write(1, str, len));
}

int	ft_putnbri(int n)
{
	size_t	i;
	size_t	j;
	char	s[sizeof(int) * 8];
	char	t[sizeof(int) * 8];

	i = 0;
	j = 0;
	if (n < 0)
		s[i++] = '-';
	else
		n *= -1;
	t[j++] = -(n % 10) + '0';
	n /= 10;
	while (n)
	{
		t[j++] = -(n % 10) + '0';
		n /= 10;
	}
	while (j)
		s[i++] = t[--j];
	return (write(1, s, i));
}

int	ft_putnbru(unsigned int n)
{
	size_t	i;
	size_t	j;
	char	s[sizeof(int) * 8];
	char	t[sizeof(int) * 8];

	i = 0;
	j = 0;
	t[j++] = n % 10 + '0';
	n /= 10;
	while (n)
	{
		t[j++] = n % 10 + '0';
		n /= 10;
	}
	while (j)
		s[i++] = t[--j];
	return (write(1, s, i));
}
