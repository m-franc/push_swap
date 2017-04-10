# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfranc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/10 11:20:45 by mfranc            #+#    #+#              #
#    Updated: 2017/04/10 14:44:39 by mfranc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
FLAGS = -Wall -Wextra -Werror -fsanitize=address
CC = clang $(FLAGS)
INC = ../../includes
LIBFT = ../../libft
INC_LIB = ../../libft/includes
ALL_INC = -I $(INC) -I $(INC_LIB)
SRCS = checker.c
OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean flcean re

all: $(NAME)

lib:
	@make -C $(LIBFT)

$(NAME): lib
	$(CC) -o $(NAME) $(SRCS) $(ALL_INC) -L $(LIBFT) -lftprintf

%.o: %.c
	$(CC) -o $@ -c $< $(ALL_INC)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
