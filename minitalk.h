/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkurimot <rkurimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 04:39:10 by rkurimot          #+#    #+#             */
/*   Updated: 2023/04/29 06:47:13 by rkurimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libftprintf/ft_printf.h"
# include <limits.h>
# include <signal.h>
# include <sys/proc.h>
# include <sys/types.h>
# include <unistd.h>

int		ft_isnumeral(char *str);
int		ft_isspace(char c);
ssize_t	ft_strtol_ten(const char *str);
void	dispatch(pid_t pid, char c);

void	signal_handler(int signal);

#endif
