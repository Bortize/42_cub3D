/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:51:30 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/10 00:47:18 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
** Controls player rotation
*/
void	rotation(t_cub3d *cub)
{
	double oldDirX;
	double oldPlaneX;
	double rot_speed;

	rot_speed = ROT_SPEED * cub->ctrl.rotate;

	oldDirX = cub->p.dirx;
	cub->p.dirx = cub->p.dirx * cos(rot_speed) -
		cub->p.diry * sin(rot_speed);
	cub->p.diry = oldDirX * sin(rot_speed) +
		cub->p.diry * cos(rot_speed);

	oldPlaneX = cub->p.planex;
	cub->p.planex = cub->p.planex * cos(rot_speed) -
		cub->p.planey * sin(rot_speed);
	cub->p.planey  = oldPlaneX * sin(rot_speed) +
		cub->p.planey  * cos(rot_speed);
}
