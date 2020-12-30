/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_plane_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 13:34:46 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/30 14:49:59 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

void	map_plane_walls(map_plan *plan)
{
	int j;


	j = 0;
	while (plan->plan[0][j] != '\0')
	{
		if (plan->plan[0][j] == '1')
		{
			ft_printf("El valor %c del 1er muro es OK \n", plan->plan[0][j]);
		}
		else
		{
			print_error("Los muros del plano contienen valores no válidos");
		}
		j++;
	}
}
