/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_plane_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 13:34:46 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/30 22:55:56 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

void	map_plane_wall_left_right(map_plan *plan)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < (plan->rows_size - 1))
	{
		if (plan->plan[i][j] == '1')
		{
			ft_printf("El muro %c es OK \n", plan->plan[plan->rows_size - 1][j]);
		}
		else
		{
			print_error("Los muros del plano contienen valores no válidos");
		}
		i++;
	}
}

void	map_plane_wall_down(map_plan *plan)
{
	int j;

	j = 0;
	while (plan->plan[plan->rows_size - 1][j] != '1')
	{
		if (plan->plan[plan->rows_size - 1][j] == '1')
		{
			ft_printf("El muro %c es OK \n", plan->plan[plan->rows_size - 1][j]);
		}
		else
		{
			print_error("Los muros del plano contienen valores no válidos");
		}
		j++;
	}
}

void	map_plane_wall_up(map_plan *plan)
{
	int j;

	j = 0;
	while (plan->plan[0][j] != '1')
	{
		if (plan->plan[0][j] == '1')
		{
			ft_printf("The UP walll is OK");
		}
		else
		{
			print_error("Los muros del plano contienen valores no válidos");
		}
		j++;
	}
}

void	map_plane_walls(map_plan *plan)
{
	map_plane_wall_up(plan);
	map_plane_wall_down(plan);
	map_plane_wall_left_right(plan);
}
