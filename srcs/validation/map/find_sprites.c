/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:18:21 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/10 00:22:27 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Creates a new instance of the structure and saves the values of the position
** where the sprite was found on the map
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
