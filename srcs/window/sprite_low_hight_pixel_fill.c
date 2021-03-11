/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_low_hight_pixel_fill.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:48:04 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/11 13:48:53 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** calculate lowest and highest pixel to fill in current stripe
*/

void	sprite_low_hight_pixel_fill(t_parse *map, t_rcastsprite *spr)
{
	spr->drawstarty = -spr->spriteheight / 2 + map->height / 2;
	if (spr->drawstarty < 0)
		spr->drawstarty = 0;
	spr->drawendy = spr->spriteheight / 2 + map->height / 2;
	if (spr->drawendy >= map->height)
		spr->drawendy = map->height - 1;
}
