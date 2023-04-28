/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurimot <rkurimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:25:38 by rkurimot          #+#    #+#             */
/*   Updated: 2023/02/13 05:00:09 by rkurimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbri(int n);
int	ft_putnbru(unsigned int n);

int	ft_putptr(uintptr_t p, const char *base);
int	ft_puthex(unsigned int n, const char *base);
int	handler(char **cur, va_list *ap);
int	ft_printf(const char *format, ...);

#endif /* FT_PRINTF_H */
