/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:10:22 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/21 12:49:08 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	keypress(int keycode, t_window *graphic)
{
	int y;
	int x;
	if (keycode == KEY_R)
	{
			y=0;
			while (y < 480)
			{
					x=0;
					while(x < 640)
					{
					my_mlx_pixel_put(graphic->mlx, x, y, 0x00FF0000);
					x++;
					}
			y++;
			}
	}
	return(0);
}
