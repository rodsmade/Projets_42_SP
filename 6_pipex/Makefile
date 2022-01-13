# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 18:18:37 by roaraujo          #+#    #+#              #
#    Updated: 2022/01/13 18:46:23 by roaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PATH VARIABLES
HEADERS_PATH = ./include/
SRCS_PATH = ./src/
OBJS_PATH = ./objs/
BINS_PATH = ./bin/

# TEST ARGS
INPUT_FILE = input_file
CMD1 = "ls -l"
CMD2 = "wc -l"
OUTPUT_FILE = output_file

# COMPILATION
CC = gcc
DEBUG = -g
# CFLAGS = -O3 $(DEBUG) -I $(HEADERS_PATH)
CFLAGS = -Wall -Wextra -Werror -O3 -I $(HEADERS_PATH)
# VALGRIND = valgrind --leak-check=full --show-leak-kinds=all -s --track-fds=yes --trace-children=yes --error-exitcode=1 --track-origins=yes
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck
# TODO: dar uma olhada aqui nessas flags dps: valgrind -q --leak-check=full --show-leak-kinds=all -s --track-fds=yes --trace-children=yes --error-exitcode=1 --track-origins=yes ./a.out

# BASH COMMANDS
RM = rm -f
MKDIR = mkdir -p
MAKE_NOPRINT = $(MAKE) --no-print-directory
TOUCH = touch -a

# FILES
NAME = $(BINS_PATH)pipex
NAME_BONUS = $(BINS_PATH)pipex_bonus
SRC_FILES = exec_pipe_utils.c \
			exit_utils.c \
			init_utils.c \
			libft_utils_1.c \
			libft_utils_2.c \
			libft_utils_3.c \
			libft_utils_ftsplit.c \
			parsing_utils.c \
			pipex.c
#			teste.c
SRC_FILES_BONUS = exec_pipe_utils.c \
			exit_utils.c \
			init_utils_bonus.c \
			libft_utils_1.c \
			libft_utils_2.c \
			libft_utils_3.c \
			libft_utils_ftsplit.c \
			parsing_utils.c \
			pipex.c
SOURCES = $(addprefix $(SRCS_PATH), $(SRC_FILES))
SOURCES_BONUS = $(addprefix $(SRCS_PATH), $(SRC_FILE_BONUS))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJ_FILES_BONUS = $(patsubst %.c, %.o, $(SRC_FILES_BONUS))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))
OBJECTS_BONUS = $(addprefix $(OBJS_PATH), $(OBJ_FILES_BONUS))

# TARGETS
all: make_dir $(NAME)

make_dir:
	@$(MKDIR) $(BINS_PATH)
	@$(MKDIR) $(OBJS_PATH)

# -> creates executable pipex inside ./bin/
$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

# -> creates object files for pipex
$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

# -> mandatory flag for project submission
bonus: make_dir $(NAME_BONUS)

$(NAME_BONUS): $(OBJECTS_BONUS)
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJECTS_BONUS)

# RUN
run: $(NAME)
# na vdd tem que ser  infile "ls -l" "wc -l" outfile
	@$(NAME) $(INPUT_FILE) $(CMD1) $(CMD2) $(OUTPUT_FILE)

valgrind: $(NAME)
	@$(VALGRIND) $(NAME) $(INPUT_FILE) $(CMD1) $(CMD2) $(OUTPUT_FILE)

run_b: $(NAME)
# na vdd tem que ser  infile "ls -l" "wc -l" outfile
	@$(NAME) $(INPUT_FILE) $(CMD1) $(CMD2) $(OUTPUT_FILE)

valgrind_b: $(NAME)
	@$(VALGRIND) $(NAME) $(INPUT_FILE) $(CMD1) $(CMD2) $(OUTPUT_FILE)

# SANITIZE
# -> deletes all .o files; also runs libft's clean target
clean:
	@$(RM) $(OBJECTS) $(OBJECTS_BONUS)

# -> deletes .o files + static library file + executable; also runs libft's fclean target
fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)

# -> 
re: fclean all

.PHONY: all run clean fclean re valgrind bonus make_dir run_b valgrind_b