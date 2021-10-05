# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 18:03:20 by roaraujo          #+#    #+#              #
#    Updated: 2021/10/04 21:45:14 by roaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PATH VARIABLES
HEADERS_PATH = ./headerfiles/
SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/
LIBS_PATH = ./libs/
BINS_PATH = ./bin/

# COMPILATION
CC = gcc
FLAGS = -Wall -Wextra -Werror

# BASH COMMANDS
RM = rm -f
MKDIR = mkdir -p

# FILES
LIBNAME = libprintft.a
SRC_FILES =	ft_printf.c
SOURCES = $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))

# TARGETS
all: libft $(LIBNAME)

# compiles libft all over
libft:
	cd $(LIBS_PATH)libft && $(MAKE)

# creates the executable file ft_printf to test printf development as of yet
$(LIBNAME): $(LIBS_PATH)libft.a
	$(MKDIR) $(BINS_PATH)
	$(CC) $(CFLAGS) $(SOURCES) $(LIBS_PATH)libft.a -I $(HEADERS_PATH) -o $(BINS_PATH)ft_printf

# creates object files from libft
$(OBJS_PATH)%.o : $(SRCS_PATH)%.c $(HEADERS_PATH)*.h
	$(MKDIR) $(OBJS_PATH)
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEADERS_PATH)

run:
	$(BINS_PATH)ft_printf

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(BINS_PATH)*
	$(RM) $(LIBS_PATH)libft.a
	$(RM) $(LIBS_PATH)$(LIBNAME)

re: fclean all

.PHONY: all run clean fclean re