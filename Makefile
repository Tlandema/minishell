# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlandema <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 12:04:00 by tlandema          #+#    #+#              #
#    Updated: 2020/01/26 07:06:39 by tlandema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
BINARY = $(NAME)

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror -I./includes -I./libft/includes

LIB = libft.a

LIB_PATH = libft

INC = includes

SRCS_PATH = srcs

SRCS =	cd.c \
		echo.c \
		envs.c \
		main.c \
		term.c \
		loop.c \
		utils.c \
		cursor.c \
		prompt.c \
		signals.c \
		dollars.c \
		command.c \
		memoline.c \
		tab_builder.c \
		line_editor.c \
		print_error.c \
		autocomplete.c \
		free_functions.c \

OBJS_PATH = obj

D_LIB = $(addprefix $(LIB_PATH)/, $(LIB))

OBJS = $(SRCS:.c=.o)

D_OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS))

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

BIN_STRING  = Binary
DEL_STRING = Deleted.
CREA_STRING = Created.
COM_STRING = Compiled.

.PHONY: all fcean clean re
.SILENT:

all: $(NAME)

$(NAME): $(INC) $(D_OBJS) $(D_LIB)
	$(CC) $(CFLAGS) -ltermcap -o $(NAME) -I$(INC) $(D_OBJS) -L./$(LIB_PATH) -lft
	printf "%-20b%-60b%b" "$(BINARY):" "$(GREEN)$(BIN_STRING)" "$(COM_STRING)$(RESET)\n"

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(LIB_PATH)
	printf "%-20b%-60b%b" "$(BINARY):" "$(GREEN)$@" "$(CREA_STRING)$(RESET)\r"

$(D_LIB) :
	@make -C libft

clean:
	rm -f $(D_OBJS) && make clean -C libft
	printf "%-20b%-60b%b" "$(BINARY):" "$(RED)$(OBJS_PATH)" "$(DEL_STRING)$(RESET)\n"

fclean: clean
	rm -f $(NAME) && rm -f libft/libft.a
	printf "%-20b%-60b%b" "$(BINARY):" "$(RED)$(BIN_STRING)" "$(DEL_STRING)$(RESET)\n"

re: fclean all
