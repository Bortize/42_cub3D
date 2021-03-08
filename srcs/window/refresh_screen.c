/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:05:14 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/08 14:05:54 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Refresca la ventana constantemente y aprovecha para pitar el suelo para
** sustituyendo el negro por el color elegido.
*/
void	refresh_screen(t_cub3d *cub)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < cub->map.width)
	{
		while (y < cub->map.height)
		{
			my_mlx_pixel_put(cub, x, y, cub->map.floor_conv);
			y++;
		}
		y = 0;
		x++;
	}
}
