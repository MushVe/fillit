# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/04 13:00:08 by cseguier          #+#    #+#              #
#    Updated: 2019/03/04 13:04:26 by cseguier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = libft/libft.a

FILE = check.c main.c normalize_tetri.c resolve.c read_file.c

INC = -I libft

SRC = $(FILE:%=%)

OBJ = $(FILE:%.c=objs/%.o)

FLAG = -Wall -Werror -Wextra

CC = gcc $(FLAG) $(INC)

RM = rm -f

all: $(NAME)

$(NAME) : $(LIB) $(OBJ)
		@$(CC) -o $@ $(OBJ) -L libft/ -lft

$(LIB) :
		@make -C libft/ all

objs/%.o: %.c
		@mkdir -p objs
		@$(CC) $(INC) -o $@ -c $<

clean:
		@$(RM) $(OBJ)
		@rm -df objs
		@make -C libft/ clean

fclean: clean
		@$(RM) $(NAME)
		@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
