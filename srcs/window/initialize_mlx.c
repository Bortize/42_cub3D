/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 19:13:44 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/05 18:38:17 by bgomez-r         ###   ########.fr       */
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
	//mlx_key_hook(cub->graphic.mlx, keypress, cub);
	mlx_hook(cub->graphic.mlx_win, KEYPRESS, 0, handle_events, cub);
	//mlx_hook(graphic.mlx_win, KEYPRESS, 0, draws_sky_floor, cub);
	//mlx_loop_hook(cub->graphic.mlx, keypress, cub);
	mlx_loop_hook(cub->graphic.mlx, raycasting, cub);
	//mlx_destroy_image(cub->graphic.mlx, cub->graphic.img);
	mlx_loop(cub->graphic.mlx);// Inicia la randeriazacion de la ventana
}
