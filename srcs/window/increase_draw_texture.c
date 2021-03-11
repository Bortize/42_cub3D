/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_draw_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 02:13:38 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/11 02:24:15 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	increase_draw_texture(t_cub3d *cub, t_raycalc ray, int col)
{
	t_texture	*text;

	text = &cub->tex.walls[cub->rcast.side];
	ray.step = 1.0 * text->height / cub->win.lineheight;
	ray.pos = (cub->win.drawstart - cub->map.height / 2 + cub->win.lineheight / 2) * ray.step;
	cub->rcast.y = cub->win.drawstart;
	while (cub->rcast.y < cub->win.drawend)
	{
		ray.y = (int)ray.pos & (text->height - 1);
		ray.pos += ray.step;
		int	color;
		color = text->addr[text->width * ray.y + ray.x];
		if(cub->rcast.side % 2)
			color = (color >> 1) & 8355711;
		my_mlx_pixel_put(cub, col, cub->rcast.y, color);
		cub->rcast.y++;
	}
}
