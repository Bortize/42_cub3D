/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_plane_values.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:45:19 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/09 23:49:54 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

/*
**  Reserves memory for an array that will hold all the lines read from the
**  blueprint. It assigns the strings of the blueprint to the array and checks by
**  the flooding method that the blueprint is valid.
*/
void	assigning_plane_values(t_cub3d *cub)
{
	cub->plan.plan = (char **)calloc(cub->plan.rows_size, sizeof(char *));
	cub->plan.values_ok = 1;
	cub->plan.plan = ft_split(cub->plan.one_line_plan, 'p');
	cub->plan.plan_tmp = ft_split(cub->plan.one_line_plan, 'p');
	boundary_fill(cub->plan.player_init_position_x,
	cub->plan.player_init_position_y, cub->plan.fill_value,
	cub->plan.boundary_value, cub);
	find_sprites(cub);
	free(cub->plan.one_line_plan);
	free(cub->plan.plan_tmp);
	cub->plan.one_line_plan = NULL;
}
