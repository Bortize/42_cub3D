/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_perp_ray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:34:45 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/10 20:58:30 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Calculate distance of perpendicular ray (Euclidean distance will give
** fisheye effect!)
*/

void	distance_perp_ray(t_raycast *rcast, t_player *p)
{
	if(rcast->side <= 1)
		rcast->perpwalldist = (rcast->mapx - p->posx + (1 - rcast->stepx) / 2)
		/ rcast->raydirx;
	else
		rcast->perpwalldist = (rcast->mapy - p->posy + (1 - rcast->stepy) / 2)
		/ rcast->raydiry;
}
