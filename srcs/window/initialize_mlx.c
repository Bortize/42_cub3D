/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 19:13:44 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/20 17:40:54 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	initialize_mlx(map_config *map)
{
	t_window graphic;

	graphic.mlx = mlx_init();
	graphic.mlx_win = mlx_new_window(graphic.mlx, map->width, map->height, "cub3D");
	graphic.img = mlx_new_image(graphic.mlx, map->width, map->height);
	graphic.addr = mlx_get_data_addr(graphic.img, &graphic.bpp, &graphic.line_length, &graphic.endian);
	my_mlx_pixel_put(&graphic, 5, 5, 0x0000FF00);
	mlx_put_image_to_window(graphic.mlx, graphic.mlx_win, graphic.img, 0, 0);
	mlx_key_hook(graphic.mlx, key_hook, &graphic);
	mlx_loop(graphic.mlx);
}
