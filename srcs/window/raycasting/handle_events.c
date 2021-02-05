/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:40:20 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/05 17:37:41 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

int handle_events(int keycode, t_cub3d *cub)
{
	double oldDirX;
	double oldPlaneX;

	if (keycode == 53)
	{
		system("killall a.out && clear");
		return (-1);
	}
	if (keycode == 125 || keycode == 126 || keycode == 124 || keycode == 123)
	{
		if (keycode == 126)
		{
			if (cub->plan.plan[(int)(cub->graphic.player_pos_x + cub->graphic.player_dir_x * MV_SPEED)][(int)(cub->graphic.player_pos_y)] == 0)
				cub->graphic.player_pos_x += cub->graphic.player_dir_x * MV_SPEED;
			if (cub->plan.plan[(int)(cub->graphic.player_pos_x)][(int)(cub->graphic.player_pos_y + cub->graphic.player_dir_y * MV_SPEED)] == 0)
				cub->graphic.player_pos_y += cub->graphic.player_dir_y * MV_SPEED;
		}
		if (keycode == 125)
		{
			if (cub->plan.plan[(int)(cub->graphic.player_pos_x - cub->graphic.player_dir_x * MV_SPEED)][(int)(cub->graphic.player_pos_y)] == 0)
				cub->graphic.player_pos_x -= cub->graphic.player_dir_x * MV_SPEED;
			if (cub->plan.plan[(int)(cub->graphic.player_pos_x)][(int)(cub->graphic.player_pos_y - cub->graphic.player_dir_y * MV_SPEED)] == 0)
				cub->graphic.player_pos_y -= cub->graphic.player_dir_y * MV_SPEED;
		}
		if (keycode == 124)
		{
			oldDirX = cub->graphic.player_dir_x;
			cub->graphic.player_dir_x = cub->graphic.player_dir_x * cos(-ROT_SPEED) - cub->graphic.player_dir_y * sin(-ROT_SPEED);
			cub->graphic.player_dir_y = oldDirX * sin(-ROT_SPEED) + cub->graphic.player_dir_y * cos(-ROT_SPEED);
			oldPlaneX = cub->graphic.player_plane_x;
			cub->graphic.player_plane_x = cub->graphic.player_plane_x * cos(-ROT_SPEED) - cub->graphic.player_plane_y * sin(-ROT_SPEED);
			cub->graphic.player_plane_y = oldPlaneX * sin(-ROT_SPEED) + cub->graphic.player_plane_y * cos(-ROT_SPEED);
		}
		if (keycode == 123)
		{
			oldDirX = cub->graphic.player_dir_x;
			cub->graphic.player_dir_x = cub->graphic.player_dir_x * cos(ROT_SPEED) - cub->graphic.player_dir_y * sin(ROT_SPEED);
			cub->graphic.player_dir_y = oldDirX * sin(ROT_SPEED) + cub->graphic.player_dir_y * cos(ROT_SPEED);
			oldPlaneX = cub->graphic.player_plane_x;
			cub->graphic.player_plane_x = cub->graphic.player_plane_x * cos(ROT_SPEED) - cub->graphic.player_plane_y * sin(ROT_SPEED);
			cub->graphic.player_plane_y = oldPlaneX * sin(ROT_SPEED) + cub->graphic.player_plane_y * cos(ROT_SPEED);
		}
	}
return (0);
}
