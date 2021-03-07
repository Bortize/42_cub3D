/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:11:39 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/07 13:52:50 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
** Ordena los sprites en funcion de la distancia al jugador de mas lejos a mas
** cerca
*/
void		sort_sprites(t_cub3d *cub)
{
	int			i;
	int			k;
	t_sprite	tmp;

	if (cub->map.count_sprites == 0)
		return ;
	i = 0;
	cub->spriteorder = malloc(sizeof(int) * cub->map.count_sprites);// reserva memoria para poder trabajr con el ordenamiento de sprites
	while (i < cub->map.count_sprites)
	{
		cub->spriteorder[i] = i;
		cub->sprites[i].dist = ((cub->p.posy - cub->sprites[i].y) * (cub->p.posy - cub->sprites[i].y) +
		(cub->p.posx - cub->sprites[i].x) * (cub->p.posx - cub->sprites[i].x));// calcula la distancia al jugador de todos los sprites en base a su posicion real
		i++;
	}
	i = 0;
 	while (i < cub->map.count_sprites)
 	{
 		k = i;
 		while (++k < cub->map.count_sprites)
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
