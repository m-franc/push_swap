# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfranc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/10 11:20:45 by mfranc            #+#    #+#              #
#    Updated: 2017/05/01 11:46:22 by mfranc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
FLAGS = -Wall -Wextra -Werror -fsanitize=address
CC = clang $(FLAGS)
INC = ../../includes
LIBFT = ../../libft/
INC_LIB = ../../libft/includes
ALL_INC = -I $(INC) -I $(INC_LIB)
SRCS = checker.c					\
	   ../ft_init_node.c			\
	   ../ft_init_link.c			\
	   ../ft_putnode.c				\
	   ../ft_putnode_single.c		\
	   ../ft_exit.c					\
	   ../ft_swap.c					\
	   ../ft_push.c					\
	   ../ft_init_ctl.c				\
	   ../ft_rotate.c				\
	   ../ft_reverse_rotate.c		\
	   ../ft_is_sort.c

OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean flcean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o $@ $(ALL_INC) -L $(LIBFT) -lftprintf

%.o: %.c
	$(CC) -o $@ -c $< $(ALL_INC)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
