# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfranc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/10 11:20:45 by mfranc            #+#    #+#              #
#    Updated: 2017/04/26 20:03:24 by mfranc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Wextra -Werror -fsanitize=address
CC = clang $(FLAGS)
INC = ../../includes
LIBFT = ../../libft/
INC_LIB = ../../libft/includes
ALL_INC = -I $(INC) -I $(INC_LIB)
SRCS = push_swap.c					\
	   ../ft_init_node.c			\
	   ../ft_putnode.c				\
	   ../ft_exit.c		\
	   ../ft_swap.c					\
	   ../ft_push.c					\
	   ../ft_init_ctl.c				\
	   ../ft_rotate.c				\
	   ../ft_reverse_rotate.c		\
	   ../ft_verif_pushswap.c		\
	   ft_list_to_inttab.c			\
	   ft_get_medstack.c

OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean flcean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(SRCS) $(ALL_INC) -L $(LIBFT) -lftprintf; mv $(NAME) ../../$(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(ALL_INC)

clean:
	@make clean -C $(LIBFT)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	rm -f ../../$(NAME)

re: fclean all
