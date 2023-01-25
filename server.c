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

void	handl_message(int segnals)
{
	static int	binarys[8];
	static int	c;

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
}

int	main(void)
{
	int	sig;

	sig = getpid();
	ft_putnbr(sig);
	ft_putchar('\n');
	signal(SIGUSR1, handl_message);
	signal(SIGUSR2, handl_message);
	while (1)
	{
	}
}
