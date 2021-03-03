/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 19:15:52 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/03 15:43:55 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
** Ordena los sprites en funcion de la distancia al jugador
*/
static void		sort_sprites(t_cub3d *cub)
{
	int			i;
	int			k;
	t_sprite	tmp;

	if (cub->count_sprites == 0)
		return ;
	i = 0;
	while (i < cub->count_sprites)
	{
		cub->sprites[i].dist = hypot(cub->sprites[i].x - cub->graphic.player_pos_x,
		cub->sprites[i].y - cub->graphic.player_pos_y);
		i++;
	}
	i = 0;
	while (i < cub->count_sprites)
	{
		k = i;
		while (++k < cub->count_sprites)
		{
			if (cub->sprites[i].dist < cub->sprites[k].dist)
			{
				tmp = cub->sprites[i];
				cub->sprites[i] = cub->sprites[k];
				cub->sprites[i] = tmp;
			}
		}
		i++;
	}
}


/*
** Inicializa toda la configuracion del lanzamiento de rayos para los sprites
*/
static	t_sprite	init_sprite(t_cub3d *cub, t_sprite sprite)
{
	sprite.x = sprite.x - cub->graphic.player_pos_x;
	sprite.y = sprite.y - cub->graphic.player_pos_y;
	//sprite.inv_det = 1.0 / (cub->graphic.map_x * cub->graphic.player_dir_y - cub->graphic.player_dir_x * cub->graphic.map_y);//matriz inversa de la camara
	sprite.inv_det = 1.0 / (cub->graphic.player_plane_x * cub->graphic.player_dir_y - cub->graphic.player_dir_x * cub->graphic.player_plane_y);
	sprite.transform_x = sprite.inv_det * (cub->graphic.player_dir_y * sprite.x - cub->graphic.player_dir_x * sprite.y);
	sprite.transform_y = sprite.inv_det * (cub->graphic.player_plane_y * sprite.x + cub->graphic.player_plane_x * sprite.y);
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
	int			stripe;// franjas de pixels verticales
	int			y;
	int			d;
	t_texture	tex;

	stripe = spr.draw_start_x;
	tex = cub->sprite;
	while (stripe < spr.draw_end_x)
	{
//		spr.texture_x = int(256 * (x - (-spr.width / 2 + spr.screen_x)) * tex.width / spr.width);
		spr.texture_x = (stripe - (-spr.width / 2 + spr.screen_x)) * tex.width / spr.width;
	//ft_printf("hola %p\n", cub->zbuffer);
		if (spr.transform_y > 0 && stripe > 0 && stripe < cub->map.width && spr.transform_y < cub->zbuffer[stripe])// zbuffer almacena la distancia perpencicular
		{
			y = spr.draw_start_y;
			while (y < spr.draw_end_y)
			{
				d = (y) * 256 - cub->map.height * 128 + spr.height * 128;
				spr.texture_y = ((d * tex.height) / spr.height) / 256;
				spr.color = tex.addr[tex.width * spr.texture_y + spr.texture_x];// Obtieen el color actual de la textura
				if ((spr.color & 0x00FFFFFF) != 0)
					set_pixel(cub, cub->map.width * y * stripe, spr.color);
				y++;
			}
		}
		stripe++;
	}
}

/*
** Ordena los sprites, los inicializa y los dibuja
*/
void	draw_sprites(t_cub3d *cub)
{
	int	i;

	i = 0;
	sort_sprites(cub);
	while (i < cub->count_sprites)
	{
		draw_sprite(cub, init_sprite(cub, cub->sprites[i]));
//		ft_printf("churra %i %i \n", cub->count_sprites, i);
		i++;
	}
}


/*
void		set_sprites(t_cub3d *cub)
{
	size_t			y;
	size_t			x;
	size_t			i;

	cub->zbuffer = malloc(sizeof(double) * cub->map.width);
	cub->sprites = malloc(sizeof(t_sprite) * cub->count_sprites);
	y = -1;
	i = -1;
	while (cub->plan.plan[y++])
	{
		x = -1;
		while(cub->plan.plan[y][++x])
		{
			if (cub->plan.plan[y][x] == '2')
				cub->sprites[++i] = (t_sprite)
				{.
				y = (double)y + 0.5,
				.x = (double)x + 0.5,
				.dist = (double)0};
			}
		}
}
*/
