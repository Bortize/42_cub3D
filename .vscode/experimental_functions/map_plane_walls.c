/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_plane_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 13:34:46 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/24 17:31:31 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

void	map_plane_wall_left_right(t_cub3d *cub3d)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < (cub->plan.rows_size - 1))
	{
		if (cub->plan.plan[i][j] == '1')
		{
			ft_printf("El muro %c es OK \n", cub->plan.plan[cub->plan.rows_size - 1][j]);
		}
		else
		{
			print_error("Los muros del plano contienen valores no válidos 🧑‍🎤");
		}
		i++;
	}
}

void	map_plane_wall_down(t_cub3d *cub3d)
{
	int j;

	j = 0;
	while (cub->plan.plan[cub->plan.rows_size - 1][j] != '1')
	{
		if (cub->plan.plan[cub->plan.rows_size - 1][j] == '1')
		{
			ft_printf("El muro %c es OK \n", cub->plan.plan[cub->plan.rows_size - 1][j]);
		}
		else
		{
			print_error("Los muros del plano contienen valores no válidos 🧑‍🎤");
		}
		j++;
	}
}

void	map_plane_wall_up(t_cub3d *cub3d)
{
	int j;

	j = 0;
	while (cub->plan.plan[0][j] != '1')
	{
		if (cub->plan.plan[0][j] == '1')
		{
			ft_printf("The UP walll is OK");
		}
		else
		{
			print_error("Los muros del plano contienen valores no válidos 🧑‍🎤");
		}
		j++;
	}
}

void	map_plane_walls(t_cub3d *cub3d)
{
	map_plane_wall_up(cub);
	map_plane_wall_down(cub);
	map_plane_wall_left_right(cub);
}
