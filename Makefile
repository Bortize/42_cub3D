# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 13:28:42 by bgomez-r          #+#    #+#              #
#    Updated: 2020/12/13 17:56:45 by bgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:

.SILENT:

NAME 		= cub3D

###############################################################################

SRCS		=	srcs/get_next_line.c \
				srcs/get_next_line_utils.c \
				srcs/file_validation.c \
				srcs/read_map.c \
				srcs/init_identifier.c \
				srcs/find_identifier.c \
				srcs/assignment_identifiers.c \
				srcs/main.c

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g

OBJS		= $(SRCS:.c=.o)

INCLUDE		= ./printf

RM 			= rm -rf

###############################################################################

all:		$(NAME)

$(NAME):	$(INCLUDE) $(OBJS)
				make -C $(INCLUDE)
				cp ./printf/libftprintf.a ./
				@$(CC) $(CFLAGS) -L. libftprintf.a $(OBJS) -o cub3D

###############################################################################

clean:
			$(RM) $(OBJS) a.out
			make -C $(INCLUDE) clean

fclean:		clean
				$(RM) -f $(NAME)
				make -C $(INCLUDE) fclean
				$(RM) *.a

re:			fclean all

run:	re
			 ./cub3D valid_map_area_000.cub

###############################################################################

.PHONY:		all clean flcean re
