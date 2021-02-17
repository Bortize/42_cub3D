/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:53:34 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/17 13:08:23 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"
/*
** Convierte las textuas en imagenes euclidianas que son enviadas a la
** ventana.
*/
void	load_textures(t_cub3d *cub)
{
	cub->no_text.img_text = mlx_xpm_file_to_image(cub->graphic.mlx, cub->map.no,
	&cub->no_text.width_text, &cub->no_text.height_text);

	cub->so_text.img_text = mlx_xpm_file_to_image(cub->graphic.mlx, cub->map.so,
	&cub->so_text.width_text, &cub->so_text.height_text);

	cub->we_text.img_text = mlx_xpm_file_to_image(cub->graphic.mlx, cub->map.we,
	&cub->we_text.width_text, &cub->we_text.height_text);

	cub->ea_text.img_text = mlx_xpm_file_to_image(cub->graphic.mlx, cub->map.ea,
	&cub->ea_text.width_text, &cub->ea_text.height_text);

//////////////////////////////////////////////////////////////////////////////////

	cub->so_text.addr = (int *)mlx_get_data_addr(cub->so_text.img_text, &cub->so_text.bpp,
	&cub->so_text.size_line, &cub->so_text.endian);

	cub->no_text.addr = (int *)mlx_get_data_addr(cub->no_text.img_text, &cub->no_text.bpp,
	&cub->so_text.size_line, &cub->so_text.endian);


	cub->we_text.addr = (int *)mlx_get_data_addr(cub->we_text.img_text, &cub->we_text.bpp,
	&cub->we_text.size_line, &cub->we_text.endian);

	cub->ea_text.addr = (int *)mlx_get_data_addr(cub->ea_text.img_text, &cub->ea_text.bpp,
	&cub->ea_text.size_line, &cub->ea_text.endian);
}
