/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_plane_values.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:45:19 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/03 12:18:11 by bgomez-r         ###   ########.fr       */
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
	i = -1;
	while (cub->plan.plan[++i] != NULL)
		ft_printf("Assigned to the structure 🧤 %s \n", cub->plan.plan[i]);
	i = -1;
	if (boundary_fill(cub->plan.player_init_position_x, cub->plan.player_init_position_y,
		cub->plan.fill_value, cub->plan.boundary_value, cub))
	{
		while (cub->plan.plan_tmp[++i] != NULL)
			ft_printf("Assigned to the structure 🧤 %s \n", cub->plan.plan_tmp[i]);
	}
	find_sprites(cub);// localiza la posicion de los sprites antes de que sea elimianda
	free(cub->plan.one_line_plan);
	free(cub->plan.plan_tmp);
	cub->plan.one_line_plan = NULL;
}
