/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_plan.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 20:52:45 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/23 14:04:42 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

int		validate_plan(char *str, map_config *map, map_plan *plan)
{
	map->flag_map_ready = 1;

	ft_printf("congrats, estas leyendo el plano \n");
	ft_printf("Linea leía 🗺️ %s \n", str);
	if (ft_strchr(str, '0') || ft_strchr(str, '1') || ft_strchr(str, '2') ||
		ft_strchr(str, 'N') || ft_strchr(str, 'S') || ft_strchr(str, 'E') ||
		ft_strchr(str, 'W') || ft_strchr(str, ' ') || ft_strchr(str, '\t'))
	{
		ft_printf(" Ha leido la linea del mapa \n");
		plan->plan_row_size++;
	}
	else
	{
		print_error("El plano contiene valores no validos ");
	}
	if (plan->row_len < ft_strlen(str))
		plan->row_len = ft_strlen(str);
	return (0);
}
