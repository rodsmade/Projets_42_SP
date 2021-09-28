# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 18:03:20 by roaraujo          #+#    #+#              #
#    Updated: 2021/09/28 18:10:35 by roaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = sources/ft_printf.c
LIBFT = libft/ft_itoa.c libft/ft_putstr_fd.c libft/ft_strlen.c
OBJS = $(SRCS:.c=.o)
OBJS_LIBFT = $(LIBFT:.c=.o)
HEADERFILES = headerfiles/

all:
	$(CC) $(CFLAGS) -c $(SRCS) $(LIBFT) -I $(HEADERFILES)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all