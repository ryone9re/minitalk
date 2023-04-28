/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurimot <rkurimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:29:07 by rkurimot          #+#    #+#             */
/*   Updated: 2023/02/14 13:50:45 by rkurimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(uintptr_t p, const char *base)
{
	size_t	i;
	size_t	j;
	char	s[sizeof(int) * 8];
	char	t[sizeof(int) * 8];

	i = 0;
	s[i++] = '0';
	s[i++] = 'x';
	j = 0;
	t[j++] = base[p % 16];
	p /= 16;
	while (p)
	{
		t[j++] = base[p % 16];
		p /= 16;
	}
	while (j)
		s[i++] = t[--j];
	return (write(1, s, i));
}

int	ft_puthex(unsigned int n, const char *base)
{
	size_t	i;
	size_t	j;
	char	s[sizeof(int) * 8];
	char	t[sizeof(int) * 8];

	if (!n)
		return (write(1, "0", 1));
	i = 0;
	j = 0;
	t[j++] = base[n % 16];
	n /= 16;
	while (n)
	{
		t[j++] = base[n % 16];
		n /= 16;
	}
	while (j)
		s[i++] = t[--j];
	return (write(1, s, i));
}

int	handler(char **cur, va_list *ap)
{
	int	i;

	if (!((*cur)[1]))
		return (write(1, (*cur)++, 1));
	(*cur)++;
	i = -1;
	if (**cur == 'c')
		i = ft_putchar(va_arg(*ap, int));
	if (**cur == 's')
		i = ft_putstr(va_arg(*ap, char *));
	if (**cur == 'p')
		i = ft_putptr(va_arg(*ap, uintptr_t), "0123456789abcdef");
	if (**cur == 'd' || **cur == 'i')
		i = ft_putnbri(va_arg(*ap, int));
	if (**cur == 'u')
		i = ft_putnbru(va_arg(*ap, unsigned int));
	if (**cur == 'x')
		i = ft_puthex(va_arg(*ap, unsigned int), "0123456789abcdef");
	if (**cur == 'X')
		i = ft_puthex(va_arg(*ap, unsigned int), "0123456789ABCDEF");
	if (**cur == '%')
		i = write(1, "%", 1);
	(*cur)++;
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*cur;
	int		i;
	int		ret;

	if (!format)
		return (-1);
	va_start(ap, format);
	cur = (char *)format;
	ret = 0;
	while (*cur)
	{
		if (*cur == '%')
			i = handler(&cur, &ap);
		else
			i = write(1, cur++, 1);
		if (i < 0)
		{
			va_end(ap);
			return (-1);
		}
		ret += i;
	}
	va_end(ap);
	return (ret);
}
