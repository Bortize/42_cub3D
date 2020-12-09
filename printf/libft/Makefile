# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/04 17:38:10 by bgomez-r          #+#    #+#              #
#    Updated: 2020/10/05 11:56:57 by bgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FUNCTIONS = ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_tolower.c \
			ft_memcmp.c ft_toupper.c ft_isalpha.c ft_isascii.c ft_strlen.c ft_strlcat.c \
			ft_strcpy.c ft_strlcpy.c ft_strjoin.c ft_strnstr.c ft_strncmp.c ft_strdup.c \
			ft_strchr.c ft_strrchr.c ft_strtrim.c ft_strmapi.c ft_split.c ft_isdigit.c \
			ft_isalnum.c ft_isprint.c ft_calloc.c ft_substr.c ft_strcpy.c ft_putstr_fd.c \
			ft_putchar_fd.c ft_putendl_fd.c ft_bzero.c ft_atoi.c ft_itoa.c ft_putnbr_fd.c \
			ft_putchar.c

FBONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

OBJ = ${FUNCTIONS:.c=.o}

OBJBONUS = ${FBONUS:.c=.o}

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME):
		${CC} ${FLAGS} -c ${FUNCTIONS}
		ar rc ${NAME}	${OBJ}
		ranlib ${NAME}

bonus:
		${CC} ${FLAGS} -c ${FUNCTIONS} ${FBONUS}
		ar rc ${NAME}	${OBJ} ${OBJBONUS}
		ranlib ${NAME}

clean:
		rm -f ${OBJ} ${OBJBONUS}

fclean: clean
		rm -f ${NAME}

re: fclean ${NAME}

.PHONY: all clean fclean re
