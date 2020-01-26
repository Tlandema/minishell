# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlandema <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 12:04:00 by tlandema          #+#    #+#              #
#    Updated: 2020/01/26 07:01:29 by tlandema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -g3 -Wall -Wextra -Werror

INC = includes

SRCS_PATH = srcs

SRCS = get_next_line.c \
	   ft_stristr.c \
	   ft_str_join.c \
	   ft_atoli.c \
	   ft_quicksort.c \
	   ft_last_char.c \
	   ft_split_white.c \
	   ft_join_tab.c \
	   ft_strjoinfree.c \
	   ft_count_tab.c \
	   ft_strrev.c \
	   ft_recursive_power.c \
	   ft_ftoa.c \
	   ft_big_putnbr.c \
	   ft_itoa_ubase.c \
	   ft_putnstr.c \
	   ft_strjoincut.c \
	   ft_str_is_digit.c \
	   ft_strndup.c \
	   ft_del_cont.c \
	   ft_lstswap.c \
	   ft_memset.c \
	   ft_tabdel.c \
	   ft_print_tab.c \
	   ft_lstlen.c \
	   ft_lstfind.c \
	   ft_lstnelem.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strlen.c \
	   ft_strdup.c \
	   ft_strcpy.c \
	   ft_strncpy.c \
	   ft_strcat.c \
	   ft_strncat.c \
	   ft_strlcat.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_strnstr.c \
	   ft_strcmp.c \
	   ft_strncmp.c \
	   ft_atoi.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_islower.c \
	   ft_isupper.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_strclr.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strsub.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_strtrim_char.c \
	   ft_strsplit.c \
	   ft_itoa.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_putendl.c \
	   ft_putnbr.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_lstnew.c \
	   ft_lstdelone.c \
	   ft_lstdel.c \
	   ft_lstadd.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_lstapp.c \

OBJS_PATH = obj

OBJS = $(SRCS:.c=.o)

D_OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS))

.PHONY: all clean fclean re
.SILENT:

GREEN       = \033[0;32m
RED         = \033[0;31m
RESET       = \033[0m

#STRINGS
BIN_STRING  = Binary
DEL_STRING  = Deleted.
CREA_STRING = Created.
COM_STRING  = Compiled.

all: $(NAME)

$(NAME): $(INC) $(D_OBJS)
	ar -rc $(NAME) $(D_OBJS)
	ranlib $(NAME)
	printf "%-20b%-60b%b" "$(NAME):" "$(GREEN)$@" "$(COM_STRING)$(RESET)\n"

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(INC)
	printf "%-20b%-60b%b" "$(NAME):" "$(GREEN)$@" "$(CREA_STRING)$(RESET)\r"

clean:
	rm -f $(D_OBJS)
	printf "%-20b%-60b%b" "$(NAME):" "$(RED)$(BIN_STRING)" "$(DEL_STRING)$(RESET)\n"

fclean: clean
	rm -f $(NAME)
	printf "%-20b%-60b%b" "$(NAME):" "$(RED)$(OBJS_PATH)" "$(DEL_STRING)$(RESET)\n"

re: fclean all
