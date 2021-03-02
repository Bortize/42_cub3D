# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 13:28:42 by bgomez-r          #+#    #+#              #
#    Updated: 2021/03/02 19:20:13 by bgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################	Special Targets	####################################
# Elimina cualquier residuo que se haya podidio generar en la compilacion si algo fallo
.DELETE_ON_ERROR:
# Silencia todas las salidas por pantalla
#.SILENT:
# Variable para indicar el nombre de nuestro programa
#########################	Program Name	####################################
NAME		= cub3D

#########################	Function Files	####################################

SRCS		=	srcs/main.c \
				srcs/window/initialize_mlx.c \
				srcs/error/print_error.c \
				srcs/validation/read_file/file_reading.c \
				srcs/validation/read_file/init_structures.c \
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
				srcs/validation/map/validate_plan.c \
				srcs/validation/map/player_start_position.c \
				srcs/validation/map/where_player_look.c \
				srcs/validation/map/boundary_validation/boundary_validation.c \
				srcs/validation/map/boundary_validation/put_pixel.c \
				srcs/window/my_mlx_pixel_put.c \
				srcs/window/raycasting/draws_sky_floor.c \
				srcs/window/keypress.c \
				srcs/window/raycasting/raycasting.c \
				srcs/window/raycasting/movement.c \
				srcs/window/raycasting/controls.c \
				srcs/window/raycasting/rotation.c \
				srcs/window/raycasting/player.c \
				srcs/window/raycasting_sprites/sprites.c \
				srcs/window/load_textures.c \
				srcs/window/raycasting/game.c


############################	Variables	####################################

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g3 -Iheaders -fsanitize=address -w

MLXFLAG		= -lmlx -framework OpenGL -framework AppKit -lm

OBJS		= $(SRCS:.c=.o)

OBJS_DIR= ./objs_dir

INCLUDE		= ./printf

INCLUDE2	= ./minilibx_opengl

RM 			= rm -rf

##########################	Rules	############################################

all:		$(NAME)

$(NAME):	$(INCLUDE) $(OBJS)
				# Llama al Makefile que esta en la ruta ./printf
				make -C $(INCLUDE)
				# Llama al Makefile que esta en la ruta ./minilibx_opengl
				make -C $(INCLUDE2)
				# Compila usando los flags, las librerías y todos los archivos objeto para finalmente generar el programa
				$(CC) $(CFLAGS) $(MLXFLAG) -L${INCLUDE} -L${INCLUDE2} -lftprintf -lmlx $(OBJS) -o cub3D
				# Borra el directorio si existiera. Se hace porque si existe da problemas
				rm -Rf ./objs_dir
				# Crea el directorio objs_dir donde guardara todos los objetos generados
				mkdir objs_dir
				# Mueve todos los objetos generados al directorio que creamos en el paso anterior
				mv $(OBJS) $(OBJS_DIR)

###############################################################################

clean:
			$(RM) $(OBJS) $(OBJS_DIR) a.out
			make -C $(INCLUDE) clean
			make -C $(INCLUDE2) clean

fclean:		clean
				$(RM) -f $(NAME)
				make -C $(INCLUDE) fclean
				$(RM) *.a leaks.txt

re:			fclean all

run:	clean
			make
			 ./cub3D tester/valid_map_area_000.cub

##########################	Rules Phony	 #######################################

.PHONY:		all clean flcean re
