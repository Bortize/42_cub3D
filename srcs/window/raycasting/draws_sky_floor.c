/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws_sky_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 13:40:02 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/03 23:47:54 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

inline void	set_pixel(t_cub3d *cub, size_t pixel, int color)
{
	cub->graphic.addr[pixel] = color;
}

void	draws_sky_floor(t_cub3d *cub, int x)
{
	int y;

	y = 0;
	while (y < cub->graphic.draw_start)
 	{
		 my_mlx_pixel_put(cub, x, y, BLUE);
 		y++;
	}
}

