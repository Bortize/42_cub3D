/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:55:26 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/07 14:14:23 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Inicializa toda la configuracion del lanzamiento de rayos para los sprites
*/
void	init_sprite(t_cub3d *cub)
{
	double spritex;
	double spritey;
	double invdet;
	double transformx;
	double transformy;
	int spritescreenx;
	int i;

	//after sorting the sprites, do the projection and draw them
	i = 0;
	while (i < cub->map.count_sprites)
	{
		//translate sprite position to relative to camera
		spritex = cub->sprites[cub->spriteorder[i]].x - cub->p.posx;
		spritey = cub->sprites[cub->spriteorder[i]].y - cub->p.posy;
		ft_printf("hello %i \n", cub->sprites[i]);

		//transform sprite with the inverse camera matrix
		// [ planeX   dirX ] -1                                       [ dirY      -dirX ]
		// [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
		// [ planeY   dirY ]                                          [ -planeY  planeX ]

		invdet = 1.0 / (cub->p.planex * cub->p.diry - cub->p.diry * cub->p.planey);

		transformx = invdet * (cub->p.diry * spritex + cub->p.dirx * spritey);
		transformy = invdet * (-cub->p.planey * spritex + cub->p.planex * spritey);

		spritescreenx = (int)(cub->map.width / 2) * (1 + transformx / transformy);

		//parameters for scaling and moving the sprites
	i++;
	}
}
