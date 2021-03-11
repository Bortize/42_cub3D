/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 07:00:19 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/11 03:00:21 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_cub3d *cub, int col)
{
	t_raycalc	ray;

	ft_bzero(&ray, sizeof(t_raycalc));
	init_raycast(cub, col);
	step_and_initial_sidedist(cub);
	perfom_dda(&cub->rcast, &cub->plan);
	distance_perp_ray(&cub->rcast, &cub->p);
	cub->zbuffer[col] = cub->rcast.perpwalldist;
	cub->win.lineheight = (int)(cub->map.height / cub->rcast.perpwalldist);
	low_hight_pixel(&cub->win, &cub->map);
	texture_calculations(&cub->rcast, &cub->p);
	ray.x = (int)(cub->rcast.wallx * (double)(cub->tex.walls[cub->rcast.side].width));
	if (cub->rcast.side <= 1 && cub->rcast.raydirx > 0)
		ray.x = cub->tex.walls[cub->rcast.side].width - ray.x - 1;
	if (cub->rcast.side >= 2 && cub->rcast.raydiry > 0)
		ray.x = cub->tex.walls[cub->rcast.side].width - ray.x - 1;
	increase_draw_texture(cub, ray, col);
}

void	draw_sprites(t_cub3d *cub)
{
	int i;

	int y;
	int d;
	int texy;
	int stripe;
	int texx;
	unsigned int color;

	i = 0;
	while (i < cub->map.count_sprites)
	{
		cub->spr.spritex = cub->sprites[i].x - cub->p.posx;
		cub->spr.spritey = cub->sprites[i].y - cub->p.posy;
		cub->spr.invdet = 1.0 / (cub->p.planex * cub->p.diry - cub->p.dirx * cub->p.planey);
		cub->spr.transformx = cub->spr.invdet * (cub->p.diry * cub->spr.spritex - cub->p.dirx * cub->spr.spritey);
		cub->spr.transformy = cub->spr.invdet * (-cub->p.planey * cub->spr.spritex + cub->p.planex * cub->spr.spritey);
		cub->spr.spritescreenx = (int)((cub->map.width / 2) * (1 + cub->spr.transformx / cub->spr.transformy));
		cub->spr.spriteheight = abs((int)(cub->map.height / cub->spr.transformy));
		sprite_low_hight_pixel_fill(&cub->map, &cub->spr);
		width_sprite(&cub->map, &cub->spr);

		//loop through every vertical stripe of the sprite on screen
		stripe = cub->spr.drawstartx;
		while (stripe < cub->spr.drawendx)
		{
			texx = (int)(256 * (stripe - (-cub->spr.spritewidth / 2 + cub->spr.spritescreenx)) * cub->tex.sprite[0].width / cub->spr.spritewidth) / 256;
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) ZBuffer, with perpendicular distance
			if (cub->spr.transformy > 0 && stripe > 0 && stripe < cub->map.width && cub->spr.transformy < cub->zbuffer[stripe])
			{
				y = cub->spr.drawstarty;
				while (y < cub->spr.drawendy)
				{
//					ft_printf("veces %i \n", y);
					// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow


					d = y * 256 - cub->map.height * 128 + cub->spr.spriteheight * 128;//256 and 128 factors to avoid floats
					texy = ((d * cub->tex.sprite[0].height) / cub->spr.spriteheight) / 256;
					color = cub->tex.sprite[0].addr[cub->tex.sprite[0].width * texy + texx];
					if((color & 0x00FFFFFF) != 0)
						my_mlx_pixel_put(cub, stripe, y, color);
//						set_pixel(cub, cub->map.width * cub->zbuffer[stripe] + y, color);
					y++;
				}
			}
			stripe++;
		}
	i++;
	}
}

void raycast_init(t_cub3d *cub)
{
	int x;

	x = 0;
	refresh_screen(cub);
	while (x < cub->map.width)
	{
		raycast(cub, x);
		draws_sky_floor(cub, x);
//		init_sprites(cub, x);
		x++;
	}
	sort_sprites(cub);
	draw_sprites(cub);
	if (cub->bmp_flag)
	{
		screenshot(cub);
		exit(EXIT_SUCCESS);
	}
	mlx_put_image_to_window(cub->mlx.init, cub->mlx.win, cub->mlx.img, 0, 0);
}
