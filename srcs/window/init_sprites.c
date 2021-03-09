/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:55:26 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/08 14:02:56 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Inicializa toda la configuracion del lanzamiento de rayos para los sprites
*/
void	init_sprites(t_cub3d *cub)
{
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

	//after sorting the sprites, do the projection and draw them
	i = 0;
	while (i < cub->map.count_sprites)
	{
		//translate sprite position to relative to camera
		spritex = cub->sprites[cub->spriteorder[i]].x - cub->p.posx;
		spritey = cub->sprites[cub->spriteorder[i]].y - cub->p.posy;

		//transform sprite with the inverse camera matrix
		// [ planeX   dirX ] -1                                       [ dirY      -dirX ]
		// [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
		// [ planeY   dirY ]                                          [ -planeY  planeX ]

		invdet = 1.0 / (cub->p.planex * cub->p.diry - cub->p.diry * cub->p.planey);

		transformx = invdet * (cub->p.diry * spritex + cub->p.dirx * spritey);
		transformy = invdet * (-cub->p.planey * spritex + cub->p.planex * spritey);

		spritescreenx = (int)(cub->map.width / 2) * (1 + transformx / transformy);

		//parameters for scaling and moving the sprites
		spriteheight = fabs((int)cub->map.height / (transformy));

		//calculate lowest and highest pixel to fill in current stripe
		drawstarty = -spriteheight / 2 + cub->map.height / 2;
		if (drawstarty < 0)
			drawstarty = 0;
		drawendy = spriteheight / 2 + cub->map.height / 2;
		if (drawendy >= cub->map.height)
			drawendy = cub->map.height - 1;

		//calculate width of the sprite
		spritewidth = abs((int)(cub->map.height / (transformy)));
		drawstartx = -spritewidth / 2 + spritescreenx;
		if (drawstartx < 0)
			drawstartx = 0;
		drawendx = spritewidth / 2 + spritescreenx;
		if (drawendx >= cub->map.width)
			drawendx = cub->map.width - 1;

		//loop through every vertical stripe of the sprite on screen
		t_texture textur;
		int stripe;
		int texx;
		stripe = drawstartx;
		while (stripe < drawendx)
		{
			texx = (((int)256 * (stripe - (-spritewidth / 2 + spritescreenx)) * textur.width / spritewidth) / 256);
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) ZBuffer, with perpendicular distance
			if (transformy > 0 && stripe > 0 && stripe < cub->map.width && transformy < cub->zbuffer[stripe])
			{
				int y;

				y = drawstarty;
				while (y < drawendy)
				{
					// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
					int d;
					int texy;
					unsigned int color;

					d = y * 256 - cub->map.height * 128 + spriteheight * 128;//256 and 128 factors to avoid floats
					texy = ((d * textur.height) / spriteheight) / 256;
					color = textur.addr[textur.width * texy + texx];
					if((color & 0x00FFFFFF) != 0)
						my_mlx_pixel_put(cub, stripe, y, color);
//						set_pixel(cub, cub->map.width * stripe + y, color);
					y++;
				}
			}
			stripe++;
		}
	i++;
	}
}
