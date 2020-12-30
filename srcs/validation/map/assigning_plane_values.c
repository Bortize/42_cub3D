/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning_plane_values.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:45:19 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/30 14:12:53 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

/*
** Rerserva memoria para una matriz que alojara todas las lineas leidas en el
** plano
*/
void	assigning_plane_values(map_plan *plan)
{
	int i;

	plan->plan = (char **)calloc(plan->rows_size, sizeof(char *));
	plan->values_ok = 1;// flag para entrar en esta funcion
	plan->plan = ft_split(plan->one_line_plan, 'p');
	i = 0;
	while (plan->plan[i] != '\0')
	{
		ft_printf("Assigned to the structure 🧤 %s \n", plan->plan[i]);
		i++;
	}
	check_line_by_line(plan);
	//free(plan->one_line_plan);
	//plan->one_line_plan = NULL;
}

void	check_line_by_line(map_plan *plan)
{
	map_plane_walls(plan);
}
