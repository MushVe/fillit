# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: czhang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 19:51:13 by czhang            #+#    #+#              #
#    Updated: 2019/02/22 14:34:45 by czhang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = libft/libft.a

FILE = check.c\
	   main.c\
	   move_coord.c\
	   coord.c\
	   tetrimino.c\
	   resolve.c\
	   read_file.c\
	   print.c

INC = -I libft/includes

SRC = $(FILE:%=%)

OBJ = $(FILE:%.c=objs/%.o)

FLAG = #-Wall -Werror -Wextra

CC = gcc $(FLAG) $(INC)

RM = rm -f

all: $(NAME)

$(NAME) : $(LIB) $(OBJ)
	$(CC) -o $@ $(OBJ) -L libft/ -lft

$(LIB) :
	make -C libft/ all

objs/%.o: %.c
	@mkdir -p objs
	$(CC) $(INC) -o $@ -c $<

test:
	gcc check.c coord.c tetrimino.c read_file.c ../main.c $(LIB)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
