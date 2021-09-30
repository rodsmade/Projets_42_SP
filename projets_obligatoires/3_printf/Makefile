# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 18:03:20 by roaraujo          #+#    #+#              #
#    Updated: 2021/09/30 16:34:38 by roaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ./sources
OBJECTS = ./objects
HEADERFILES = ./headerfiles
BIN = ./bin
LIBFT = ./libft

all: libft printf

libft:	ft_itoa.o \
		ft_putstr_fd.o \
		ft_strlen.o

printf:
	$(CC) $(CFLAGS) $(SOURCES)/*.c $(OBJECTS)/*.o -I $(HEADERFILES) -o $(BIN)/ft_printf

%.o: $(LIBFT)/%.c
	gcc -c $< -I $(HEADERFILES) -o $(OBJECTS)/$@

run:
	$(BIN)/ft_printf

clean:
	rm -rf $(OBJECTS)/*

fclean: clean
	rm -rf $(BIN)/*

re: fclean all
