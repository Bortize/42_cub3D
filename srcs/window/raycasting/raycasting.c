/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:42:29 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/04 00:19:36 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"
/*
** Refresca la pantalla para crear la nueva imagen y aprovecha para pintar
** el suelo del color que le es pasado por parametro en la funcion my_mlx_
** pixel_put
*/
void	refresh_screen(t_cub3d *cub){
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < cub->map.width)
	{
		while (y < cub->map.height)
		{
			//mlx_pixel_put(cub->graphic.mlx, cub->graphic.mlx_win, x, y, 0x000000);
			my_mlx_pixel_put(cub, x, y, cub->map.floor_conv);
			y++;
		}
		y = 0;
		x++;
	}
}

void	initial_calc(t_cub3d *cub, int x)
{
//	Le paso la posicion inicial del jugador para que pueda moverse
	//cub->graphic.player_pos_x = cub->plan.player_init_position_x;
	//cub->graphic.player_pos_y = cub->plan.player_init_position_y;

//	Calcula la posicion y direccion del rayo
	cub->graphic.camera_x = 2 * x / (double)cub->map.width - 1;
	// Direccion del rayo
	cub->graphic.ray_dir_x = cub->graphic.player_dir_x + cub->graphic.player_plane_x * cub->graphic.camera_x;
	cub->graphic.ray_dir_y = cub->graphic.player_dir_y + cub->graphic.player_plane_y * cub->graphic.camera_x;
	// Cuadrado actual en el que se en cuentra el rayo
	cub->graphic.map_x = (int)(cub->graphic.player_pos_x);
	cub->graphic.map_y = (int)(cub->graphic.player_pos_y);
	// Longitud del rayo de un lado 'x' o 'y' al siguiente lado 'x' o 'y'
	cub->graphic.delta_dist_x = fabs(1 / cub->graphic.ray_dir_x);
	cub->graphic.delta_dist_y = fabs(1 / cub->graphic.ray_dir_y);
	//printf("%f, %f\n", cub->graphic.player_pos_y, cub->graphic.player_pos_y);
	// Calcular el sideDist inicial y el paso
	if (cub->graphic.ray_dir_x < 0.)
	{
		cub->graphic.step_x = -1;
		cub->graphic.side_dist_x = (cub->graphic.player_pos_x - cub->graphic.map_x) * cub->graphic.delta_dist_x;
	}
	else
	{
		cub->graphic.step_x = 1;
		cub->graphic.side_dist_x = (cub->graphic.map_x + 1.0 - cub->graphic.player_pos_x) * cub->graphic.delta_dist_x;
	}
	if (cub->graphic.ray_dir_y < 0)
	{
		cub->graphic.step_y = -1;
		cub->graphic.side_dist_y = (cub->graphic.player_pos_y - cub->graphic.map_y) * cub->graphic.delta_dist_y;
	}
	else
	{
		cub->graphic.step_y = 1;
		cub->graphic.side_dist_y = (cub->graphic.map_y + 1.0 - cub->graphic.player_pos_y) * cub->graphic.delta_dist_y;
	}
}

/*
** Esta funcion esta relacioada con la funcion de pintar los muros. Sus numeros, hacen refererencia
** a los colores en funcion de la direccion de la pared.
*/
static	int		ray_direction(t_cub3d *cub)
{
	int direction;

	direction = 0;
	if (cub->graphic.side_dist_x > cub->graphic.side_dist_y)
	{
		direction = 0 + (cub->graphic.ray_dir_y > 0);
		//direction = cub->graphic.ray_dir_y < 0 ? NORTH : SOUTH;
		return (direction);
	}
	else
	{
		direction = 2 + (cub->graphic.ray_dir_x < 0);
		//direction = cub->graphic.ray_dir_y < 0 ? WEST : EAST;
		return (direction);
	}
}

/*
** Avanza por las baldosas del plano comprobando en cada iteración del while si el rayo ha
** impactado en algun muro.
*/
void	perform_dda(t_cub3d *cub)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		cub->graphic.wall_direction = ray_direction(cub);
		cub->graphic.ray_texture = cub->text[cub->graphic.wall_direction];
		// raycast_texture(cub);// El rayo que define los colors de las texturas.
	// saltar a la siguiente casilla del mapa, o en dirección x, o en dirección y
		if (cub->graphic.side_dist_x < cub->graphic.side_dist_y)
		{
			cub->graphic.side_dist_x += cub->graphic.delta_dist_x;
			cub->graphic.map_x += cub->graphic.step_x;
			cub->graphic.side = 0;
		}
		else
		{
			cub->graphic.side_dist_y += cub->graphic.delta_dist_y;
			cub->graphic.map_y += cub->graphic.step_y;
			cub->graphic.side = 1;
		}
		if (cub->plan.plan[cub->graphic.map_y][cub->graphic.map_x] == '1')
			hit = 1;
	}
}
/*
** Calcula la altura de los muros utilizando la distancia perpendicular
** en vez de la distancia real euclidiana.
*/
void	calc_wall_height(t_cub3d *cub)
{
	if (cub->graphic.side == 0)
		cub->graphic.perp_wall_dist = (cub->graphic.map_x - cub->graphic.player_pos_x + (1 - cub->graphic.step_x) / 2) / cub->graphic.ray_dir_x;
	else
		cub->graphic.perp_wall_dist = (cub->graphic.map_y - cub->graphic.player_pos_y + (1 - cub->graphic.step_y) / 2) / cub->graphic.ray_dir_y;
	//Calculate height of line to draw on screen
	cub->graphic.line_height = (int)(cub->map.height / cub->graphic.perp_wall_dist);
	//calculate lowest and highest pixel to fill in current stripe
	cub->graphic.draw_start = -cub->graphic.line_height / 2 + cub->map.height / 2;
	if (cub->graphic.draw_start < 0)
		cub->graphic.draw_start = 0;
	cub->graphic.draw_end = cub->graphic.line_height / 2 + cub->map.height / 2;
	if (cub->graphic.draw_end >= cub->map.height)
		cub->graphic.draw_end = cub->map.height - 1;
	if (cub->graphic.draw_end < 0)
		cub->graphic.draw_end = 0;
}

