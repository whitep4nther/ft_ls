# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsautron <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/07/18 01:20:28 by bsautron          #+#    #+#              #
#    Updated: 2014/12/04 17:42:09 by ihermell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME	= ft_ls
SRCS	= init.c print.c print_file.c filter.c parse.c ft_ls.c error.c \
		  tools.c more_list.c list.c dir.c file.c data_lst.c sort.c \
		  more_print_file.c more_print.c extended_attr.c permissions.c \
		  more_sort.c columns.c moar_list.c hack.c
OBJS	= $(SRCS:.c=.o)
FLAGS	= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@/bin/echo -n "=== LIBFT ==="
	@make -C libft/ re
	@/bin/echo -n "Compilation >>     "
	@gcc -I./libft/includes/ -L./libft/ -lft $(FLAGS) -o $(NAME) $(SRCS)
	@echo "OK!"

clean:
	@/bin/echo -n "Clean OBJS >>      "
	@rm -f $(OBJS)
	@echo "DONE :)"

fclean: clean
	@/bin/echo -n "Clean ft_ls >>     "
	@rm -f $(NAME)
	@echo "SWIFT"

re: fclean all
