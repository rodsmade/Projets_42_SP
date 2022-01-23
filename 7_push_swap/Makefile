# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 18:18:37 by roaraujo          #+#    #+#              #
#    Updated: 2022/01/22 22:36:54 by roaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PATH VARIABLES
BINS_PATH = ./bin/
HEADERS_PATH = ./include/
LIBS_PATH = ./libs/
OBJS_PATH = ./objs/
SRCS_PATH = ./src/

# COMPILATION
CC = gcc
DEBUG = -g
CFLAGS = -Wall -Wextra -Werror $(DEBUG) -I $(HEADERS_PATH)
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck

# BASH COMMANDS
RM = rm -f
MKDIR = mkdir -p
MAKE_NOPRINT = $(MAKE) --no-print-directory
TOUCH = touch -a

# FILES
NAME = $(BINS_PATH)push_swap
SRC_FILES = push_swap.c \
			utils_double_list_1.c \
			utils_double_list_2.c \
			utils_operations_push.c \
			utils_operations_reverse_rotate.c \
			utils_operations_rotate.c \
			utils_operations_swap.c \
			utils_sorting.c
SOURCES = $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))

# TARGETS
all: libft make_dir $(NAME)

# -> compiles libft all over
libft:
	cd $(LIBS_PATH)libft && $(MAKE)

# -> creates folder if it doesn't already exist
make_dir:
	$(MKDIR) $(BINS_PATH)
	$(MKDIR) $(OBJS_PATH)

# -> creates executable push_swap inside ./bin/
$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -L $(LIBS_PATH) -lft

# -> creates object files for push_swap
$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

# -> mandatory flag for project submission
bonus: all

# RUN
run: $(NAME)
# 
	$(NAME) $$ARG

valgrind: $(NAME)
	$(VALGRIND) $(NAME) $$ARG

# SANITIZE
# -> deletes all .o files; also runs libft's clean target
clean:
	$(RM) $(OBJECTS) $(OBJECTS_BONUS)

# -> deletes .o files + static library file + executable; also runs libft's fclean target
fclean: clean
	cd $(LIBS_PATH)libft && $(MAKE) fclean
	$(RM) $(NAME) $(NAME_BONUS)

# -> full clean, recompile
re: fclean all

.PHONY: all run clean fclean re valgrind bonus make_dir