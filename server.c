/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:57:10 by rouali            #+#    #+#             */
/*   Updated: 2023/01/25 11:57:12 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	powr(int po, int i)
{
	int	power;

	power = 1;
	if (i < 0)
		return (0);
	while (i)
	{
		power *= po;
		i--;
	}
	return (power);
}

void	convert(int *binarys)
{
	int		i;
	int		j;
	char	dec;
	int		rm;

	i = 0;
	j = 7;
	dec = 0;
	while (i < 8)
	{
		rm = binarys[j] % 10;
		dec += rm * powr(2, i);
		i++;
		j--;
	}
	ft_putchar(dec);
}

void	handl_message(int segnals, siginfo_t *info, void *v)
{
	static int	binarys[8];
	static int	count;
	static int	pid;

	(void)v;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		count = 0;
	}
	if (segnals == SIGUSR1)
	{
		binarys[count] = 1;
		count++;
	}
	else
	{
		binarys[count] = 0;
		count++;
	}
	if (count == 8)
	{
		convert(binarys);
		count = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	ro;

	ro.sa_sigaction = handl_message;
	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1)
	{
		sigaction(SIGUSR1, &ro, NULL);
		sigaction(SIGUSR2, &ro, NULL);
	}
}
