/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:42:29 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/01 20:39:26 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"
/*
** Refresca la pantalla para crear la nueva imagen
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
			mlx_pixel_put(cub->graphic.mlx, cub->graphic.mlx_win, x, y, 0x000000);
			y++;
		}
		y=0;
		x++;
	}
}

void	initial_calc(t_cub3d *cub, int x)
{
//	AHORA SE PROCEDE A CALCULAR LA DIRECCION DE LA SEMIRECTA.
	cub->graphic.camera_x = 2 * x / (double)(cub->map.width) - 1;
	// Direccion del rayo
	cub->graphic.ray_dir_x = cub->graphic.player_dir_x + cub->graphic.player_plane_x * cub->graphic.camera_x;
	cub->graphic.ray_dir_y = cub->graphic.player_dir_y + cub->graphic.player_plane_y * cub->graphic.camera_x;
	// Cuadrado actual en el que se en cuentra el rayo
	cub->graphic.map_x = (int)(cub->graphic.player_pos_x);
	cub->graphic.map_y = (int)(cub->graphic.player_pos_y);
	// Longitud del rayo de un lado 'x' o 'y' al siguiente lado 'x' o 'y'
	cub->graphic.delta_dist_x = fabs(1 / cub->graphic.ray_dir_x);
	cub->graphic.delta_dist_y = fabs(1 / cub->graphic.ray_dir_y);
	// Calcular el sideDist inicial y el paso
	if (cub->graphic.ray_dir_x < 0)
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
** Avanza por las baldosas del plano comprobando en cada iteración del while si es rayo ha
** impactado en algun muro.
*/
void	perform_dda(t_cub3d *cub)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
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
	if (cub->plan.plan[cub->graphic.map_x][cub->graphic.map_y] != '0')
		hit = 1;
	}
}

void	calc_wall_height(t_cub3d *cub)
{
	int	line_height;

	if (cub->graphic.side == 0)
		rc->perp_wall_dist = (rc->map_x - rc->player_pos_x + (1 - rc->step_x) / 2) / rc->ray_dir_x;
	else
		rc->perp_wall_dist = (rc->map_y - rc->player_pos_y + (1 - rc->step_y) / 2) / rc->ray_dir_y;
	line_height = (int)(WIN_Y / rc->perp_wall_dist);
	rc->draw_start = -line_height / 2 + WIN_Y / 2;
	if (rc->draw_start < 0)
		rc->draw_start = 0;
	rc->draw_end = line_height / 2 + WIN_Y / 2;
	if (rc->draw_end >= WIN_Y)
	rc->draw_end = WIN_Y - 1;
}

int	raycasting(t_cub3d *cub)
{
	int x;

	x = 0;
	refresh_screen(cub);
	//for
	while (x < cub->map.width)// Mientras x sea menor que el anchod e la resolucion de la ventana
	{
		initial_calc(cub, x);
		perform_dda(cub);// el algoritmo en bucle que va a calcular cuadno chocque el rayo
		calc_wall_height(cub);// Calcula la altura del muro una vez que el rayo choca con el muro
		draw_vert_line(cub, x);// Dibuja las franjas de los pixeles de izq a dcha
		x++;
	}
	if (handle_events(key,cub) != 0)
		return (-1);
	return (0);
}
