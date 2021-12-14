# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 18:18:37 by roaraujo          #+#    #+#              #
#    Updated: 2021/12/10 15:50:11 by roaraujo         ###   ########.fr        #
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
DEBUG = -g
CFLAGS = -Wall -Wextra -Werror -O3 $(DEBUG) -I $(HEADERS_PATH)
# VALGRIND = valgrind --leak-check=full --show-leak-kinds=all -s --track-fds=yes --trace-children=yes --error-exitcode=1 --track-origins=yes
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck
# TODO: dar uma olhada aqui nessas flags dps: valgrind -q --leak-check=full --show-leak-kinds=all -s --track-fds=yes --trace-children=yes --error-exitcode=1 --track-origins=yes ./a.out

# BASH COMMANDS
RM = rm -f
MKDIR = mkdir -p
MAKE_NOPRINT = $(MAKE) --no-print-directory
TOUCH = touch -a

# FILES
NAME = $(BINS_PATH)so_long
LIBFT_A = $(LIBS_PATH)libft.a
SRC_FILES = game_close_utils.c \
			game_init_utils.c \
			hooks_utils.c \
			input_validation_utils.c \
			map_validation_utils.c \
			movement_utils.c \
			render_utils.c \
			render_utils_2.c \
			render_utils_3.c \
			so_long.c
SOURCES = $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))

# TARGETS
all: make_dir $(NAME)

# -> compiles libft all over
$(LIBFT_A):
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT)

make_dir:
	@$(MKDIR) $(BINS_PATH)

# -> creates executable so_long inside ./bin/
$(NAME): $(LIBFT_A) $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -lmlx -lXext -lX11 -L $(LIBS_PATH) -lft

# -> creates object files for so_long
$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	@$(MKDIR) $(OBJS_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

# -> mandatory flag for project submission
bonus: all

# RUN

run: $(NAME)
	@$(NAME) $(MAP)

valgrind: $(NAME)
	@$(VALGRIND) $(NAME) $(MAP)

# SANITIZE
# -> deletes all .o files; also runs libft's clean target
clean:
	@$(RM) $(OBJECTS)
	@$(MAKE_NOPRINT) clean -C $(LIBS_PATH)libft/

# -> deletes .o files + static library file + executable; also runs libft's fclean target
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE_NOPRINT) fclean -C $(LIBS_PATH)libft/

# -> 
re: fclean all

.PHONY: all run clean fclean re valgrind bonus make_dir