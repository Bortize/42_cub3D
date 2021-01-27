/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:28:33 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/27 19:04:12 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB3D_H
# define CUB3D_H

# include "../printf/libft/libft.h"
# include "../printf/ft_printf.h"
# include "get_next_line.h"
# include "../minilibx_opengl/mlx.h"
# include "keycode_mac.h"
# include <ctype.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_identifiers
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
}				t_identifiers;

typedef	struct	s_map
{
	int			i;
	int			rows_size;
	char		*one_line_plan;
	size_t		row_len;// Tamaño de las filas
	char		**plan;// Matriz donde guardas el mapa
	int			values_ok;
	double		player_position_x;
	double		player_position_y;
	char		*player_positon;
	char		boundary_value;
	char		fill_value;
	char		sprite_value;
}				t_map;

typedef struct	s_window
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char 		*addr;
	int			line_length;
	int			endian;
	void		*img_ptr;
	int			bpp;
	double		player_dir_x;
	double		player_dir_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		player_plane_x;
	double		player_plane_y;
}				t_window;

typedef struct	s_cub3d
{
	t_identifiers	map;
	t_map			plan;
	t_window		graphic;
}				t_cub3d;

void	initialize_mlx(t_cub3d *cub);
int		file_validation(char *str);
void	init_structures(t_cub3d *cub);
int		file_reading(int fd, t_cub3d *cub);
int		save_plane_lines(char *str, t_cub3d *cub);
int		find_identifiers(char *str, t_cub3d *cub);
int		assignment_identifiers_text_colour(t_cub3d *cub);
void	assignment_identifiers_colours(t_cub3d *cub);
void	assignment_identifiers_resolution(t_cub3d *cub);
void	validation_identifiers_ceilling(t_cub3d *cub);
void	validation_identifiers_floor(t_cub3d *cub);
int		integer_validation(t_cub3d *cub);
void	print_error(char *str);
int		integer_validation_resolution(t_cub3d *cub);
int		integer_validation_size(t_cub3d *cub);
int		path_validation(char *str);
void	screen_validation_r(t_cub3d *cub);
void	texture_validation_no(t_cub3d *cub);
void	texture_validation_so(t_cub3d *cub);
void	texture_validation_ea(t_cub3d *cub);
void	texture_validation_we(t_cub3d *cub);
void	texture_validation_s(t_cub3d *cub);
int		color_validation_ceilling(t_cub3d *cub);
int		color_validation_floor(t_cub3d *cub);
int		validate_plan(char *str, t_cub3d *cub);
void	init_plan_values(t_cub3d *cub);
int		check_identifiers(t_cub3d *cub);
void	check_characters_plane(char *str, t_cub3d *cub);
void	check_allowed_values(char *str, t_cub3d *cub);
void	assigning_plane_values(t_cub3d *cub);
void	check_line_by_line(t_cub3d *cub);
void	boundary_fill(int x, int y, int fill_value, int boundary_value, t_cub3d *cub);
int		player_start_position(char *str, t_cub3d *cub);
char	put_pixel(int x, int y, t_cub3d *cub);
void	my_mlx_pixel_put(t_cub3d *cub, int x, int y, int color);
int		keypress(int keycode, t_cub3d *cub);
int		draws_sky_floor(t_cub3d *cub);
int		raycasting(t_cub3d *cub);

#endif
