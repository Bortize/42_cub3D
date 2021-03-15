/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfom_dda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 20:06:35 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/10 20:12:06 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	perfom_dda(t_raycast *rcast, t_map *plan)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (rcast->sidedistx < rcast->sidedisty)
		{
			rcast->sidedistx += rcast->deltadistx;
			rcast->mapx += rcast->stepx;
			rcast->side = 0 + (rcast->raydirx < 0);
		}
		else
		{
			rcast->sidedisty += rcast->deltadisty;
			rcast->mapy += rcast->stepy;
			rcast->side = 2 + (rcast->raydiry > 0);
		}
		if (plan->plan[rcast->mapy][rcast->mapx] == '1')
			hit = 1;
	}
}
