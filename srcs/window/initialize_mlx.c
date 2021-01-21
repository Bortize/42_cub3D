/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 19:13:44 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/21 14:32:35 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	initialize_mlx(map_config *map)
{
	t_window graphic;

	if (!(graphic.mlx = mlx_init()))
		print_error("Fallo al iniciar MLX");
	graphic.mlx_win = mlx_new_window(graphic.mlx, map->width, map->height, "cub3D");
	graphic.img = mlx_new_image(graphic.mlx, map->width, map->height);
	graphic.addr = mlx_get_data_addr(graphic.img, &graphic.bpp, &graphic.line_length, &graphic.endian);
	my_mlx_pixel_put(&graphic, 5, 5, 0x0000FF00);
	mlx_put_image_to_window(graphic.mlx, graphic.mlx_win, graphic.img, 0, 0);
	mlx_key_hook(graphic.mlx, keypress, &graphic);
	//mlx_hook(t.win, 2, 0, exit_program, &t);
	mlx_loop_hook(graphic.mlx, keypress, &graphic);
	mlx_loop(graphic.mlx);// Inicia la randeriazacion de la ventana
}
