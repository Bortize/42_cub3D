/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:56:02 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/04 23:07:21 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_mlx(t_cub3d *cub)
{
	if (!(cub->mlx.init = mlx_init()))
		print_error("Fallo al iniciar MLX");
	cub->mlx.win = mlx_new_window(cub->mlx.init, cub->map.width,
		cub->map.height, "cub3D");
	cub->mlx.img = mlx_new_image(cub->mlx.init, cub->map.width, cub->map.height);
	cub->mlx.addr = mlx_get_data_addr(cub->mlx.img, &cub->mlx.bpp,
		&cub->mlx.line_len, &cub->mlx.endian);
}
