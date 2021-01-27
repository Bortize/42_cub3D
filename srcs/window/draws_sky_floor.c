/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws_sky_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 13:40:02 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/27 17:19:11 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	draws_sky_floor(t_cub3d *cub)
{
	ft_printf("hola amigo \n");
	ft_printf("el ancho es %d \n", cub->map.height);
	ft_printf("El alto es %d \n", cub->map.width);
	ft_printf("%p \n", cub->graphic.addr);
	int y;
	int x;
	y=0;
	while (y < cub->map.height / 2)
 	{
		x=0;
		while(x < cub->map.width)
		{
			my_mlx_pixel_put(cub, x, y, 0xFFFF0000);
			//mlx_pixel_put(cub->graphic.mlx, cub->graphic.mlx_win, x, y, 0xFFFF0000);
			x++;
		}
 		y++;
	}
	while(y < cub->map.height)
	{
		x=0;
		while(x < cub->map.width)
		{
			my_mlx_pixel_put(cub, x, y, 0xFFFF00FF);
			//mlx_pixel_put(cub->graphic.mlx, cub->graphic.mlx_win, x, y, 0x00FFFF00);
			x++;
		}
 		y++;
	}
	//mlx_destroy_image(cub->graphic.mlx, cub->graphic.img);
	return(0);
}

