# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 18:45:05 by ablanco-          #+#    #+#              #
#    Updated: 2023/04/02 14:10:35 by ablanco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC		=	main.c swap.c

OBJS	= $(SRC:.c=.o)
LIB		= 	./libft

CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g3 -fsanitize=address

RM		= rm -f

all:	$(NAME) libft

$(NAME):	$(OBJS)
			make -C $(LIB)
			$(CC) $(OBJS) $(CFLAGS) $(LIB)/libft.a -o $(NAME)

exe:
		./$(NAME)
clean:
		$(RM) $(OBJS)
		make -C $(LIB) clean
fclean:	clean
		$(RM) $(NAME)
		make -C $(LIB) fclean
re:	fclean all

.PHONY: clean exe fclean re all
