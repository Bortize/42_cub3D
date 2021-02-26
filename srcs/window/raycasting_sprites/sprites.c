/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 19:15:52 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/26 19:48:20 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
** Ordena los sprites en funcion de la distancia al jugador
*/
static void		sort_sprites(t_cub3d *cub)
{
	int		i;
	int		k;
	t_sprite	tmp;

	if (cub->sprt.count_sprites == 0)
		return ;
	i = -1;
	while (++i < cub->sprt.count_sprites)
		cub->sprites.sprite[i].dist = hypot(cub->sprites.sprite[i].x - cub->graphic.player_pos_x,
		cub->sprites.sprite[i].y - cub->graphic.player_pos_y);
	i = -1;
	while (++i < cub->sprt.count_sprites)
	{
		k = i;
		while (++k < cub->sprt.count_sprites)
		{
			if (cub->sprites.sprite[i].dist < cub->sprites.sprite[k].dist)
			{
				tmp = cub->sprites.sprite[i];
				cub->sprites.sprite[i] = cub->sprites.sprite[k];
				cub->sprites.sprite[i] = tmp;
			}
		}
	}
}

static	t_sprite	init_sprite(t_cub3d *cub, t_sprite sprite)
{
	sprite.x = sprite.x - cub->graphic.player_pos_x;
	sprite.y = sprite.y - cub->graphic.player_pos_y;
	sprite.inv_det = 1.0 / (cub->graphic.camera_x * cub->graphic.player_dir_y - cub->graphic.player_dir_x * cub->plane.y)
}

/*
** Ordena los sprites, los inicializa y los dibuja
*/
void	draw_sprites(t_cub3d *cub)
{
	size_t	i;

	i = -1;
	sort_sprites(cub);
	i = -1;
	while (++i < cub->sprt.count_sprites)
		draw_sprite(cub, init_sprite(cub, cub->sprites.sprite[i]));
}
