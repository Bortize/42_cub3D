#include "cub3d.h"

/*
** Sort the sprites according to the distance to the player from
** farthest to closest
*/

void			sort_sprites(t_cub3d *cub)
{
	int			i;
	int			j;
	t_sprite	tmp;
	int			sorted;

	if (cub->map.count_sprites == 0)
		return ;
	i = 0;
	while (i < cub->map.count_sprites)
	{
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
