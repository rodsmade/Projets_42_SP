# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 18:03:20 by roaraujo          #+#    #+#              #
#    Updated: 2021/10/01 12:38:29 by roaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
SOURCES = ./sources
OBJECTS = ./objects
HEADERFILES = ./headerfiles
BIN = ./bin
LIBFT = ./libft

all: libft printf

libft:	ft_itoa.o \
		ft_itoh.o \
		ft_putstr_fd.o \
		ft_strlen.o

# creates the executable file ft_printf to test printf development as of yet
printf: $(LIBFT)/libft.a
	mkdir -p $(BIN)
	$(CC) $(CFLAGS) $(SOURCES)/*.c $(LIBFT)/libft.a -I $(HEADERFILES) -o $(BIN)/ft_printf

# creates object files from libft
%.o: $(LIBFT)/srcs/%.c
	gcc -c $< -I $(HEADERFILES) -o $(LIBFT)/objs/$@

$(LIBFT)/libft.a:
	ar -rcs $(LIBFT)/libft.a $(LIBFT)/objs/*.o

run:
	$(BIN)/ft_printf

clean:
	rm -rf $(OBJECTS)/*
	rm -rf $(LIBFT)/objs/*

fclean: clean
	rm -rf $(BIN)/*
	rm $(LIBFT)/libft.a

re: fclean all
