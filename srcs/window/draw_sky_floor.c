/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sky_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 13:40:02 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/05 23:41:09 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draws_sky_floor(t_cub3d *cub, int x)
{
	int y;

	y = 0;
	while (y < cub->win.drawstart)
 	{
		 my_mlx_pixel_put(cub, x, y, cub->map.ceilling_conv);
 		y++;
	}
}
