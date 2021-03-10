/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:13:26 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/10 21:25:39 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_calculation(t_raycalc ray, t_cub3d *cub)
{
	if (cub->rcast.side <= 1)
		cub->rcast.wallx = cub->p.posy + cub->rcast.perpwalldist * cub->rcast.raydiry;
	else
		cub->rcast.wallx = cub->p.posx + cub->rcast.perpwalldist * cub->rcast.raydirx;
	cub->rcast.wallx -= (floor)(cub->rcast.wallx);
	//x coordinate on the texture
	ray.x = (int)(cub->rcast.wallx * (double)(cub->tex.walls[cub->rcast.side].width));
	if (cub->rcast.side <= 1 && cub->rcast.raydirx > 0)
		ray.x = cub->tex.walls[cub->rcast.side].width - ray.x - 1;
	if (cub->rcast.side >= 2 && cub->rcast.raydiry > 0)
		ray.x = cub->tex.walls[cub->rcast.side].width - ray.x - 1;
}
