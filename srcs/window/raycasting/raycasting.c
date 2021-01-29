/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:42:29 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/29 19:36:05 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

void	initial_calc(t_cub3d *cub, int x)
{
	double	camera_x;// coordenada x en el plano de la camara que represneta la actual coordenada x de la pantalla.
//	AHORA SE PROCEDE A CALCULAR LA DIRECCION DE LA SEMIRECTA.
	camera_x = 2 * x / (double)(cub->map.width) - 1;
	cub->graphic.ray_dir_x = cub->graphic.player_dir_x + cub->graphic.player_plane_x * camera_x;
	cub->graphic.ray_dir_y = cub->graphic.player_dir_y + cub->graphic.player_plane_y * camera_x;
	cub->graphic.map_x = (int)(cub->graphic.player_pos_x);
	cub->graphic.map_y = (int)(cub->graphic.player_pos_y);
	// Longitud del rayo de un lado x o y al siguiente lado x o y
/*
** 	cub->graphic.delta_dist_x = sqrt(1 + pow(cub->graphic.ray_dir_y, 2) / pow(cub->graphic.ray_dir_x, 2));
** 	cub->graphic.delta_dist_y = sqrt(1 + pow(cub->graphic.ray_dir_x, 2) / pow(cub->graphic.ray_dir_y, 2));
*/
	cub->graphic.delta_dist_x = fabs(1 / cub->graphic.ray_dir_x);
	cub->graphic.delta_dist_y = fabs(1 / cub->graphic.ray_dir_y);
	// Calcula el paso y el sideDist inicial
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


int	raycasting(t_cub3d *cub)
{
	int x;

	x = 0;
	refresh_screen(cub);
	//for
	while (x < cub->map.width)
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
