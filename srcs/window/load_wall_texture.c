/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_wall_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:01:36 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/13 09:49:53 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline static void	file_to_image(t_cub3d *cub)
{
	int i;

	cub->tex.walls[0].img_tex = mlx_xpm_file_to_image(cub->mlx.init,
		cub->map.no, &cub->tex.walls[0].width, &cub->tex.walls[0].height);
	cub->tex.walls[1].img_tex = mlx_xpm_file_to_image(cub->mlx.init,
		cub->map.so, &cub->tex.walls[1].width, &cub->tex.walls[1].height);
	cub->tex.walls[2].img_tex = mlx_xpm_file_to_image(cub->mlx.init,
		cub->map.we, &cub->tex.walls[2].width, &cub->tex.walls[2].height);
	cub->tex.walls[3].img_tex = mlx_xpm_file_to_image(cub->mlx.init,
		cub->map.ea, &cub->tex.walls[3].width, &cub->tex.walls[3].height);
	i = 0;
	while (i < 4)
		if (!cub->tex.walls[i++].img_tex)
			print_error("Some wall texture(s) failed to load");

}

inline static void	get_data(t_cub3d *cub)
{
	cub->tex.walls[0].addr =
		(int *)mlx_get_data_addr(cub->tex.walls[0].img_tex,
		&cub->tex.walls[0].bpp, &cub->tex.walls[0].size_line,
		&cub->tex.walls[0].endian);
	cub->tex.walls[1].addr =
		(int *)mlx_get_data_addr(cub->tex.walls[1].img_tex,
		&cub->tex.walls[1].bpp, &cub->tex.walls[1].size_line,
		&cub->tex.walls[1].endian);
	cub->tex.walls[2].addr =
		(int *)mlx_get_data_addr(cub->tex.walls[2].img_tex,
		&cub->tex.walls[2].bpp, &cub->tex.walls[2].size_line,
		&cub->tex.walls[2].endian);
	cub->tex.walls[3].addr =
		(int *)mlx_get_data_addr(cub->tex.walls[3].img_tex,
		&cub->tex.walls[3].bpp, &cub->tex.walls[3].size_line,
		&cub->tex.walls[3].endian);
}

void				load_wall_texture(t_cub3d *cub)
{
	file_to_image(cub);
	get_data(cub);
}
