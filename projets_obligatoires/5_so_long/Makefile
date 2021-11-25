# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 18:18:37 by roaraujo          #+#    #+#              #
#    Updated: 2021/11/17 18:36:49 by roaraujo         ###   ########.fr        #
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
FLAGS = -Wall -Wextra -Werror -O3

# BASH COMMANDS
RM = rm -f
MKDIR = mkdir -p
MAKE_NOPRINT = $(MAKE) --no-print-directory

# FILES
SRC_FILES = so_long.c \
			movement_utils.c \
			render_utils.c \
			hooks_utils.c
SOURCES = $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))
NAME = so_long

# TARGETS
all: libft $(NAME)

# -> compiles libft all over
libft:
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT)

# -> creates the executable file so_long to run game
$(NAME): $(OBJECTS) ./main.c
	$(MKDIR) $(BINS_PATH)
	$(CC) $(FLAGS) main.c -I $(HEADERS_PATH) -o $(BINS_PATH)$(NAME) -lmlx -lXext -lX11

# -> creates object files for libso_long
$(OBJS_PATH)%.o : $(SRCS_PATH)%.c $(HEADERS_PATH)*.h
	$(MKDIR) $(OBJS_PATH)
	$(CC) $(FLAGS) -c $< -I $(HEADERS_PATH) -o $@ -lmlx

# -> mandatory flag for project submission
bonus: all

# RUN
run: all $(NAME)
	$(BINS_PATH)$(NAME)

# SANITIZE
# -> deletes all .o files; also runs libft's clean target
clean:
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT) $@
	$(RM) $(OBJECTS)

# -> deletes .o files + static library file + NAME; also runs libft's fclean target
fclean: clean
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT) $@
	$(RM) $(BINS_PATH)$(NAME)

# -> sanitizes and re-compiles all over again 
re: fclean all

.PHONY: all run clean fclean re bonus libft so_long