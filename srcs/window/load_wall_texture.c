/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_wall_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:01:36 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/05 14:51:08 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_wall_texture(t_cub3d *cub)
{
	cub->tex[0].img_tex = mlx_xpm_file_to_image(cub->mlx.init, cub->map.no,
		&cub->tex[0].width, &cub->tex[0].height);
	cub->tex[1].img_tex = mlx_xpm_file_to_image(cub->mlx.init, cub->map.so,
		&cub->tex[1].width, &cub->tex[1].height);
	cub->tex[2].img_tex = mlx_xpm_file_to_image(cub->mlx.init, cub->map.we,
		&cub->tex[2].width, &cub->tex[2].height);
	cub->tex[3].img_tex = mlx_xpm_file_to_image(cub->mlx.init, cub->map.ea,
		&cub->tex[3].width, &cub->tex[3].height);

	cub->tex[0].addr = (int *)mlx_get_data_addr(cub->tex[0].img_tex, &cub->tex[0].bpp,
		&cub->tex[0].size_line, &cub->tex[0].endian);
	cub->tex[1].addr = (int *)mlx_get_data_addr(cub->tex[1].img_tex, &cub->tex[1].bpp,
		&cub->tex[1].size_line, &cub->tex[1].endian);
	cub->tex[2].addr = (int *)mlx_get_data_addr(cub->tex[2].img_tex, &cub->tex[2].bpp,
		&cub->tex[2].size_line, &cub->tex[2].endian);
	cub->tex[3].addr = (int *)mlx_get_data_addr(cub->tex[3].img_tex, &cub->tex[3].bpp,
		&cub->tex[3].size_line, &cub->tex[3].endian);
}
