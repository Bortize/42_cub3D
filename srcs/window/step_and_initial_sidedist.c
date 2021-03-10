/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_and_initial_sidedist.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:53:54 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/10 19:59:34 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** calculate step and initial sideDist
*/

void	step_and_initial_sidedist(t_cub3d *cub)
{
	if (cub->rcast.raydirx < 0)
	{
		cub->rcast.stepx = -1;
		cub->rcast.sidedistx = (cub->p.posx - cub->rcast.mapx)
		* cub->rcast.deltadistx;
	}
	else
	{
		cub->rcast.stepx = 1;
		cub->rcast.sidedistx = (cub->rcast.mapx + 1.0 - cub->p.posx)
		* cub->rcast.deltadistx;
	}
	if (cub->rcast.raydiry < 0)
	{
		cub->rcast.stepy = -1;
		cub->rcast.sidedisty = (cub->p.posy - cub->rcast.mapy)
		* cub->rcast.deltadisty;
	}
	else
	{
		cub->rcast.stepy = 1;
		cub->rcast.sidedisty = (cub->rcast.mapy + 1.0 - cub->p.posy)
		* cub->rcast.deltadisty;
	}
}