/*
** Selecciona el color para los muros en funcion de hacia donde apunta el rayo.
*/
void	draw_vert_line(t_cub3d *cub, int x)
{
//	int color;
//	int y;

//	if (cub->graphic.side == 0 && cub->graphic.ray_dir_x > 0)
//		color = GREEN;
//	if (cub->graphic.side == 0 && cub->graphic.ray_dir_x <= 0)
//		color = YELLOW;
//	if (cub->graphic.side == 1 && cub->graphic.ray_dir_y > 0)
//		color = PURPLE;
//	if (cub->graphic.side == 1 && cub->graphic.ray_dir_y <= 0)
//		color = CIAN;

//	if (cub->graphic.side == 1)
//		color = color + 3000;

	draws_sky_floor(cub, x);
//	y = cub->graphic.draw_start;
//	while (y < cub->graphic.draw_end)
//	{
//		my_mlx_pixel_put(cub, x, y, color);
//		y++;
//	}
}

/*
** Castea la textura para mostrar el pixel de la textura
*/
void			cast_texture(t_cub3d *cub)
{
	double		wall_x;

	if (!(cub->graphic.wall_direction != WEST && cub->graphic.wall_direction != EAST))
		wall_x = cub->graphic.player_pos_y + cub->graphic.perp_wall_dist * cub->graphic.ray_dir_y;
	else
		wall_x = cub->graphic.player_pos_x + cub->graphic.perp_wall_dist * cub->graphic.ray_dir_x;
	wall_x -= floor(wall_x);
	cub->graphic.texture_x = wall_x * (double)cub->graphic.ray_texture.width_text;
	cub->graphic.texture_step = (double)cub->graphic.ray_texture.height_text / cub->graphic.line_height;
	cub->graphic.texture_pos = (cub->graphic.draw_start - cub->map.height / 2 + cub->graphic.line_height / 2)
		* cub->graphic.texture_step;
}

void			draw_textured_line(t_cub3d *cub, int x)
{
	t_image		texture;
	int			i;
	int			text_y;
	int			color;

	i = cub->graphic.draw_start - 1;
	texture = cub->graphic.ray_texture;
	while (++i < cub->graphic.draw_end)
	{
		text_y = (int)cub->graphic.texture_pos % cub->graphic.ray_texture.height_text;
		cub->graphic.texture_pos += cub->graphic.texture_step;
		if (text_y <= cub->graphic.ray_texture.height_text)
			color = texture.addr[cub->graphic.ray_texture.height_text * text_y + cub->graphic.texture_x];
		my_mlx_pixel_put(cub, x, i, color);
	}
}

/*
** Inicia todos los calculos para calcular el lanzamiento y colision de los rayos para
** calcular la altura de los muros y poder dibujarlos
*/
int	raycasting(t_cub3d *cub)
{
	int x;// contador del ancho de la ventana para completar el lanzamiento de los rayos.

	x = 0;
	refresh_screen(cub);
	//for
	while (x < cub->map.width)// Mientras x sea menor que el ancho de la resolucion de la ventana
	{
		initial_calc(cub, x);
		perform_dda(cub);// el algoritmo en bucle que va a calcular cuadno chocque el rayo
		calc_wall_height(cub);// Calcula la altura del muro una vez que el rayo choca con el muro
		cub->zbuffer[x] = cub->graphic.perp_wall_dist;// Se le asigna al buffer la distancia de todos los rayos perpendiculares al plano de la camara.
//		printf("rayos perpendicualres %d al plano ⚡ %f \n", x, cub->zbuffer[x]);
		draw_vert_line(cub, x);// Dibuja las franjas de los pixeles de izq a dcha
		cast_texture(cub);
		draw_textured_line(cub, x);
//		draw_sprites(cub);
		x++;
	}
//	draw_sprites(cub);
	mlx_put_image_to_window(cub->graphic.mlx, cub->graphic.mlx_win, cub->graphic.img, 0, 0);
//	if (handle_events(keycode, cub) != 0)
//		return (-1);
	return (0);
}
