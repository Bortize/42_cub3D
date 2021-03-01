/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:53:34 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/01 16:21:21 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"
/*
** Convierte las textuas en imagenes euclidianas que son enviadas a la
** ventana.
*/
void	load_textures(t_cub3d *cub)
{
	cub->text[0].img_text = mlx_xpm_file_to_image(cub->graphic.mlx, cub->map.no,
	&cub->text[0].width_text, &cub->text[0].height_text);

	cub->text[1].img_text = mlx_xpm_file_to_image(cub->graphic.mlx, cub->map.so,
	&cub->text[1].width_text, &cub->text[1].height_text);

	cub->text[2].img_text = mlx_xpm_file_to_image(cub->graphic.mlx, cub->map.we,
	&cub->text[2].width_text, &cub->text[2].height_text);

	cub->text[3].img_text = mlx_xpm_file_to_image(cub->graphic.mlx, cub->map.ea,
	&cub->text[3].width_text, &cub->text[3].height_text);

//////////////////////////////////////////////////////////////////////////////////
	cub->text[0].addr = (int *)mlx_get_data_addr(cub->text[0].img_text, &cub->text[0].bpp,
	&cub->text[0].size_line, &cub->text[0].endian);

	cub->text[1].addr = (int *)mlx_get_data_addr(cub->text[1].img_text, &cub->text[1].bpp,
	&cub->text[1].size_line, &cub->text[1].endian);

	cub->text[2].addr = (int *)mlx_get_data_addr(cub->text[2].img_text, &cub->text[2].bpp,
	&cub->text[2].size_line, &cub->text[2].endian);

	cub->text[3].addr = (int *)mlx_get_data_addr(cub->text[3].img_text, &cub->text[3].bpp,
	&cub->text[3].size_line, &cub->text[3].endian);
}
