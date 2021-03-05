/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:28:33 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/05 14:58:58 by bgomez-r         ###   ########.fr       */
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
	int			flag_map_ready;
	int			count_sprites;
}				t_parse;//map
typedef	struct	s_map
{
	int			i;//
	int			rows_size;//				Guarda el numero de filas que contiene el plano del mapa
	char		*one_line_plan;//			Guarda todas las lineas del plano en unico string para poder trabajar mas facilmente
	size_t		row_len;//					Tamaño de las filas
	char		**plan;//					Matriz donde guardas el mapa
	char		**plan_tmp;//					Matriz donde guardas el mapa
	int			values_ok;//
	char		player_init_coor;//
	double		player_init_position_x;//	Vector de posicion del jugador x (inicial)
	double		player_init_position_y;//	Vector de posicion del jugador y (inical )
	char		*player_positon;//			Matriz de posicion del jugador (para poder meter en sus indices init x e init y) no lo uliltizo
	char		boundary_value;//			Valor que se le da a los muros y que es utilizado en el funcion de validacion por inundacion '1'
	char		fill_value;//				Valor con el que se va a sustituir la baldosa en caso de que sea 0 en el algoritmo por inundacion 'f'
	char		sprite_value;//				Valor del sprite que tendremos en cuenta al uilizar el algoritmo por inundacion '2'
}				t_map;//plan
/*
** Inicia todo lo necesario para que la mlx carge
** y funcione correctamente
*/
typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}							t_mlx;
/*
** Controles que afectan a la ventan y al juego
*/
typedef struct s_controls
{
	int			esc;// Salir
	int			forward;// Avanzar hacia alante
	int			sideways;// Avanzar hacia atras
	int			rotate;// Rotar izquierda y derecha
	double	olddirx;
	double	oldplanex;
}							t_controls;

typedef struct s_player
{
	double	posx;// Posicion del jugador
	double	posy;// Posicion del jugador
	double	dirx;// Direccion del jugador
	double	diry;// Direccion del jugador
	double	planex;// Plano de la camara dej jugador
	double	planey;//	Plano de la camara dej jugador
}							t_player;

typedef struct s_raycast
{
	int			x;// Contador del disparador de rayos
	int			y;//
	double	camerax;// coordenada-x in camera space
	double	raydirx;// Direccion del rayo
	double	raydiry;// Direccion del rayo
	int			mapx;// Cuadrado actual del mapa en el que esta el rayo
	int			mapy;// Cuadrado actual del mapa en el que esta el rayo
	double	sidedistx;// longitud del rayo desde la posición actual hasta el siguiente lado x
	double	sidedisty;// longitud del rayo desde la posición actual hasta el siguiente lado y
	double	deltadistx;// Longitud del rayo de un lado 'x' al siguiente lado 'x'
	double	deltadisty;// Longitud del rayo de un lado 'y' al siguiente lado 'y'
	double	perpwalldist;// Distancia perpendicular desde el muro al plano de la camara.
	int			stepx;// El lado hacia el que avanzara el rayo. Sera x?
	int			stepy;// El lado hacia el que avanzara el rayo. Sera y?
	int			hit;// Flag que comprueba si el muro fue golpeado por el rayo
	int			side;// Flag que compreba en que lado del muro golpeo el rayo (NS,EO)
	double	wallx;// Donde ha sido golpeado el muro exactamente
	int			texnum;
}							t_raycast;


typedef struct	s_window
{
	int		lineheight;// Altura de la linea donde empezar a dibujar en la pantalla
	int		drawstart;// Donde comienza a dibujar en la ventana
	int		drawend;// Donde termina de dibujar en la ventana
}							t_window;

typedef struct	s_texture
{
	void					*img_tex;// Puntero a la imagen que se genera en mlx_xpm_file_to_image
	int						*addr;// Dirección a la imagen que se genera.
	int						bpp;// Bites por pixel
	int						endian;// Manera en la que se representan los bites dependiendo del sistema
	int						size_line;
	int						x;// Coordenada x en la textura
	int						y;// Coordenada y en la textura
	double				height;// Ancho de la textura
	double				width;// Alto de la textura
	double				step;// Cuanto hay que aumentar la coordenada de la textura por pixel de la pantalla
	double				pos;// Coordenada inicial de la textura
	unsigned int	color;
}								t_texture;

typedef struct	s_cub3d
{
	double				*zbuffer;
	t_parse				map;// Parseo del juego
	t_map					plan;// Plano del juego
	t_mlx					mlx;// Configuracion mlx
	t_controls		ctrl;// Controloes del juego
	t_raycast			rcast;// Raycast
	t_player			p;// Jugador
	t_window			win;// Ventana
	t_texture			tex[4];// Array de configuracion de texturas para los muros y sprite

//	t_image				text[4];// hace refencia a las texturas n,s,e,o. (t_image y t_texture con casi identicas, solo que t_texture abarca mas variables)
}								t_cub3d;

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
void	path_validation(char *str);
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
int		boundary_fill(int x, int y, int fill_value, int boundary_value, t_cub3d *cub);
void	graphic(t_cub3d *cub);
void	start_mlx(t_cub3d *cub);
void	load_textures(t_cub3d *cub);
void	load_wall_texture(t_cub3d *cub);
void	load_sprite_texture(t_cub3d *cub);
void	key_press(int keycode, t_cub3d *cub);
void	key_release(int keycode, t_cub3d *cub);
int		moving(t_cub3d *cub);
int		rotating(t_cub3d *cub);
int		raycast(t_cub3d *cub);
int		game(t_cub3d *cub);


#endif
