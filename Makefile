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
NAME		=  minitalk

SERVER		= server

CLIENT		= client

CC			= cc

CFLAGS		=	-Wall -Wextra -Werror

OBJS		= server.o client.o libft.o

all:		$(NAME)

$(NAME):	$(SERVER) $(CLIENT)

$(SERVER):  server.c libft.c
	$(CC) $(CFLAGS) server.c libft.c -o server

$(CLIENT):  client.c libft.c
	$(CC) $(CFLAGS) client.c libft.c -o client

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f server client

re:		fclean all
