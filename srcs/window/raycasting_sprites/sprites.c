/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 19:15:52 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/01 16:19:04 by bgomez-r         ###   ########.fr       */
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
/*
** Inicializa toda la configuracion del lanzamiento de rayos para los sprites
*/
static	t_sprite	init_sprite(t_cub3d *cub, t_sprite sprite)
{
	sprite.x = sprite.x - cub->graphic.player_pos_x;
	sprite.y = sprite.y - cub->graphic.player_pos_y;
	sprite.inv_det = 1.0 / (cub->graphic.map_x * cub->graphic.player_dir_y - cub->graphic.player_dir_x * cub->graphic.map_y);
	sprite.transform_x = sprite.inv_det * (cub->graphic.player_dir_y * sprite.x - cub->graphic.player_dir_x * sprite.y);
	sprite.transform_y = sprite.inv_det * (cub->graphic.map_y * sprite.x + cub->graphic.map_x * sprite.y);
	sprite.screen_x = (int)((cub->map.width / 2) * (1 + sprite.transform_x / sprite.transform_y));// La profundidad dentro de la pantalla
	sprite.height = abs((int)(cub->map.height / (sprite.transform_y)));// Calcula la altura del sprite en pantalla
	// Calcula el pixel mas alto y mas bajo para rellenar la franja atual
	sprite.draw_start_y = -sprite.height / 2 + cub->map.height / 2;
	if (sprite.draw_start_y < 0)
		sprite.draw_start_y = 0;
	sprite.draw_end_y = sprite.height / 2 + cub->map.height / 2;
	if (sprite.draw_end_y >= cub->map.height)
		sprite.draw_end_y = cub->map.height - 1;
// Calcula el ancho del sprite
	sprite.width = abs((int)(cub->map.height / (sprite.transform_y)));
	sprite.draw_start_x = -sprite.width / 2 + sprite.screen_x;
	if (sprite.draw_start_x < 0)
		sprite.draw_start_x = 0;
	sprite.draw_end_x = sprite.width / 2 + sprite.screen_x;
	if (sprite.draw_end_x >= cub->map.width)
		sprite.draw_end_x = cub->map.width - 1;
	return (sprite);
}

static void		draw_sprite(t_cub3d *cub, t_sprite spr)
{
	int				x;
	int				y;
	int				d;
	t_texture	tex;

	x = spr.draw_start_x - 1;
	tex = cub->sprite;
	while (++x < spr.draw_end_x)
	{
//		spr.texture_x = int(256 * (x - (-spr.width / 2 + spr.screen_x)) * tex.width / spr.width);
		spr.texture_x = (x - (-spr.width / 2 + spr.screen_x)) * tex.width / spr.width;
		if (spr.transform_y > 0 && x > 0 && x < cub->map.width && spr.transform_y < cub->zbuffer[x])
		{
			y = spr.start_y - 1;
			while (++y < spr.end_y)
			{
				d = (y) * 256 - cub->map.height * 128 + spr.height * 128;
				spr.texture_y = ((d * tex.height) / spr.height) / 256;
				spr.color = tex.ptr[tex.width * spr.texture_y + spr.texture_x];
				if ((spr.color & 0x00ffffff) != 0)
					set_pixel(cub, cub->map.width * y * x, spr.color);
			}
		}
	}
}

/*
** Ordena los sprites, los inicializa y los dibuja
*/
void	draw_sprites(t_cub3d *cub)
{
	int	i;

	i = -1;
	sort_sprites(cub);
	i = -1;
	while (++i < cub->sprt.count_sprites)
		draw_sprite(cub, init_sprite(cub, cub->sprites.sprite[i]));
}



void		set_sprites(t_cub3d *cub)
{
	size_t			y;
	size_t			x;
	size_t			i;

	cub->zbuffer = malloc(sizeof(double) * cub->map.width);
	cub->sprites.sprite = malloc(sizeof(t_sprite) * cub->sprt.count_sprites);
	y = -1;
	i = -1;
	while (cub->plan.plan[y++])
	{
		x = -1;
		while(cub->plan.plan[y][++x])
		{
			if (cub->plan.plan[y][x] == '2')
				cub->sprites.sprite[++i] = (t_sprite)
				{.
				y = (double)y + 0.5,
				.x = (double)x + 0.5,
				.dist = (double)0};
			}
		}
}
