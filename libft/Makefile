# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 15:28:47 by ablanco-          #+#    #+#              #
#    Updated: 2023/03/22 18:43:40 by ablanco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
GNL		= ./gnl
PF		= ./printf

SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c  ft_strlcpy.c \
		  ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
		  ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		  ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		  \
		  ./gnl/get_next_line.c ./gnl/get_next_line_utils.c ./gnl/get_next_line_bonus.c ./gnl/get_next_line_utils_bonus.c \
		  \
		  $(PF)/ft_printf.c $(PF)/ft_putnbr.c $(PF)/funciones.c \
		  ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		  ft_lstmap.c ft_lstnew.c ft_lstadd_front.c 

OBJS	= ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS:.c=.o}


CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

all:	${NAME}


${NAME}:	${OBJS}
			make -C $(PF)
			ar -rc ${NAME} ${OBJS}

clean:
		@${RM} ${OBJS} ${BONUS_OBJS}
		make -C $(PF) clean
		@echo "Borrando objetos"

fclean:	clean
		${RM} ${NAME}
		make -C $(PF) fclean

re:	fclean all

bonus: ${BONUS_OBJS}
		@ar -rc ${NAME} ${BONUS_OBJS}

.PHONY:	all clean fclean re bonus
