# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/04 05:16:53 by sbouheni          #+#    #+#              #
#    Updated: 2023/06/06 01:44:17 by sbouheni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
DEBUGFLAGS	=	-g -fsanitize=address
COMPILE 	= 	$(CC) $(CFLAGS)
DEBUG		=	$(CC) $(DEBUGFLAGS)
LIBNAME		=	libft.a
NAME		=	client server

all : $(NAME)

client : ./src/client.c $(LIBNAME)
	$(COMPILE) ./src/client.c $(LIBNAME) -o client

server : ./src/server.c $(LIBNAME)
	$(COMPILE) ./src/server.c $(LIBNAME) -o server

$(LIBNAME) :
	make -C libft
	mv ./libft/libft.a .

clean : 
	rm -f $(LIBNAME)
	make clean -C libft

fclean : clean
	rm -f $(NAME)

re : fclean all

debug : $(LIBNAME) debug_client debug_server

debug_client : ./src/client.c $(LIBNAME)
	$(DEBUG) ./src/client.c $(LIBNAME) -o client

debug_server : ./src/server.c $(LIBNAME)
	$(DEBUG) ./src/server.c $(LIBNAME) -o server
