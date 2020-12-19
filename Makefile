# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 13:28:42 by bgomez-r          #+#    #+#              #
#    Updated: 2020/12/19 19:40:58 by bgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:

.SILENT:

NAME 		= cub3D

###############################################################################

SRCS		=	srcs/validation_identifiers/open_read/get_next_line.c \
				srcs/validation_identifiers/open_read/get_next_line_utils.c \
				srcs/validation_identifiers/open_read/file_validation.c \
				srcs/validation_identifiers/open_read/read_map.c \
				srcs/validation_identifiers/open_read/init_identifier.c \
				srcs/validation_identifiers/search_identifiers/find_identifier.c \
				srcs/validation_identifiers/search_identifiers/assignment_identifiers.c \
				srcs/validation_identifiers/search_identifiers/validation_identifiers.c \
				srcs/validation_identifiers/search_identifiers/integer_validation.c \
				srcs/error/print_error.c \
				srcs/validation_identifiers/search_identifiers/integer_validation_size.c \
				srcs/validation_identifiers/search_identifiers/path_validation.c \
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
