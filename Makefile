# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rouali <rouali@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 11:56:39 by rouali            #+#    #+#              #
#    Updated: 2023/01/25 11:56:42 by rouali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		=  server client

SRCS		=	client.c\
				server.c\
				libft.c


OBJS		= $(SRCS:.c=.o)

CC			= gcc

CFLAGS		=	-Wall -Wextra -Werror -c


all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(SRCS)
	$(CC) -o server server.o libft.o
	$(CC) -o client client.o libft.o


clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:		fclean all
