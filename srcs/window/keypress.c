/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:10:22 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/24 17:22:48 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	keypress(int keycode, t_window *graphic)
{
	if (keycode == KEY_R)
	{
		ft_printf("hola amigo \n");
		ft_printf("el ancho es %d \n", &cub->map.height);
		ft_printf("El alto es %d \n", &cub->map.width);
		ft_printf("%p \n", graphic->addr);
		int y;
		int x;
		if (keycode == 15)
		{
			y=0;
			while (y < cub->map.height)
 			{
				x=0;
				while(x < cub->map.width)
				{
					mlx_pixel_put(graphic->mlx, graphic->mlx_win, x, y, 0x00FF0000);
					x++;
				}
 				y++;
			}
		}
	}
	return(0);
}
