/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_plane_values.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:45:19 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/15 21:21:28 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**  Reserves memory for an array that will hold all the lines read from the
**  blueprint. It assigns the strings of the blueprint to the array and checks
** by the flooding method that the blueprint is valid.
*/

void	assigning_plane_values(t_cub3d *cub)
{
	cub->plan.values_ok = 1;
	cub->plan.plan = ft_split_map(cub->plan.one_line_plan, 'p',
		cub->plan.row_len);
	cub->plan.plan_tmp = ft_split_map(cub->plan.one_line_plan, 'p',
		cub->plan.row_len);
	boundary_fill(cub->plan.player_init_position_x,
	cub->plan.player_init_position_y, cub);
	find_sprites(cub);
	free(cub->plan.one_line_plan);
	cub->plan.one_line_plan = NULL;
	free_array(cub->plan.plan_tmp);
}
