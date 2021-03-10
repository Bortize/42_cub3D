/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:03:22 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/10 19:13:40 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_sprite_texture(t_cub3d *cub)
{
	cub->tex.sprite[0].img_tex = mlx_xpm_file_to_image(cub->mlx.init,
	cub->map.s, &cub->tex.sprite[0].width, &cub->tex.sprite[0].height);
	cub->tex.sprite[0].addr =
	(int *)mlx_get_data_addr(cub->tex.sprite[0].img_tex,
	&cub->tex.sprite[0].bpp, &cub->tex.sprite[0].size_line,
	&cub->tex.sprite[0].endian);
}
