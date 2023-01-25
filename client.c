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

void	send_message(int pid, char *message)
{
	int	i;
	int	j;
	int k;

	i = 0;
	while (message[i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			if (message[i] & (1 << j))
			{

				k = kill(pid, SIGUSR1);
				if (k == -1)
					exit(-1);
			}
			else
			{
				k = kill(pid, SIGUSR2);
				if (k == -1)
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

	(void)ac;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		send_message(pid, av[2]);
	}
	return (0);
}
