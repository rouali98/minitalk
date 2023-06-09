/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:56:49 by rouali            #+#    #+#             */
/*   Updated: 2023/01/25 11:56:51 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	checker_pid(char *n)
{
	int	i;

	i = 0;
	while (n[i])
	{
		if (!ft_isdigit(n[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	send_message(int pid, char *message)
{
	int	i;
	int	j;

	i = 0;
	while (message[i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			if (message[i] & (1 << j))
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(-1);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(-1);
			}
			j--;
			usleep(500);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3 || (av[2][0] == 0))
	{
		ft_putstr("Incorrect Data!");
		return (0);
	}
	if (!checker_pid(av[1]))
	{
		ft_putstr("Incorrect PID!");
		return (0);
	}
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid == 0)
		{
			ft_putstr("Incorrect PID!");
			return (0);
		}
		send_message(pid, av[2]);
	}
	return (0);
}
