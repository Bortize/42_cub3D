# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 13:28:42 by bgomez-r          #+#    #+#              #
#    Updated: 2020/12/24 19:49:32 by bgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:

.SILENT:

NAME 		= cub3D

###############################################################################

SRCS		=	srcs/main.c \
				srcs/error/print_error.c \
				srcs/validation/read_file/file_reading.c \
				srcs/validation/read_file/init_identifiers.c \
				srcs/validation/read_file/get_next_line.c \
				srcs/validation/read_file/get_next_line_utils.c \
				srcs/validation/read_file/file_validation.c \
				srcs/validation/identifiers_search/find_identifiers.c \
				srcs/validation/identifiers_search/check_identifiers.c \
				srcs/validation/identifiers_search/assignment_identifiers.c \
				srcs/validation/identifiers_validation/path_validation.c \
				srcs/validation/identifiers_validation/validation_ceilling_floor.c \
				srcs/validation/identifiers_validation/integer_validation.c \
				srcs/validation/identifiers_validation/integer_validation_size.c \
				srcs/validation/identifiers_validation/screen_validation_r.c \
				srcs/validation/identifiers_validation/texture_validation_no.c \
				srcs/validation/identifiers_validation/texture_validation_so.c \
				srcs/validation/identifiers_validation/texture_validation_ea.c \
				srcs/validation/identifiers_validation/texture_validation_we.c \
				srcs/validation/identifiers_validation/texture_validation_s.c \
				srcs/validation/identifiers_validation/color_validation_ceilling.c \
				srcs/validation/identifiers_validation/color_validation_floor.c \
				srcs/validation/map/check_characters.c \
				srcs/validation/map/validate_plan.c

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g #-fsanitize=address

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
