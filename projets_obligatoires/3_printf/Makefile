# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 18:03:20 by roaraujo          #+#    #+#              #
#    Updated: 2021/10/06 13:13:45 by roaraujo         ###   ########.fr        #
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
LIBNAME = libprintf.a
SRC_FILES = ft_printf.c
SOURCES = $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))

# TARGETS
all: libft $(LIBNAME)

# compiles libft all over
libft:
	@cd $(LIBS_PATH)libft && $(MAKE)

$(LIBNAME): $(OBJECTS)
	@ar -rcs $(LIBS_PATH)$(LIBNAME) $(OBJECTS)

# creates object files for ft_printf (libprintf)
$(OBJS_PATH)%.o : $(SRCS_PATH)%.c $(HEADERS_PATH)*.h
	@$(MKDIR) $(OBJS_PATH)
	@$(CC) $(FLAGS) -c $< -I $(HEADERS_PATH) -o $@

# creates the executable file ft_printf_test to test development
main:	./main.c
	@$(MKDIR) $(BINS_PATH)
	@$(CC) $(CFLAGS) $< $(LIBS_PATH)libprintf.a $(LIBS_PATH)libft.a -I $(HEADERS_PATH) -o $(BINS_PATH)ft_printf_test

run: main
	@$(BINS_PATH)ft_printf_test

clean:
	@$(RM) $(OBJECTS)
	@cd $(LIBS_PATH)libft && $(MAKE) $@

fclean: clean
	@$(RM) $(BINS_PATH)*
	@$(RM) $(LIBS_PATH)$(LIBNAME)
	@cd $(LIBS_PATH)libft && $(MAKE) $@

re: fclean all

.PHONY: all run clean fclean re