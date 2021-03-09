/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_plane_values.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:45:19 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/09 01:42:07 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

/*
** Reserva memoria para una matriz que alojara todas las lineas leidas en el
** plano. Asigna los strings del plano a la matriz y comprueba mediante el
** método de inundación que el plano sea válido
*/
void	assigning_plane_values(t_cub3d *cub)
{
	cub->plan.plan = (char **)calloc(cub->plan.rows_size, sizeof(char *));
	cub->plan.values_ok = 1;
	cub->plan.plan = ft_split(cub->plan.one_line_plan, 'p');
	cub->plan.plan_tmp = ft_split(cub->plan.one_line_plan, 'p');
	if (boundary_fill(cub->plan.player_init_position_x, cub->plan.player_init_position_y,
		cub->plan.fill_value, cub->plan.boundary_value, cub))
	find_sprites(cub);
	free(cub->plan.one_line_plan);
	free(cub->plan.plan_tmp);
	cub->plan.one_line_plan = NULL;
}
