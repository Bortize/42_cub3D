/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 02:33:31 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/11 13:40:15 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** calculate width of the sprite
*/

void	width_sprite(t_parse *map, t_rcastsprite *spr)
{
	spr->spritewidth = abs((int)(map->height / spr->transformy));
	spr->drawstartx = -spr->spritewidth / 2 + spr->spritescreenx;
	if (spr->drawstartx < 0)
		spr->drawstartx = 0;
	spr->drawendx = spr->spritewidth / 2 + spr->spritescreenx;
	if (spr->drawendx >= map->width)
		spr->drawendx = map->width - 1;
}
