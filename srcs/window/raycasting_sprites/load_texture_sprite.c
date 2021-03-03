/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture_sprite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:12:01 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/03 16:44:45 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	load_textures_sprite(t_cub3d *cub)
{
	cub->sprite.texture = mlx_xpm_file_to_image(cub->graphic.mlx, cub->map.s,
	&cub->sprite.width, &cub->sprite.height);
///////////////////////////////////////////////
	cub->sprite.addr = (int *)mlx_get_data_addr(cub->sprite.texture, &cub->sprite.bpp,
	&cub->sprite.size_l, &cub->sprite.endian);
}
