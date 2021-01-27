/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:42:29 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/27 19:04:23 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

void	initial_calc(t_cub3d *cub, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)(cub->map.width) - 1;
	cub->graphic.ray_dir_x = cub->graphic.player_dir_x + cub->graphic.player_plane_x * camera_x;
	cub->graphic.ray_dir_y = cub->graphic.player_dir_y + cub->graphic.player_plane_y * camera_x;
	rc->map_x = (int)(rc->player_pos_x);
	rc->map_y = (int)(rc->player_pos_y);
	rc->delta_dist_x = sqrt(1 + pow(rc->ray_dir_y, 2) / pow(rc->ray_dir_x, 2));
	rc->delta_dist_y = sqrt(1 + pow(rc->ray_dir_x, 2) / pow(rc->ray_dir_y, 2));
	if (rc->ray_dir_x < 0)
	{
		rc->step_x = -1;
		rc->side_dist_x = (rc->player_pos_x - rc->map_x) * rc->delta_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist_x = (rc->map_x + 1.0 - rc->player_pos_x) * rc->delta_dist_x;
	}
	if (rc->ray_dir_y < 0)
	{
		rc->step_y = -1;
		rc->side_dist_y = (rc->player_pos_y - rc->map_y) * rc->delta_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist_y = (rc->map_y + 1.0 - rc->player_pos_y) * rc->delta_dist_y;
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
		perform_dda(cub);
		calc_wall_height(cub);
		draw_vert_line(cub, x);
		x++;
	}
	if (handle_events(key,cub) != 0)
		return (-1);
	return (0);
}
