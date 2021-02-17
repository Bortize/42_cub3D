/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:51:30 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/17 20:52:25 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
** Controla la rotacion del jugador
*/
void	rotation(t_cub3d *cub)
{
	double oldDirX;
	double oldPlaneX;
	double rot_speed;

	rot_speed = ROT_SPEED * cub->move.rotating;

	oldDirX = cub->graphic.player_dir_x;
	cub->graphic.player_dir_x = cub->graphic.player_dir_x *
	cos(rot_speed) - cub->graphic.player_dir_y * sin(rot_speed);
	cub->graphic.player_dir_y = oldDirX * sin(rot_speed) +
	cub->graphic.player_dir_y * cos(rot_speed);

	oldPlaneX = cub->graphic.player_plane_x;
	cub->graphic.player_plane_x = cub->graphic.player_plane_x *
	cos(rot_speed) - cub->graphic.player_plane_y * sin(rot_speed);
	cub->graphic.player_plane_y = oldPlaneX * sin(rot_speed) +
	cub->graphic.player_plane_y * cos(rot_speed);
}
