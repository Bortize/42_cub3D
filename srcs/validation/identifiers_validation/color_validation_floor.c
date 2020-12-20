/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validation_floor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:45:54 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/20 15:46:36 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

void	color_validation_floor(map_config *map)
{
	if (ft_strcmp("F", map->tab[0]) == 0)
	{
		map->flag_floor++;
		map->i++;
		map->tabcf = ft_split(map->tab[1], ',');
		validation_identifiers_floor(map);
		ft_printf(" 🧪 -->  %i \n", map->floor[0]);
		ft_printf(" 🧪 -->  %i \n", map->floor[1]);
		ft_printf(" 🧪 -->  %i \n\n", map->floor[2]);
	}
}