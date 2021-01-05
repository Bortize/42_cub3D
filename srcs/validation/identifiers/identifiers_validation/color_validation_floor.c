/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validation_floor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:45:54 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/04 19:17:32 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../headers/cub3d.h"

int	color_validation_floor(map_config *map)
{
	const char *new;
	const char *new2;

	if (ft_strcmp("F", map->tab[0]) == 0)
	{
		if (map->tab[2] == NULL)
		{
			map->flag_floor++;
			map->i++;
			map->tabcf = ft_split(map->tab[1], ',');
			validation_identifiers_floor(map);
			ft_printf(" 🧪 -->  %i \n", map->floor[0]);
			ft_printf(" 🧪 -->  %i \n", map->floor[1]);
			ft_printf(" 🧪 -->  %i \n\n", map->floor[2]);
			return (0);
		}
		if (map->tab[3] == NULL)
		{
			map->flag_floor++;
			map->i++;
			new = ft_strjoin(map->tab[0], map->tab[1]);
			map->tabcf = ft_split(new, ',');
			validation_identifiers_floor(map);
			ft_printf(" 🧪 -->  %i \n", map->floor[0]);
			ft_printf(" 🧪 -->  %i \n", map->floor[1]);
			ft_printf(" 🧪 -->  %i \n\n", map->floor[2]);
			return (0);
		}
		if (map->tab[4] == NULL)
		{
			map->flag_ceilling++;
			map->i++;
			new = ft_strjoin(map->tab[1], map->tab[2]);
			new2 = ft_strjoin(new, map->tab[3]);
			map->tabcf = ft_split(new2, ',');
			validation_identifiers_floor(map);
			ft_printf(" 🧪 -->  %i \n", map->floor[0]);
			ft_printf(" 🧪 -->  %i \n", map->floor[1]);
			ft_printf(" 🧪 -->  %i \n\n", map->floor[2]);
			return (0);
		}
	}
	return (0);
}
