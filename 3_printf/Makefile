# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 18:03:20 by roaraujo          #+#    #+#              #
#    Updated: 2021/10/12 13:53:54 by roaraujo         ###   ########.fr        #
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
MAKE_NOPRINT = $(MAKE) --no-print-directory

# FILES
LIBNAME = libftprintf.a
SRC_FILES = ft_printf.c \
			ft_printf_print_utils_1.c \
			ft_printf_print_utils_2.c
SOURCES = $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))
EXECUTABLE = ft_printf_test

# TARGETS
all: libft $(LIBNAME)

# -> compiles libft all over
libft:
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT)

# -> creates static library libftprintf.a inside ./libs/
$(LIBNAME): $(OBJECTS)
	@cp $(LIBS_PATH)libft.a $(LIBS_PATH)$(LIBNAME)
	@ar -rcs $(LIBS_PATH)$(LIBNAME) $(OBJECTS)

# -> creates object files for ft_printf (libftprintf)
$(OBJS_PATH)%.o : $(SRCS_PATH)%.c $(HEADERS_PATH)*.h
	@$(MKDIR) $(OBJS_PATH)
	@$(CC) $(FLAGS) -c $< -I $(HEADERS_PATH) -o $@

# -> mandatory flag for project submission
bonus: all

# RUN
# -> creates the executable file $(EXECUTABLE) to test development
main:	./main.c
	@$(MKDIR) $(BINS_PATH)
	@$(CC) $(CFLAGS) $< $(LIBS_PATH)$(LIBNAME) -I $(HEADERS_PATH) -o $(BINS_PATH)$(EXECUTABLE)

run: all main
	@$(BINS_PATH)$(EXECUTABLE)
	@$(MAKE_NOPRINT) fclean

# SANITIZE
# -> deletes all .o files; also runs libft's clean target
clean:
	@$(RM) $(OBJECTS)
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT) $@

# -> deletes .o files + static library file + executable; also runs libft's fclean target
fclean: clean
	@$(RM) $(BINS_PATH)$(EXECUTABLE)
	@$(RM) $(LIBS_PATH)$(LIBNAME)
	@cd $(LIBS_PATH)libft && $(MAKE_NOPRINT) $@

# -> 
re: fclean all

.PHONY: all run clean fclean re