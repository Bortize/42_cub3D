/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_stripe_sprite_screen.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:59:34 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/13 14:43:32 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline static void	painting_sprite(t_cub3d *cub, t_drawsprites drwspr)
{
	while (drwspr.y < cub->spr.drawendy)
	{
		drwspr.d = drwspr.y * 256 - cub->map.height
			* 128 + cub->spr.spriteheight * 128;
		drwspr.texy = ((drwspr.d * cub->tex.sprite[0].height)
			/ cub->spr.spriteheight) / 256;
		drwspr.color = cub->tex.sprite[0].addr[cub->tex.sprite[0].width
			* drwspr.texy + drwspr.texx];
		if ((drwspr.color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(cub, drwspr.stripe,
			drwspr.y, drwspr.color);
		drwspr.y++;
	}
}

void				vertical_stripe_sprite_screen(t_cub3d *cub,
	t_drawsprites drwspr)
{
	while (drwspr.stripe < cub->spr.drawendx)
	{
		drwspr.texx = (int)(256 * (drwspr.stripe - (-cub->spr.spritewidth
			/ 2 + cub->spr.spritescreenx)) * cub->tex.sprite[0].width
			/ cub->spr.spritewidth) / 256;
		if (cub->spr.transformy > 0 && drwspr.stripe > 0
			&& drwspr.stripe < cub->map.width
			&& cub->spr.transformy < cub->zbuffer[drwspr.stripe])
		{
			drwspr.y = cub->spr.drawstarty;
			painting_sprite(cub, drwspr);
		}
		drwspr.stripe++;
	}
}
