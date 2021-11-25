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
LIBNAME = libso_long.a
SRC_FILES = so_long.c \
			movement_utils.c \
			render_utils.c \
			hooks_utils.c
SOURCES = $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))
EXECUTABLE = so_long

# TARGETS
all: libft $(LIBNAME)

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

run: all main
	@$(BINS_PATH)$(EXECUTABLE) ./resources/maps/map1.berr
	@$(MAKE_NOPRINT) fclean

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