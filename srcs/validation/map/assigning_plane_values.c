/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_plane_values.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:45:19 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/07 15:18:17 by bgomez-r         ###   ########.fr       */
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
	int i;

	cub->plan.plan = (char **)calloc(cub->plan.rows_size, sizeof(char *));
	cub->plan.values_ok = 1;// flag para entrar en esta funcion
	cub->plan.plan = ft_split(cub->plan.one_line_plan, 'p');
	cub->plan.plan_tmp = ft_split(cub->plan.one_line_plan, 'p');
	i = 0;
	while (cub->plan.plan[i] != '\0')
	{
		ft_printf("Assigned to the structure 🧤 %s \n", cub->plan.plan[i]);
		ft_printf("Assigned to the structure 🧤 %s \n", cub->plan.plan_tmp[i]);
		i++;
	}
	if (boundary_fill(cub->plan.player_init_position_x, cub->plan.player_init_position_y,
		cub->plan.fill_value, cub->plan.boundary_value, cub))
	{

	};
	free(cub->plan.one_line_plan);
	free(cub->plan.plan_tmp);
	cub->plan.one_line_plan = NULL;
}
