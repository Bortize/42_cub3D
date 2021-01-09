/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_plane_values.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:45:19 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/09 20:37:48 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

/*
** Reserva memoria para una matriz que alojara todas las lineas leidas en el
** plano. Asigna los strings del plano a la matriz y comprueba mediante el
** método de inundación que el plano sea válido
*/
void	assigning_plane_values(map_plan *plan)
{
	int i;

	plan->plan = (char **)calloc(plan->rows_size, sizeof(char *));
	plan->values_ok = 1;// flag para entrar en esta funcion
	plan->plan = ft_split(plan->one_line_plan, 'p');
	i = 0;
	while (plan->plan[i] != (void *)'\0')
	{
		ft_printf("Assigned to the structure 🧤 %s \n", plan->plan[i]);
		i++;
	}
	check_line_by_line(plan);
	free(plan->one_line_plan);
	plan->one_line_plan = NULL;
}
/*
** Comprueba mediante el método de inundación que el plano sea válido
*/
void	check_line_by_line(map_plan *plan)
{
	boundary_fill(plan->player_position_x, plan->player_position_y,
		plan->fill_value, plan->boundary_value, plan);
}
