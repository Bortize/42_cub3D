# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 13:28:42 by bgomez-r          #+#    #+#              #
#    Updated: 2021/03/15 13:27:10 by bgomez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################	Special Targets	###################################
# If the compilation fails, remove any residue generated.
.DELETE_ON_ERROR:
# Mutes all outputs per screen
#.SILENT:
#########################	Program Name	###################################
# Variable to indicate the name of our program
NAME		= cub3D

#########################	Function Files	###################################

SRCS		=	srcs/main.c \
				srcs/free_array.c \
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
				srcs/validation/identifiers/identifiers_validation/check_error_identifier.c \
				srcs/validation/map/save_plane_lines.c \
				srcs/validation/map/assigning_plane_values.c \
				srcs/validation/map/check_characters_plane.c \
				srcs/validation/map/find_sprites.c \
				srcs/validation/map/validate_plan.c \
				srcs/validation/map/player_start_position.c \
				srcs/validation/map/where_player_look.c \
				srcs/validation/map/boundary_validation/boundary_validation.c \
				srcs/validation/map/boundary_validation/put_pixel.c \
				srcs/validation/map/ft_split_map.c \
				srcs/window/graphic.c \
				srcs/window/start_mlx.c \
				srcs/window/load_textures.c \
				srcs/window/load_wall_texture.c \
				srcs/window/load_sprite_texture.c \
				srcs/window/controls.c \
				srcs/window/movement.c \
				srcs/window/my_mlx_pixel_put.c \
				srcs/window/rotation.c \
				srcs/window/player_movement.c \
				srcs/window/raycast.c \
				srcs/window/draw_sky_floor.c \
				srcs/window/game.c \
				srcs/window/sort_sprites.c \
				srcs/window/set_pixel.c \
				srcs/window/refresh_screen.c \
				srcs/window/screenshot.c \
				srcs/window/step_and_initial_sidedist.c \
				srcs/window/perfom_dda.c \
				srcs/window/init_raycast.c \
				srcs/window/distance_perp_ray.c \
				srcs/window/low_hight_pixel.c \
				srcs/window/texture_calculations.c \
				srcs/window/increase_draw_texture.c \
				srcs/window/sprite_low_hight_pixel_fill.c \
				srcs/window/width_sprite.c \
				srcs/window/init_raycast_sprites.c \
				srcs/window/vertical_stripe_sprite_screen.c

############################	Variables	###################################

CC				= gcc

INCLUDES		= -Iheaders -I$(FTPRINTF_PATH) -I$(MLX_PATH)

CFLAGS			= -Wall -Wextra -Werror -w -O3 $(INCLUDES)

OS				= $(shell uname)

ifeq ($(OS), Linux)
  MLXFLAGS		= -lX11 -lz -lXext
else ifeq ($(OS), Darwin)
  MLXFLAGS		= -framework OpenGL -framework AppKit
endif

LIB_COMMON		= $(MLXFLAGS) -lm -L$(FTPRINTF_PATH) -L$(MLX_PATH) -l$(FTPRINTF_NAME) -l$(MLX_NAME)

OBJS			= $(SRCS:.c=.o)

FTPRINTF_PATH	= printf
FTPRINTF_NAME	= ftprintf
FTPRINTF_FILE	= $(FTPRINTF_PATH)/lib$(FTPRINTF_NAME).a

MLX_PATH		= minilibx_$(OS)
MLX_NAME		= mlx
MLX_FILE		= $(MLX_PATH)/lib$(MLX_NAME).a

RM				= rm -rf

##########################	Rules	###########################################

all:		$(NAME)

$(NAME):	$(OBJS) $(FTPRINTF_FILE) $(MLX_FILE)
				$(CC) $(OBJS) -o cub3D $(CFLAGS) $(LIB_COMMON)

##############################################################################

clean:
			$(RM) $(OBJS) $(OBJS_DIR)
			make -C $(FTPRINTF_PATH) clean
			make -C $(MLX_PATH) clean

fclean:		clean
			$(RM) -f $(NAME)
			make -C $(FTPRINTF_PATH) fclean
			$(RM) *.a leaks.txt

re:			fclean all

$(MLX_FILE):
			make -C $(MLX_PATH)

$(FTPRINTF_FILE):
			make -C $(FTPRINTF_PATH)

debug:	CFLAGS += -O3 -g3 #-fsanitize=address system("leaks -fullContent cub3D");
debug:	$(NAME)

run:	$(NAME)
			./cub3D tester/valid_maps/valid_map_area_001.cub

##########################	Rules Phony	 #######################################

.PHONY:		all clean flcean re debug
