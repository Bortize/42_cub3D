/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:03:22 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/05 14:48:36 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_sprite_texture(t_cub3d *cub)
{
	cub->tex[4].img_tex = mlx_xpm_file_to_image(cub->mlx.init, cub->map.s,
	&cub->tex[4].width, &cub->tex[4].height);
//	cub->tex[1].img_tex = mlx_xpm_file_to_image(cub->mlx.init, cub->map.s,
//		&cub->tex[1].width, &cub->tex[1].height);

	cub->tex[4].addr = (int *)mlx_get_data_addr(cub->tex[4].img_tex, &cub->tex[4].bpp,
		&cub->tex[4].size_line, &cub->tex[4].endian);
//	cub->tex[1].addr = (int *)mlx_get_data_addr(cub->tex[1].img_tex, &cub->tex[1].bpp,
//		&cub->tex[1].size_line, &cub->tex[1].endian);
}
