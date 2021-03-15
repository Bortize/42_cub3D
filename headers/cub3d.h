/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:28:33 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/15 18:01:09 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "../printf/libft/libft.h"
# include "../printf/ft_printf.h"
# include "get_next_line.h"
# ifdef __APPLE__
#  include "keycode_mac.h"
# elif __linux__
#  include "keycode_linux.h"
# endif
# include <ctype.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <stdarg.h>

typedef struct	s_parse
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
	int			floor_conv;
	int			ceilling[3];
	int			flag_ceilling;
	int			ceilling_conv;
	char		**tab;
	char		**tabcf;
	int			flag_config_ready;
	int			start_map;
	int			end_map;
	int			count_sprites;
}				t_parse;
typedef	struct	s_map
{
	int			i;
	int			rows_size;
	char		*one_line_plan;
	size_t		row_len;
	char		**plan;
	char		**plan_tmp;
	int			values_ok;
	char		player_init_coor;
	double		player_init_position_x;
	double		player_init_position_y;
	char		*player_positon;
	char		boundary_value;
	char		fill_value;
	char		sprite_value;
}				t_map;

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;
/*
** Inicia todo lo necesario para que la mlx carge
** y funcione correctamente
*/
typedef struct	s_mlx
{
	void	*init;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_mlx;
/*
** Controles que afectan a la ventan y al juego
*/
typedef struct	s_controls
{
	int		esc;
	int		forward;
	int		sideways;
	int		rotate;
	double	olddirx;
	double	oldplanex;
}				t_controls;

typedef struct	s_player
{
	int		flag_found_player;
	int		count_found_player;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
}				t_player;

typedef struct	s_raycast
{
	int		x;
	int		y;
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	double	wallx;
	int		texnum;
}				t_raycast;

typedef struct	s_window
{
	int	lineheight;
	int	drawstart;
	int	drawend;
}				t_window;

typedef struct	s_texture
{
	void	*img_tex;
	int		*addr;
	int		bpp;
	int		endian;
	int		size_line;
	int		width;
	int		height;
}				t_texture;

typedef struct	s_textures
{
	t_texture	walls[4];
	t_texture	sprite[2];
}				t_textures;

typedef struct	s_raycalc
{
	double	step;
	double	pos;
	int		x;
	int		y;
}				t_raycalc;

typedef struct	s_sprite
{
	double		x;
	double		y;
	double		dist;
	t_texture	*tex;
}				t_sprite;

typedef struct	s_rcastsprite
{
	int		i;
	double	spritex;
	double	spritey;
	double	invdet;
	double	transformx;
	double	transformy;
	int		spritescreenx;
	int		spriteheight;
	int		drawstarty;
	int		drawendy;
	int		spritewidth;
	int		drawstartx;
	int		drawendx;
}				t_rcastsprite;
typedef struct	s_drawsprites
{
	int				i;
	int				y;
	int				d;
	int				texy;
	int				stripe;
	int				texx;
	unsigned int	color;
}				t_drawsprites;
/*
** This is the main structure of the program
*/
typedef struct	s_cub3d
{
	double			*zbuffer;
	t_parse			map;
	t_map			plan;
	t_mlx			mlx;
	t_controls		ctrl;
	t_raycast		rcast;
	t_player		p;
	t_window		win;
	t_textures		tex;
	t_rcastsprite	spr;
	t_sprite		*sprites;
	int				*spriteorder;
	int				bmp_flag;
}				t_cub3d;

void			initialize_mlx(t_cub3d *cub);
int				file_validation(char *str);
void			init_structures(t_cub3d *cub);
int				file_reading(int fd, t_cub3d *cub);
int				save_plane_lines(char *str, t_cub3d *cub);
int				find_identifiers(char *str, t_cub3d *cub);
int				assignment_identifiers_text_colour(t_cub3d *cub);
void			assignment_identifiers_colours(t_cub3d *cub);
void			assignment_identifiers_resolution(t_cub3d *cub);
void			validation_identifiers_ceilling(t_cub3d *cub);
void			validation_identifiers_floor(t_cub3d *cub);
int				integer_validation(t_cub3d *cub);
void			print_error(char *str);
int				integer_validation_resolution(t_cub3d *cub);
int				integer_validation_size(t_cub3d *cub);
void			path_validation(char *str);
void			screen_validation_r(t_cub3d *cub);
void			texture_validation_no(t_cub3d *cub);
void			texture_validation_so(t_cub3d *cub);
void			texture_validation_ea(t_cub3d *cub);
void			texture_validation_we(t_cub3d *cub);
void			texture_validation_s(t_cub3d *cub);
int				color_validation_ceilling(t_cub3d *cub);
int				color_validation_floor(t_cub3d *cub);
int				validate_plan(char *str, t_cub3d *cub);
void			init_plan_values(t_cub3d *cub);
int				check_identifiers(t_cub3d *cub);
void			check_characters_plane(char *str, t_cub3d *cub);
void			find_sprites(t_cub3d *cub);
void			check_allowed_values(char *str, t_cub3d *cub);
void			assigning_plane_values(t_cub3d *cub);
int				boundary_fill(int x, int y, t_cub3d *cub);
char			put_pixel(int x, int y, t_cub3d *cub);
void			graphic(t_cub3d *cub);
void			start_mlx(t_cub3d *cub);
void			load_textures(t_cub3d *cub);
void			load_wall_texture(t_cub3d *cub);
void			load_sprite_texture(t_cub3d *cub);
int				key_press(int keycode, t_cub3d *cub);
int				key_release(int keycode, t_cub3d *cub);
int				moving(t_cub3d *cub);
int				rotating(t_cub3d *cub);
void			raycast(t_cub3d *cub, int col);
void			raycast_init(t_cub3d *cub);
int				game(t_cub3d *cub);
void			my_mlx_pixel_put(t_cub3d *cub, int x, int y, int color);
void			set_plan_position(t_cub3d *cub, double x, double y);
void			move_forward(t_cub3d *cub);
void			move_sideways(t_cub3d *cub);
int				player_start_position(char *str, t_cub3d *cub);
void			where_player_look(t_cub3d *cub, char c);
void			movement(t_cub3d *cub);
void			set_plan_position(t_cub3d *cub, double x, double y);
void			move_forward(t_cub3d *cub);
void			move_sideways(t_cub3d *cub);
void			rotation(t_cub3d *cub);
void			refresh_screen(t_cub3d *cub);
void			draws_sky_floor(t_cub3d *cub, int x);
void			sort_sprites(t_cub3d *cub);
void			draw_sprites(t_cub3d *cub);
void			set_pixel(t_cub3d *cub, size_t pixel, int color);
void			refresh_screen(t_cub3d *cub);
int				screenshot(t_cub3d *cub);
void			step_and_initial_sidedist(t_cub3d *cub);
void			perfom_dda(t_raycast *rcast, t_map *plan);
void			init_raycast(t_cub3d *cub, int col);
void			distance_perp_ray(t_raycast *rcast, t_player *p);
void			low_hight_pixel(t_window *win, t_parse *map);
void			texture_calculations(t_raycast *rcast, t_player *p);
void			increase_draw_texture(t_cub3d *cub, t_raycalc ray, int col);
void			sprite_low_hight_pixel_fill(t_parse *map, t_rcastsprite *spr);
void			width_sprite(t_parse *map, t_rcastsprite *spr);
void			init_raycast_sprites(t_cub3d *cub, t_drawsprites drwspr);
void			vertical_stripe_sprite_screen(t_cub3d *cub,
					t_drawsprites drwspr);
char			**ft_split_map(char const *s, char c, int min_size);
void			free_array(char **array);
void			check_error_identifier(t_cub3d *cub);

#endif
