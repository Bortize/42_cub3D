/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 07:00:19 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/05 14:57:45 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	raycast(t_cub3d *cub)
{
	while (cub->rcast.x < cub->map.width)
	{
		//calculate ray position and direction
		cub->rcast.camerax = 2 * cub->rcast.x / (double)cub->map.width - 1;
		cub->rcast.raydirx = cub->p.dirx + cub->p.planex * cub->rcast.camerax;
		cub->rcast.raydiry = cub->p.diry + cub->p.planey * cub->rcast.camerax;
		//which box of the map we're in
		cub->rcast.mapx = (int)cub->p.posx;
		cub->rcast.mapy = (int)cub->p.posy;
		//length of ray from one x or y-side to next x or y-side
		cub->rcast.deltadistx = fabs(1 / cub->rcast.raydirx);
		cub->rcast.deltadistx = fabs(1 / cub->rcast.raydiry);

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
		while (cub->rcast.hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (cub->rcast.sidedistx < cub->rcast.sidedisty)
			{
				cub->rcast.sidedistx += cub->rcast.deltadistx;
				cub->rcast.mapx += cub->rcast.stepx;
				cub->rcast.side = 0;
			}
			else
			{
				cub->rcast.sidedisty += cub->rcast.deltadisty;
				cub->rcast.mapy += cub->rcast.stepy;
				cub->rcast.side = 1;
			}
			//Check if ray has hit a wall
			if(cub->plan.plan[cub->rcast.mapx][cub->rcast.mapy] > 0)
				cub->rcast.hit = 1;
		}

		//Calculate distance of perpendicular ray (Euclidean distance will give fisheye effect!)
		if(cub->rcast.side == 0)
			cub->rcast.perpwalldist = (cub->rcast.mapx - cub->p.posx + (1 - cub->rcast.stepx) / 2) / cub->rcast.raydirx;
		else
			cub->rcast.perpwalldist = (cub->rcast.mapy - cub->p.posy + (1 - cub->rcast.stepy) / 2) / cub->rcast.raydiry;

		//Calculate height of line to draw on screen
		cub->win.lineheight = (int)(cub->map.height / cub->rcast.perpwalldist);

		//calculate lowest and highest pixel to fill in current stripe
		cub->win.drawstart = -cub->win.lineheight / 2 + cub->map.height / 2;
		if (cub->win.drawstart < 0)
			cub->win.drawstart = 0;
		cub->win.drawend = cub->win.lineheight / 2 + cub->map.height / 2;
		if (cub->win.drawend >= cub->map.height)
			cub->win.drawend = cub->map.height - 1;

		//texturing calculations
		cub->rcast.texnum = cub->plan.plan[cub->rcast.mapx][cub->rcast.mapy] - 1;//1 subtracted from it so that texture 0 can be used!

		//calculate value of wallX
		if (cub->rcast.side == 0)
			cub->rcast.wallx = cub->p.posy + cub->rcast.perpwalldist * cub->rcast.raydiry;
		else
			cub->rcast.wallx = cub->p.posx + cub->rcast.perpwalldist * cub->rcast.raydirx;
		cub->rcast.wallx -= floor((cub->rcast.wallx));

		//x coordinate on the texture
		cub->tex.x = int(cub->rcast.wallx * double(cub->tex.width));
		if (cub->rcast.side == 0 && cub->rcast.raydirx > 0)
			cub->tex.x = cub->tex.width - cub->tex.x - 1;
		if (cub->rcast.side == 1 && cub->rcast.raydiry < 0)
			cub->tex.x = cub->tex.width - cub->tex.x - 1;

		// TODO: an integer-only bresenham or DDA like algorithm could make the texture coordinate stepping faster
		// How much to increase the texture coordinate per screen pixel
		cub->tex.step = 1.0 * cub->tex.height / cub->win.lineheight;
		// Starting texture coordinate
		cub->tex.pos = (cub->win.drawstart - cub->map.height / 2 + cub->win.lineheight / 2) * cub->tex.step;
		cub->rcast.y = cub->win.drawstart;
		while (cub->rcast.y < cub->win.drawend)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			cub->tex.y = (int)cub->tex.pos & (cub->tex.height - 1);
			cub->tex.pos += cub->tex.step;
			unsigned int	color;
			color = cub->tex.addr[cub->rcast.texnum][cub->tex->height * cub->tex.y + cub->tex.x];
			if(cub->rcast.side == 1) color = (color >> 1) & 8355711;
		}
	}

}
