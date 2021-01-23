/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws_sky_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 13:40:02 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/23 14:32:45 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	draws_sky_floor(int keycode, t_window *graphic)
{
	int y;
	int x;

	if (keycode == 15)
	{
		y = 0;
		while (y < graphic->map->height / 2)
 		{
			x=0;
			while(x < graphic->map->width)
			{
				mlx_pixel_put(graphic->mlx, graphic->mlx_win, x, y, 0x49ACFF);
				x++;
			}
 			y++;
		}
	}
	return (0);
}
