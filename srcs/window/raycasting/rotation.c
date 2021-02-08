/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:51:30 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/08 20:38:54 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

static void		rotate_right(t_cub3d *cub)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = cub->graphic.player_dir_x;
	cub->graphic.player_dir_x = cub->graphic.player_dir_x *
	cos(-ROT_SPEED) - cub->graphic.player_dir_y * sin(-ROT_SPEED);
	cub->graphic.player_dir_y = oldDirX * sin(-ROT_SPEED) +
	cub->graphic.player_dir_y * cos(-ROT_SPEED);

	oldPlaneX = cub->graphic.player_plane_x;
	cub->graphic.player_plane_x = cub->graphic.player_plane_x *
	cos(-ROT_SPEED) - cub->graphic.player_plane_y * sin(-ROT_SPEED);
	cub->graphic.player_plane_y = oldPlaneX * sin(-ROT_SPEED) +
	cub->graphic.player_plane_y * cos(-ROT_SPEED);
}

static void		rotate_left(t_cub3d *cub)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = cub->graphic.player_dir_x;
	cub->graphic.player_dir_x = cub->graphic.player_dir_x *
	cos(ROT_SPEED) - cub->graphic.player_dir_y * sin(ROT_SPEED);
	cub->graphic.player_dir_y = oldDirX * sin(ROT_SPEED) +
	cub->graphic.player_dir_y * cos(ROT_SPEED);

	oldPlaneX = cub->graphic.player_plane_x;
	cub->graphic.player_plane_x = cub->graphic.player_plane_x *
	cos(ROT_SPEED) - cub->graphic.player_plane_y * sin(ROT_SPEED);
	cub->graphic.player_plane_y = oldPlaneX * sin(ROT_SPEED) +
	cub->graphic.player_plane_y * cos(ROT_SPEED);
}

/*
** Controla la rotacion del jugador
*/
void	rotation(t_cub3d *cub)
{
	if (cub->move.rotating_left)
		rotate_left(cub);
	if (cub->move.rotating_right)
		rotate_right(cub);
}
