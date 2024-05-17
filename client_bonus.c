/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:57:08 by zayaz             #+#    #+#             */
/*   Updated: 2024/05/17 13:32:10 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *s)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = (result * 10) + s[i] - '0';
		i++;
	}
	return (result * sign);
}

void	signal_msj(int a)
{
	static int	b = 0;

	(void)a;
	if (b == 0)
		ft_printf("message has arrived\n");
	b++;
}

void	bitwise_unix(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		signal(SIGUSR1, &signal_msj);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid_srv;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid_srv = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			bitwise_unix(argv[2][i], pid_srv);
			i++;
		}
	}
	else
		ft_printf("please add three arguments\n");
	return (0);
}
