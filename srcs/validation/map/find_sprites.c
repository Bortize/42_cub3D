/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:18:21 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/09 01:38:55 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Crea una nueva instancia de la estructura y guarda los valroes de la
** posicion en donde se encontro el sprite en el mapa
*/

void	find_sprites(t_cub3d *cub)
{
	int x;
	int y;
	int i;
	int s;

	i = 0;
	x = 0;
	s = 0;
	y = 0;
	cub->sprites = malloc(sizeof(t_sprite) * cub->map.count_sprites);
	while ((cub->plan.one_line_plan[i]) != '\0')
	{
		if (cub->plan.one_line_plan[i] == 'p')
		{
			x = 0;
			y++;
		}
		if (cub->plan.one_line_plan[i] == '2')
		{
			cub->sprites[s].x = x - 0.5;
			cub->sprites[s].y = y + 0.5;
			s++;
		}
		i++;
		x++;
	}
}
