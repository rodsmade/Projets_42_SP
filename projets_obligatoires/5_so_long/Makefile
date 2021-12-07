# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 18:18:37 by roaraujo          #+#    #+#              #
#    Updated: 2021/12/07 02:07:01 by roaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PATH VARIABLES
HEADERS_PATH = ./headerfiles/
SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/
LIBS_PATH = ./libs/
BINS_PATH = ./bin/
LOGS_PATH = ./logs/
LEDGER = valgrind_logs.txt

# COMPILATION
CC = gcc
DEBUG = -g
FLAGS = -Wall -Wextra -Werror -O3 $(DEBUG)
VALGRIND = valgrind --leak-check=full \
			--show-leak-kinds=all \
			--track-origins=yes \
			-q \
			--log-file=$(LOGS_PATH)$(LEDGER)
# TODO: dar uma olhada aqui nessas flags dps: valgrind -q --leak-check=full --show-leak-kinds=all -s --track-fds=yes --trace-children=yes --error-exitcode=1 --track-origins=yes ./a.out
# TODO: refatorar o makefile pra parar de criar biblioteca libso_long
# TODO: refatorar makefile pra tirar a necessidade do main.c se pá e inclui a main() no so_long.c

# BASH COMMANDS
RM = rm -f
MKDIR = mkdir -p
MAKE_NOPRINT = $(MAKE) --no-print-directory
TOUCH = touch -a

# FILES
LIBNAME = libso_long.a
SRC_FILES = so_long.c \
			movement_utils.c \
			render_utils.c \
			render_utils_2.c \
			game_close_utils.c \
			game_init_utils.c \
			hooks_utils.c \
			map_validation_utils.c \
			other_utils.c
SOURCES = $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))
EXECUTABLE = so_long

# TARGETS
all: libft $(LIBNAME) main

# -> compiles libft all over
libft:
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT)

# -> creates static library libso_long.a inside ./libs/
$(LIBNAME): $(OBJECTS)
	@cp $(LIBS_PATH)libft.a $(LIBS_PATH)$(LIBNAME)
	@ar -rcs $(LIBS_PATH)$(LIBNAME) $(OBJECTS)

# -> creates object files for libso_long
$(OBJS_PATH)%.o : $(SRCS_PATH)%.c $(HEADERS_PATH)*.h
	@$(MKDIR) $(OBJS_PATH)
	@$(CC) $(FLAGS) -c $< -I $(HEADERS_PATH) -o $@ -lmlx

# -> mandatory flag for project submission
bonus: all

# RUN
# -> creates the executable file $(EXECUTABLE) to test development
main:	./main.c
	@$(MKDIR) $(BINS_PATH)
	@$(CC) $(CFLAGS) $< -L$(LIBS_PATH) -lso_long -lmlx -lXext -lX11 -I $(HEADERS_PATH) -o $(BINS_PATH)$(EXECUTABLE)

run: all
	@$(BINS_PATH)$(EXECUTABLE) ./resources/maps/map1.ber
	@$(MAKE_NOPRINT) fclean

valgrind: all
	@$(MKDIR) $(LOGS_PATH)
	@$(TOUCH) $(LOGS_PATH)$(LEDGER)
	@$(VALGRIND) $(BINS_PATH)$(EXECUTABLE) ./resources/maps/map1.ber

# SANITIZE
# -> deletes all .o files; also runs libft's clean target
clean:
	@$(RM) $(OBJECTS)

# -> deletes .o files + static library file + executable; also runs libft's fclean target
fclean: clean
	@$(RM) $(BINS_PATH)$(EXECUTABLE)
	@$(RM) $(LIBS_PATH)$(LIBNAME)

# -> 
re: fclean all

.PHONY: all run clean fclean re