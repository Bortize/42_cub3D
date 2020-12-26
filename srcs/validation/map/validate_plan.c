/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_plan.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 20:52:45 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/24 20:00:10 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

int		validate_plan(char *str, map_config *map, map_plan *plan)
{
	map->flag_map_ready = 1;//provisional, porque necesita usarse algo de la estructura plan

	check_characters(str, map, plan);
	if (plan->row_len < ft_strlen(str))
		plan->row_len = ft_strlen(str);
	return (0);
}
