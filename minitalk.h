/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:56:59 by rouali            #+#    #+#             */
/*   Updated: 2023/01/25 11:57:01 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

//========> Server <==========//

void	hand_mess(int segnals);
void	convert(int *n);
int		powr(int r, int i);

//========> Client <==========//

void	send_message(int pid, char *mess);

//========> Libft <==========//

void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	ft_putchar(char c);
int		ft_atoi(const char *str);
int		ft_isdigit(int n);
int		checker_pid(char *n);

#endif
