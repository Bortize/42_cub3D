/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:28:33 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/11 12:28:20 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB3D_H
# define CUB3D_H

# include "../printf/libft/libft.h"
# include "../printf/ft_printf.h"
# include "get_next_line.h"
# include "../minilibx_opengl/mlx.h"
# include <ctype.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct	config
{
	int			i;
	int			width;
	int			flag_widht;
	int			height;
	int			flag_height;
	char		*no;
	int			flag_no;
	char		*so;
	int			flag_so;
	char		*ea;
	int			flag_ea;
	char		*we;
	int			flag_we;
	char		*s;
	int			flag_s;
	int			floor[3];
	int			flag_floor;
	int			ceilling[3];
	int			flag_ceilling;
	char		**tab;
	char		**tabcf;
	int			flag_map_ready;
}								map_config;

typedef	struct	valid_map
{
	int			i;
	int			rows_size;
	char		*one_line_plan;
	size_t	row_len;
	char		**plan;// Matriz
	int			values_ok;
	int			player_position_x;
	int			player_position_y;
	char		*player_positon;
	char		boundary_value;
	char		fill_value;
	char		sprite_value;
}								map_plan;

void	initialize_mlx(map_config *map);
int		file_validation(char *str);
void	init_identifiers(map_config *map);
int		file_reading(int fd, map_config *map, map_plan *plan);
int		save_plane_lines(char *str, map_plan *plan);
int		file_reading_map(int fd, map_config *map, map_plan *plan);
int		find_identifiers(char *str, map_config *map);
int		assignment_identifiers_text_colour(map_config *map);
void	assignment_identifiers_colours(map_config *map);
void	assignment_identifiers_resolution(map_config *map);
void	validation_identifiers_ceilling(map_config *map);
void	validation_identifiers_floor(map_config *map);
int		integer_validation(map_config *map);
void	print_error(char *str);
int		integer_validation_resolution(map_config *map);
int		integer_validation_size(map_config *map);
int		path_validation(char *str);
void	screen_validation_r(map_config *map);
void	texture_validation_no(map_config *map);
void	texture_validation_so(map_config *map);
void	texture_validation_ea(map_config *map);
void	texture_validation_we(map_config *map);
void	texture_validation_s(map_config *map);
int		color_validation_ceilling(map_config *map);
int		color_validation_floor(map_config *map);
int		validate_plan(char *str, map_plan *plan);
void	init_plan_values(map_plan *plan);
int		check_identifiers(map_config *map);
void	check_characters_plane(char *str, map_plan *plan);
void	check_allowed_values(char *str, map_plan *plan);
void	assigning_plane_values(map_plan *plan);
void	check_line_by_line(map_plan *plan);
void	boundary_fill(int x, int y, int fill_value, int boundary_value, map_plan *plan);
int		player_start_position(char *str, map_plan *plan);
char	put_pixel(int x, int y, map_plan *plan);

#endif
