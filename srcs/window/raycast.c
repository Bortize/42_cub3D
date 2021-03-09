/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 07:00:19 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/10 00:44:19 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_cub3d *cub, int col)
{
	t_raycalc	ray;

	ft_bzero(&ray, sizeof(t_raycalc));
	//calculate ray position and direction
	cub->rcast.camerax = 2 * col / (double)cub->map.width - 1;
	cub->rcast.raydirx = cub->p.dirx + cub->p.planex * cub->rcast.camerax;
	cub->rcast.raydiry = cub->p.diry + cub->p.planey * cub->rcast.camerax;
	//which box of the map we're in
	cub->rcast.mapx = (int)(cub->p.posx);
	cub->rcast.mapy = (int)(cub->p.posy);
	//length of ray from one x or y-side to next x or y-side
	cub->rcast.deltadistx = fabs(1 / cub->rcast.raydirx);
	cub->rcast.deltadisty = fabs(1 / cub->rcast.raydiry);

	//calculate step and initial sideDist
	if (cub->rcast.raydirx < 0)
	{
		cub->rcast.stepx = -1;
		cub->rcast.sidedistx = (cub->p.posx - cub->rcast.mapx) * cub->rcast.deltadistx;
	}
	else
	{
		cub->rcast.stepx = 1;
		cub->rcast.sidedistx = (cub->rcast.mapx + 1.0 - cub->p.posx) * cub->rcast.deltadistx;
	}
	if (cub->rcast.raydiry < 0)
	{
		cub->rcast.stepy = -1;
		cub->rcast.sidedisty = (cub->p.posy - cub->rcast.mapy) * cub->rcast.deltadisty;
	}
	else
	{
		cub->rcast.stepy = 1;
		cub->rcast.sidedisty = (cub->rcast.mapy + 1.0 - cub->p.posy) * cub->rcast.deltadisty;
	}

	//perform DDA
	int hit = 0;
	while (hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (cub->rcast.sidedistx < cub->rcast.sidedisty)
		{
			cub->rcast.sidedistx += cub->rcast.deltadistx;
			cub->rcast.mapx += cub->rcast.stepx;
			cub->rcast.side = 0 + (cub->rcast.raydirx < 0);
		}
		else
		{
			cub->rcast.sidedisty += cub->rcast.deltadisty;
			cub->rcast.mapy += cub->rcast.stepy;
			cub->rcast.side = 2 + (cub->rcast.raydiry > 0);
		}
		if (cub->plan.plan[cub->rcast.mapy][cub->rcast.mapx] == '1')
			hit = 1;
	}

	//Calculate distance of perpendicular ray (Euclidean distance will give fisheye effect!)
	if(cub->rcast.side <= 1)
		cub->rcast.perpwalldist = (cub->rcast.mapx - cub->p.posx + (1 - cub->rcast.stepx) / 2) / cub->rcast.raydirx;
	else
		cub->rcast.perpwalldist = (cub->rcast.mapy - cub->p.posy + (1 - cub->rcast.stepy) / 2) / cub->rcast.raydiry;

	cub->zbuffer[col] = cub->rcast.perpwalldist;
	//Calculate height of line to draw on screen
	cub->win.lineheight = (int)(cub->map.height / cub->rcast.perpwalldist);
		//calculate lowest and highest pixel to fill in current stripe
	cub->win.drawstart = -cub->win.lineheight / 2 + cub->map.height / 2;
	if (cub->win.drawstart < 0)
		cub->win.drawstart = 0;
	cub->win.drawend = cub->win.lineheight / 2 + cub->map.height / 2;
	if (cub->win.drawend >= cub->map.height)
		cub->win.drawend = cub->map.height - 1;
	if (cub->win.drawend < 0)
		cub->win.drawend = 0;


	//texturing calculations
	//cub->rcast.texnum = cub->plan.plan[cub->rcast.mapy][cub->rcast.mapx] - 1;//1 subtracted from it so that texture 0 can be used!
		//calculate value of wallX
	if (cub->rcast.side <= 1)
		cub->rcast.wallx = cub->p.posy + cub->rcast.perpwalldist * cub->rcast.raydiry;
	else
		cub->rcast.wallx = cub->p.posx + cub->rcast.perpwalldist * cub->rcast.raydirx;
	cub->rcast.wallx -= (floor)(cub->rcast.wallx);
	//x coordinate on the texture
	ray.x = (int)(cub->rcast.wallx * (double)(cub->tex.walls[cub->rcast.side].width));
	if (cub->rcast.side <= 1 && cub->rcast.raydirx > 0)
		ray.x = cub->tex.walls[cub->rcast.side].width - ray.x - 1;
	if (cub->rcast.side >= 2 && cub->rcast.raydiry > 0)
		ray.x = cub->tex.walls[cub->rcast.side].width - ray.x - 1;

	t_texture *text;

	text = &cub->tex.walls[cub->rcast.side];
	// TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
	// How much to increase the texture coordinate per screen pixel
	ray.step = 1.0 * text->height / cub->win.lineheight;
	// Starting texture coordinate
	ray.pos = (cub->win.drawstart - cub->map.height / 2 + cub->win.lineheight / 2) * ray.step;
	cub->rcast.y = cub->win.drawstart;
	while (cub->rcast.y < cub->win.drawend)
	{
		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		ray.y = (int)ray.pos & (text->height - 1);
		ray.pos += ray.step;
		int	color;
		color = text->addr[text->width * ray.y + ray.x];
		if(cub->rcast.side % 2)
			color = (color >> 1) & 8355711;
		my_mlx_pixel_put(cub, col, cub->rcast.y, color);
		cub->rcast.y++;
	}
}

