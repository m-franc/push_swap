# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfranc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/18 16:54:20 by mfranc            #+#    #+#              #
#    Updated: 2017/04/18 19:14:07 by mfranc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/
PUSHSWAP = srcs/srcs_ps/
CHECKER = srcs/srcs_ck/

all: name

lib:
	make -C $(LIBFT)

name: lib
	make -C $(PUSHSWAP)
	make -C $(CHECKER)

clean:
	make clean -C $(LIBFT)
	make clean -C $(PUSHSWAP)
	make clean -C $(CHECKER)

fclean: clean
	make fclean -C $(LIBFT)
	make fclean -C $(PUSHSWAP)
	make fclean -C $(CHECKER)

re: fclean all
