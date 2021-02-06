/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:28:33 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/06 13:20:03 by bgomez-r         ###   ########.fr       */
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
# include <math.h>
# include <stdarg.h>

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
}				t_identifiers;//map

typedef	struct	s_map
{
	int			i;//
	int			rows_size;//				Guarda el numero de filas que contiene el plano del mapa
	char		*one_line_plan;//			Guarda todas las lineas del plano en unico string para poder trabajar mas facilmente
	size_t		row_len;//					Tamaño de las filas
	char		**plan;//					Matriz donde guardas el mapa
	int			values_ok;//
	double		player_init_position_x;//	Vector de posicion del jugador x (inicial)
	double		player_init_position_y;//	Vector de posicion del jugador y (inical )
	char		*player_positon;//			Matriz de posicion del jugador (para poder meter en sus indices init x e init y) no lo uliltizo
	char		boundary_value;//			Valor que se le da a los muros y que es utilizado en el funcion de validacion por inundacion '1'
	char		fill_value;//				Valor con el que se va a sustituir la baldosa en caso de que sea 0 en el algoritmo por inundacion 'f'
	char		sprite_value;//				Valor del sprite que tendremos en cuenta al uilizar el algoritmo por inundacion '2'
}				t_map;//plan

typedef struct	s_window
{
	void		*mlx;//				Puntero al motor gráfico
	void		*mlx_win;//			Puntero a la ventana
	void		*img;//				Puntero a la imagen "frame" que se genera en cada loop
	char 		*addr;//			Dirección a la imagen que se genera.
	int			line_length;//		Longitud del vector del plano de la camara?
	int			endian;//			Manera en la que se representan los bites dependiendo del sistema
	int			bpp;//				Bites por pixel
	double		player_pos_x;//		El vector de posicion del jugador.
	double		player_pos_y;//		El vector de posicion del jugador.
	double		player_dir_x;//		La direccion del jugador. Actualemnte se esta inicializando a capon en init_strucuture pero debe hacerse en funcion de a que coordenad mire el jugador.
	double		player_dir_y;//		La direccion del jugador.
	double		player_plane_x;//	Plano de la camara del jugador.
	double		player_plane_y;//	Plano de la camara del jugador.
	int			step_x;//			Dirección en la que el jugador tiene que anvanzar.
	int			step_y;//			Dirección en la que el jugador tiene que avanzar.
	double		ray_dir_x;//		Direccion del pixel del plano de la camara
	double		ray_dir_y;//		Direccion del pixel del plano de la camara
	double		camera_x;//			Coordenada 'x' en el plano de la camara que representa la actual coordenada 'x' de la pantalla
	int			map_x;//			Cuadrado actual del mapa donde se encuentra el rayo.
	int			map_y;//			Cuadrado actual del mapa donde se encuentra el rayo.
	double		side_dist_x;//		Distancia que el rayo tiene que recorrer desde su posicion inicial hasta el primer lado de 'x'
	double		side_dist_y;//		Distancia que el rayo tiene que recorrer desde su posicion inicial hasta el primer lado de 'y'
	double		delta_dist_x;//		Distancia que el rayo tiene que recorrer de 1 lado x al siguiente lado x.
	double		delta_dist_y;//		Distancia que el rayo tiene que recorrer de 1 lado x al siguiente lado x.
	int			side;//				Checkea que lado del muro se encuentra el rayo, si en el x o en el y
	int			hit;//				Checkea cuando el rayo ha impactado en el muro
	int			perp_wall_dist;//	Distancia perpendicular desde el punto de impacto de la pared al plano de la camara en vez de al jugador.
	int			draw_start;//
	int			draw_end;//
	int			line_height;//
}				t_window;//graphic

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
void	initial_calc(t_cub3d *cub, int x);
void	perform_dda(t_cub3d *cub);
void	calc_wall_height(t_cub3d *cub);
void	draw_vert_line(t_cub3d *cub, int x);
int 	handle_events(int key, t_cub3d *cub);
void	init_window(t_cub3d *cub);


#endif