void	draw_sprites(t_cub3d *cub)
{
	//sort_sprites(cub);
	//after sorting the sprites, do the projection and draw them
//	init_sprites(cub);
	int i;
	double spritex;
	double spritey;
	double invdet;
	double transformx;
	double transformy;
	int spritescreenx;
//	int	vmovescreen;
	int	spriteheight;
	int drawstarty;
	int	drawendy;
	int	spritewidth;
	int	drawstartx;
	int drawendx;

	int y;
	int d;
	int texy;
	int stripe;
	int texx;
	unsigned int color;
	//after sorting the sprites, do the projection and draw them
	i = 0;
	while (i < cub->map.count_sprites)
	{
		//translate sprite position to relative to camera
		spritex = cub->sprites[i].x - cub->p.posx;
		spritey = cub->sprites[i].y - cub->p.posy;

		//transform sprite with the inverse camera matrix
		// [ planeX   dirX ] -1                                       [ dirY      -dirX ]
		// [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
		// [ planeY   dirY ]                                          [ -planeY  planeX ]

		invdet = 1.0 / (cub->p.planex * cub->p.diry - cub->p.dirx * cub->p.planey);

		transformx = invdet * (cub->p.diry * spritex - cub->p.dirx * spritey);
		transformy = invdet * (-cub->p.planey * spritex + cub->p.planex * spritey);

		spritescreenx = (int)((cub->map.width / 2) * (1 + transformx / transformy));

		//parameters for scaling and moving the sprites
		spriteheight = abs((int)(cub->map.height / transformy));

		//calculate lowest and highest pixel to fill in current stripe
		drawstarty = -spriteheight / 2 + cub->map.height / 2;
		if (drawstarty < 0)
			drawstarty = 0;
		drawendy = spriteheight / 2 + cub->map.height / 2;
		if (drawendy >= cub->map.height)
			drawendy = cub->map.height - 1;

		//calculate width of the sprite
		spritewidth = abs((int)(cub->map.height / transformy));
		drawstartx = -spritewidth / 2 + spritescreenx;
		if (drawstartx < 0)
			drawstartx = 0;
		drawendx = spritewidth / 2 + spritescreenx;
		if (drawendx >= cub->map.width)
			drawendx = cub->map.width - 1;

		//loop through every vertical stripe of the sprite on screen
		//t_texture textur;
		stripe = drawstartx;
		while (stripe < drawendx)
		{
			texx = (int)(256 * (stripe - (-spritewidth / 2 + spritescreenx)) * cub->tex.sprite[0].width / spritewidth) / 256;
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) ZBuffer, with perpendicular distance
			if (transformy > 0 && stripe > 0 && stripe < cub->map.width && transformy < cub->zbuffer[stripe])
			{
				y = drawstarty;
				while (y < drawendy)
				{
//					ft_printf("veces %i \n", y);
					// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow


					d = y * 256 - cub->map.height * 128 + spriteheight * 128;//256 and 128 factors to avoid floats
					texy = ((d * cub->tex.sprite[0].height) / spriteheight) / 256;
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
