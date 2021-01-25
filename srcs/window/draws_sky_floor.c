/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws_sky_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 13:40:02 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/25 19:58:35 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	draws_sky_floor(int keycode, t_cub3d *cub)
{
	int y;
	int x;

	if (keycode == KEY_R)
	{
		y = 0;
		while (y < cub->map.height / 2)
 		{
			x=0;
			while(x < cub->map.width)
			{
				mlx_pixel_put(cub->graphic.mlx, cub->graphic.mlx_win, x, y, 0x49ACFF);
				x++;
			}
 			y++;
		}
	}
	return (0);
}
