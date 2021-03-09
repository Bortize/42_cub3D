/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:11:39 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/08 21:14:29 by bgomez-r         ###   ########.fr       */
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
	int			j;
	t_sprite	tmp;
	int			sorted;

	if (cub->map.count_sprites == 0)
		return ;
	i = 0;
	//cub->spriteorder = malloc(sizeof(int) * cub->map.count_sprites);// reserva memoria para poder trabajr con el ordenamiento de sprites
	while (i < cub->map.count_sprites)
	{
		//cub->spriteorder[i] = i;
		cub->sprites[i].dist = ((cub->p.posy - cub->sprites[i].y) * (cub->p.posy - cub->sprites[i].y) +
		(cub->p.posx - cub->sprites[i].x) * (cub->p.posx - cub->sprites[i].x));// calcula la distancia al jugador de todos los sprites en base a su posicion real
		i++;
	}
	i = 0;
	while (i < cub->map.count_sprites)
 	{
		sorted = 0;
 		j = i;
 		while (++j < cub->map.count_sprites)
 		{
 			if (cub->sprites[i].dist < cub->sprites[j].dist)
 			{
 				tmp = cub->sprites[i];
 				cub->sprites[i] = cub->sprites[j];
 				cub->sprites[j] = tmp;
				sorted = !sorted;
 			}
 			i++;
 		}
		if (!sorted)
			break ;
 	}
}
