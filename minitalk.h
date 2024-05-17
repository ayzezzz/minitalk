/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:00:43 by zayaz             #+#    #+#             */
/*   Updated: 2024/05/13 20:00:46 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <unistd.h>

int		ft_atoi(char *src);
void	signal_msj(int a);
void	bitwise(char c, int pid);
void	bitwise_unix(char c, int pid);
void	signal_handle(int signum);
void	handler(int sig, siginfo_t *siginfo, void *context);

#endif