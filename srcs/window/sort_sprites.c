/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 12:11:39 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/11 14:11:12 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

inline static void	calc_distance(t_cub3d *cub, int i)
{
	while (i < cub->map.count_sprites)
	{
		cub->sprites[i].dist = ((cub->p.posy - cub->sprites[i].y)
			* (cub->p.posy - cub->sprites[i].y) +
		(cub->p.posx - cub->sprites[i].x) * (cub->p.posx - cub->sprites[i].x));
		i++;
	}
}

inline static void	bubble_sort(t_cub3d *cub, int i)
{
	t_sprite	tmp;
	int			sorted;
	int			j;

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

/*
** Sort the sprites according to the distance to the player from
** farthest to closest
*/

void				sort_sprites(t_cub3d *cub)
{
	int			i;

	if (cub->map.count_sprites == 0)
		return ;
	i = 0;
	calc_distance(cub, i);
	i = 0;
	bubble_sort(cub, i);
}
