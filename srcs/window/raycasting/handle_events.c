/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:40:20 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/07 19:22:26 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

int handle_events(int keycode, t_cub3d *cub)
{
	double oldDirX;
	double oldPlaneX;

		if (keycode == 53)
		{
			print_error("Escape");
		}
		if (keycode == KEY_W)
		{
			if (cub->plan.plan[(int)(cub->graphic.player_pos_y)][(int)(cub->graphic.player_pos_x + cub->graphic.player_dir_x * MV_SPEED)] == '0')
				cub->graphic.player_pos_x += cub->graphic.player_dir_x * MV_SPEED;
			if (cub->plan.plan[(int)(cub->graphic.player_pos_y + cub->graphic.player_dir_y * MV_SPEED)][(int)(cub->graphic.player_pos_x)] == '0')
				cub->graphic.player_pos_y += cub->graphic.player_dir_y * MV_SPEED;
		}
		if (keycode == KEY_S)
		{
			if (cub->plan.plan[(int)(cub->graphic.player_pos_y)][(int)(cub->graphic.player_pos_x - cub->graphic.player_dir_x * MV_SPEED)] == '0')
				cub->graphic.player_pos_x -= cub->graphic.player_dir_x * MV_SPEED;
			if (cub->plan.plan[(int)(cub->graphic.player_pos_y - cub->graphic.player_dir_y * MV_SPEED)][(int)(cub->graphic.player_pos_x)] == '0')
				cub->graphic.player_pos_y -= cub->graphic.player_dir_y * MV_SPEED;
		}
		if (keycode == KEY_D)
		{
			if (cub->plan.plan[(int)(cub->graphic.player_pos_y)][(int)(cub->graphic.player_pos_x - cub->graphic.player_dir_y * MV_SPEED)] == '0')
				cub->graphic.player_pos_x -= cub->graphic.player_dir_y * MV_SPEED;
			if (cub->plan.plan[(int)(cub->graphic.player_pos_y - cub->graphic.player_dir_x * MV_SPEED)][(int)(cub->graphic.player_pos_x)] == '0')
				cub->graphic.player_pos_y -= cub->graphic.player_dir_x * MV_SPEED;
		}
		if (keycode == KEY_A)
		{
			if (cub->plan.plan[(int)(cub->graphic.player_pos_y)][(int)(cub->graphic.player_pos_x + cub->graphic.player_dir_y * MV_SPEED)] == '0')
				cub->graphic.player_pos_x += cub->graphic.player_dir_y * MV_SPEED;
			if (cub->plan.plan[(int)(cub->graphic.player_pos_y + cub->graphic.player_dir_x * MV_SPEED)][(int)(cub->graphic.player_pos_x)] == '0')
				cub->graphic.player_pos_y += cub->graphic.player_dir_x * MV_SPEED;
		}
		if (keycode == KEY_LEFT)
		{
			oldDirX = cub->graphic.player_dir_x;
			cub->graphic.player_dir_x = cub->graphic.player_dir_x * cos(-ROT_SPEED) - cub->graphic.player_dir_y * sin(-ROT_SPEED);
			cub->graphic.player_dir_y = oldDirX * sin(-ROT_SPEED) + cub->graphic.player_dir_y * cos(-ROT_SPEED);
			oldPlaneX = cub->graphic.player_plane_x;
			cub->graphic.player_plane_x = cub->graphic.player_plane_x * cos(-ROT_SPEED) - cub->graphic.player_plane_y * sin(-ROT_SPEED);
			cub->graphic.player_plane_y = oldPlaneX * sin(-ROT_SPEED) + cub->graphic.player_plane_y * cos(-ROT_SPEED);
		}
		if (keycode == KEY_RIGHT)
		{
			oldDirX = cub->graphic.player_dir_x;
			cub->graphic.player_dir_x = cub->graphic.player_dir_x * cos(ROT_SPEED) - cub->graphic.player_dir_y * sin(ROT_SPEED);
			cub->graphic.player_dir_y = oldDirX * sin(ROT_SPEED) + cub->graphic.player_dir_y * cos(ROT_SPEED);
			oldPlaneX = cub->graphic.player_plane_x;
			cub->graphic.player_plane_x = cub->graphic.player_plane_x * cos(ROT_SPEED) - cub->graphic.player_plane_y * sin(ROT_SPEED);
			cub->graphic.player_plane_y = oldPlaneX * sin(ROT_SPEED) + cub->graphic.player_plane_y * cos(ROT_SPEED);
		}
		return (0);
}
