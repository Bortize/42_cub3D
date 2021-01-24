/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 19:13:44 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/24 19:18:46 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	initialize_mlx(t_cub3d *cub)
{
	if (!(cub->graphic.mlx = mlx_init()))
		print_error("Fallo al iniciar MLX");
	cub->graphic.mlx_win = mlx_new_window(cub->graphic.mlx, cub->map.width, cub->map.height, "cub3D");
	cub->graphic.img = mlx_new_image(cub->graphic.mlx, cub->map.width, cub->map.height);
	cub->graphic.addr = mlx_get_data_addr(cub->graphic.img, &cub->graphic.bpp, &cub->graphic.line_length, &cub->graphic.endian);

	my_mlx_pixel_put(&cub->graphic, 5, 5, 0x0000FF00);
	mlx_put_image_to_window(cub->graphic.mlx, cub->graphic.mlx_win, cub->graphic.img, 0, 0);
	//mlx_key_hook(graphic.mlx, keypress, &graphic);
	mlx_hook(cub->graphic.mlx_win, KEYPRESS, 0, keypress, &cub->graphic);
	//mlx_hook(graphic.mlx_win, KEYPRESS, 0, draws_sky_floor, &graphic);
	//mlx_loop_hook(graphic.mlx, keypress, &graphic);
	//mlx_loop_hook(graphic.mlx, draws_sky_floor, &graphic);
	mlx_loop(cub->graphic.mlx);// Inicia la randeriazacion de la ventana
}
