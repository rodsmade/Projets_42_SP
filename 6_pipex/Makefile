# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 18:18:37 by roaraujo          #+#    #+#              #
#    Updated: 2022/01/11 17:50:43 by roaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PATH VARIABLES
HEADERS_PATH = ./include/
SRCS_PATH = ./src/
OBJS_PATH = ./objs/
BINS_PATH = ./bin/

# TEST ARGS
INPUT_FILE = input_file
CMD1 = "ls -l" "cat -a"
CMD2 = "wc -l" "tr ' ' \" \""
OUTPUT_FILE = output_file

# COMPILATION
CC = gcc
DEBUG = -g
# CFLAGS = -O3 $(DEBUG) -I $(HEADERS_PATH)
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
NAME = $(BINS_PATH)pipex
SRC_FILES = libft_utils_ftsplit.c \
			libft_utils.c \
			exit_utils.c \
			exec_pipe_utils.c \
			pipex.c
#			teste.c
SOURCES = $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))

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
	@$(MKDIR) $(OBJS_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

# -> mandatory flag for project submission
bonus: all

# RUN
run: $(NAME)
# na vdd tem que ser  infile "ls -l" "wc -l" outfile
	@$(NAME) $(INPUT_FILE) $(CMD1) $(CMD2) $(OUTPUT_FILE)

valgrind: $(NAME)
	@$(VALGRIND) $(NAME) $(INPUT_FILE) $(CMD1) $(CMD2) $(OUTPUT_FILE)

# SANITIZE
# -> deletes all .o files; also runs libft's clean target
clean:
	@$(RM) $(OBJECTS)

# -> deletes .o files + static library file + executable; also runs libft's fclean target
fclean: clean
	@$(RM) $(NAME)

# -> 
re: fclean all

.PHONY: all run clean fclean re valgrind bonus make_dir