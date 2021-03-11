/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast_sprites.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:47:03 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/11 10:51:27 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycast_sprites(t_cub3d *cub, t_drawsprites drwspr)
{
	cub->spr.spritex = cub->sprites[drwspr.i].x - cub->p.posx;
		cub->spr.spritey = cub->sprites[drwspr.i].y - cub->p.posy;
		cub->spr.invdet = 1.0 / (cub->p.planex * cub->p.diry - cub->p.dirx * cub->p.planey);
		cub->spr.transformx = cub->spr.invdet * (cub->p.diry * cub->spr.spritex - cub->p.dirx * cub->spr.spritey);
		cub->spr.transformy = cub->spr.invdet * (-cub->p.planey * cub->spr.spritex + cub->p.planex * cub->spr.spritey);
		cub->spr.spritescreenx = (int)((cub->map.width / 2) * (1 + cub->spr.transformx / cub->spr.transformy));
		cub->spr.spriteheight = abs((int)(cub->map.height / cub->spr.transformy));
}
