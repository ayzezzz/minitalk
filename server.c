/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:58:05 by zayaz             #+#    #+#             */
/*   Updated: 2024/05/13 20:03:50 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	static int	i;
	static int	bit;

	if (signum == SIGUSR1)
		bit |= (1 << i);
	i++;
	if (i == 7)
	{
		write(1, &bit, 1);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		sleep(1);
	return (0);
}
