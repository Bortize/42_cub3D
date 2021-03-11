/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 07:00:19 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/11 14:14:34 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline void	raycast(t_cub3d *cub, int col)
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
	ray.x = (int)(cub->rcast.wallx
		* (double)(cub->tex.walls[cub->rcast.side].width));
	if (cub->rcast.side <= 1 && cub->rcast.raydirx > 0)
		ray.x = cub->tex.walls[cub->rcast.side].width - ray.x - 1;
	if (cub->rcast.side >= 2 && cub->rcast.raydiry > 0)
		ray.x = cub->tex.walls[cub->rcast.side].width - ray.x - 1;
	increase_draw_texture(cub, ray, col);
}

inline void	draw_sprites(t_cub3d *cub)
{
	t_drawsprites drwspr;

	ft_bzero(&drwspr, sizeof(t_drawsprites));
	while (drwspr.i < cub->map.count_sprites)
	{
		init_raycast_sprites(cub, drwspr);
		sprite_low_hight_pixel_fill(&cub->map, &cub->spr);
		width_sprite(&cub->map, &cub->spr);
		drwspr.stripe = cub->spr.drawstartx;
		vertical_stripe_sprite_screen(cub, drwspr);
		drwspr.i++;
	}
}

void		raycast_init(t_cub3d *cub)
{
	int x;

	x = 0;
	refresh_screen(cub);
	while (x < cub->map.width)
	{
		raycast(cub, x);
		draws_sky_floor(cub, x);
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
