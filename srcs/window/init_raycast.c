/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:19:04 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/11 14:18:48 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** calculate ray position and direction
*/

void	init_raycast(t_cub3d *cub, int col)
{
	cub->rcast.camerax = 2 * col / (double)cub->map.width - 1;
	cub->rcast.raydirx = cub->p.dirx + cub->p.planex * cub->rcast.camerax;
	cub->rcast.raydiry = cub->p.diry + cub->p.planey * cub->rcast.camerax;
	cub->rcast.mapx = (int)(cub->p.posx);
	cub->rcast.mapy = (int)(cub->p.posy);
	cub->rcast.deltadistx = fabs(1 / cub->rcast.raydirx);
	cub->rcast.deltadisty = fabs(1 / cub->rcast.raydiry);
}
