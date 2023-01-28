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

int	powr(int r, int i)
{
	int	power;

	power = 1;
	if (i < 0)
		return (0);
	while (i)
	{
		power *= r;
		i--;
	}
	return (power);
}

void	convert(int *n)
{
	int		i;
	char	dec;
	int		rem;
	int		r;

	i = 0;
	r = 7;
	dec = 0;
	while (i < 8)
	{
		rem = n[r] % 10;
		dec += rem * powr(2, i);
		i++;
		r--;
	}
	ft_putchar(dec);
}

void	handl_message(int segnals, siginfo_t *info, void *t)
{
	static int	binarys[8];
	static int	c;
	static int	opid;

	(void)t;
	if (opid != info->si_pid)
	{
		c = 0;
	}
	if (segnals == SIGUSR1)
	{
		binarys[c] = 1;
		c++;
	}
	else
	{
		binarys[c] = 0;
		c++;
	}
	if (c == 8)
	{
		convert(binarys);
		c = 0;
	}
	opid = info->si_pid;
}

int	main(void)
{
	int					sig;
	struct sigaction	sa;

	sa.sa_sigaction = handl_message;
	sa.sa_flags = 0;
	sig = getpid();
	ft_putnbr(sig);
	ft_putchar('\n');
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(1);
}
