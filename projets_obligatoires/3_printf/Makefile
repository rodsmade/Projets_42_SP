# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 18:03:20 by roaraujo          #+#    #+#              #
#    Updated: 2021/09/30 16:30:59 by roaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ./sources
OBJECTS = ./objects
HEADERFILES = ./headerfiles
EXEC = ./exec
LIBFT = ./libft

all: libft printf

libft:	ft_itoa.o \
		ft_putstr_fd.o \
		ft_strlen.o

printf:
	$(CC) $(CFLAGS) $(SOURCES)/*.c $(OBJECTS)/*.o -I $(HEADERFILES) -o $(EXEC)/ft_printf

%.o: $(LIBFT)/%.c
	gcc -c $< -I $(HEADERFILES) -o $(OBJECTS)/$@

run:
	$(EXEC)/ft_printf

clean:
	rm -rf $(OBJECTS)/*

fclean: clean
	rm -rf $(EXEC)/*

re: fclean all

# CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# SRCS = ./sources/ft_printf.c
# LIBFT = ./libft/ft_itoa.c libft/ft_putstr_fd.c libft/ft_strlen.c
# OBJS = $(SRCS:.c=.o)
# OBJS_LIBFT = $(LIBFT:.c=.o)
# HEADERFILES = ./headerfiles/
# EXEC = ./executable
# OBJECTS = ./objects

# all:
# 	$(CC) $(CFLAGS) -c $(SRCS) $(LIBFT) -I $(HEADERFILES) -o $(OBJECTS)/????
# 	mkdir $(EXEC)/
# 	$(CC) $(CFLAGS) $(OBJECTS)/* -I $(HEADERFILES) -o $(EXEC)/app

# clean:
# 	rm -f $(OBJECTS)/*
# 	rm -rf executable/

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all