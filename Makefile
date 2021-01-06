# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 13:28:42 by bgomez-r          #+#    #+#              #
#    Updated: 2021/01/05 23:31:35 by bgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################	Special Targets	####################################
# Elimina cualquier residuo que se haya podidio generar en la compilacion si algo fallo
.DELETE_ON_ERROR:
# Silencia todas las salidas por pantalla
.SILENT:
# Variable para indicar el nombre de nuestro programa
#########################	Program Name	####################################
NAME		= cub3D

#########################	Function Files	####################################

SRCS		=	srcs/main.c \
				srcs/window/initialize_mlx.c \
				srcs/error/print_error.c \
				srcs/validation/read_file/file_reading.c \
				srcs/validation/read_file/init_identifiers.c \
				srcs/validation/read_file/get_next_line.c \
				srcs/validation/read_file/get_next_line_utils.c \
				srcs/validation/read_file/file_validation.c \
				srcs/validation/identifiers/identifiers_search/find_identifiers.c \
				srcs/validation/identifiers/identifiers_search/check_identifiers.c \
				srcs/validation/identifiers/identifiers_search/assignment_identifiers.c \
				srcs/validation/identifiers/identifiers_validation/path_validation.c \
				srcs/validation/identifiers/identifiers_validation/validation_ceilling_floor.c \
				srcs/validation/identifiers/identifiers_validation/integer_validation.c \
				srcs/validation/identifiers/identifiers_validation/integer_validation_size.c \
				srcs/validation/identifiers/identifiers_validation/screen_validation_r.c \
				srcs/validation/identifiers/identifiers_validation/texture_validation_no.c \
				srcs/validation/identifiers/identifiers_validation/texture_validation_so.c \
				srcs/validation/identifiers/identifiers_validation/texture_validation_ea.c \
				srcs/validation/identifiers/identifiers_validation/texture_validation_we.c \
				srcs/validation/identifiers/identifiers_validation/texture_validation_s.c \
				srcs/validation/identifiers/identifiers_validation/color_validation_ceilling.c \
				srcs/validation/identifiers/identifiers_validation/color_validation_floor.c \
				srcs/validation/map/save_plane_lines.c \
				srcs/validation/map/assigning_plane_values.c \
				srcs/validation/map/check_characters_plane.c \
				srcs/validation/map/map_plane_walls.c \
				srcs/validation/map/validate_plan.c \
				srcs/validation/map/player_start_position.c \
				srcs/validation/map/boundary_validation/boundary_validation.c \
				srcs/validation/map/boundary_validation/put_pixel.c \

############################	Variables	####################################

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g #-fsanitize=address -w

MLXFLAG		= -lmlx -framework OpenGL -framework AppKit -lm

OBJS		= $(SRCS:.c=.o)

INCLUDE		= ./printf

INCLUDE2	= ./minilibx_opengl

RM 			= rm -rf

##########################	Rules	############################################

all:		$(NAME)

$(NAME):	$(INCLUDE) $(OBJS)
				# Compila el Makefile que esta en la ruta ./printf
				make -C $(INCLUDE)
				# Compila el Makefile que esta en la ruta ./minilibx_opengl
				make -C $(INCLUDE2)
				# Copia las librerias generadas en cada ruta y las sube a este nivel
				cp ./printf/libftprintf.a ./
				cp ./minilibx_opengl/libmlx.a ./
				# Compila usando los flags, las librerías y todos los archivos objeto para finalmente generar el programa
				@$(CC) $(CFLAGS) $(MLXFLAG) -L. libftprintf.a libmlx.a $(OBJS) -o cub3D

###############################################################################

clean:
			$(RM) $(OBJS) a.out
			make -C $(INCLUDE) clean
			make -C $(INCLUDE2) clean

fclean:		clean
				$(RM) -f $(NAME)
				make -C $(INCLUDE) fclean
				$(RM) *.a leaks.txt

re:			fclean all

run:	re
			 ./cub3D map_test/valid_maps/valid_map_area_000.cub

##########################	Rules Phony	 #######################################

.PHONY:		all clean flcean re
