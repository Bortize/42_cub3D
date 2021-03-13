/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:47:07 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/13 13:06:25 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_mlx(t_cub3d *cub)
{
	if (!(cub->mlx.init = mlx_init()))
		print_error("Failure to start MLX");
	printf("resolution %i %i\n", cub->map.width, cub->map.height);
	cub->mlx.win = mlx_new_window(cub->mlx.init, cub->map.width,
		cub->map.height, "cub3D");
	cub->mlx.img = mlx_new_image(cub->mlx.init, cub->map.width,
		cub->map.height);
	cub->mlx.addr = mlx_get_data_addr(cub->mlx.img, &cub->mlx.bpp,
		&cub->mlx.line_len, &cub->mlx.endian);
}
