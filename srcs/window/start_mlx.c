/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:47:07 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/16 16:04:46 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_mlx(t_cub3d *cub)
{
	int	width;
	int	height;

	if (!(cub->mlx.init = mlx_init()))
		print_error("Failure to start MLX\n");
	if (!cub->bmp_flag)
	{
		mlx_get_screen_size(cub->mlx.init, &width, &height);
		if (cub->map.width > width)
			cub->map.width = width;
		if (cub->map.height > height)
			cub->map.height = height;
		cub->mlx.win = mlx_new_window(cub->mlx.init, cub->map.width,
			cub->map.height, "cub3D");
	}
	cub->mlx.img = mlx_new_image(cub->mlx.init, cub->map.width,
		cub->map.height);
	cub->mlx.addr = mlx_get_data_addr(cub->mlx.img, &cub->mlx.bpp,
		&cub->mlx.line_len, &cub->mlx.endian);
}
