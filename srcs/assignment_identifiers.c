/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment_identifiers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:57:35 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/16 12:17:57 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"


void	assignment_identifiers_resolution(map_config *map)
{
	if (ft_strcmp("R", map->tab[0]) == 0)
		map->width = ft_atoi(map->tab[1]);
		map->height = ft_atoi(map->tab[2]);
		ft_printf("🧪w --> %i \n", map->width);
		ft_printf("🧪h --> %i \n\n\n", map->height);
}

void	assignment_identifiers_colours(map_config *map)
{
	if (ft_strcmp("C", map->tab[0]) == 0)
	{
		map->tabcf = ft_split(map->tab[1], ',');
		validation_identifiers_ceilling(map);
		ft_printf(" 🧪 -->  %i \n", map->ceilling[0]);
		ft_printf(" 🧪 -->  %i \n", map->ceilling[1]);
		ft_printf(" 🧪 -->  %i \n\n", map->ceilling[2]);
	}
	if (ft_strcmp("F", map->tab[0]) == 0)
	{
		map->tabcf = ft_split(map->tab[1], ',');
		validation_identifiers_floor(map);
		ft_printf(" 🧪 -->  %i \n", map->floor[0]);
		ft_printf(" 🧪 -->  %i \n", map->floor[1]);
		ft_printf(" 🧪 -->  %i \n\n", map->floor[2]);
	}
}

void	assignment_identifiers(map_config *map)
{
	ft_printf("🧪 --> %s \n", map->tab[0]);
	ft_printf("🧪 --> %s \n\n\n\n", map->tab[1]);
	if (ft_strcmp("NO", map->tab[0]) == 0)
		map->flag_no++;
		map->no = map->tab[1];
	if (ft_strcmp("SO", map->tab[0]) == 0)
		map->flag_so++;
		map->so = map->tab[1];
	if (ft_strcmp("EA", map->tab[0]) == 0)
		map->flag_ea++;
		map->ea = map->tab[1];
	if (ft_strcmp("WE", map->tab[0]) == 0)
		map->flag_we++;
		map->we = map->tab[1];
	if (ft_strcmp("S", map->tab[0]) == 0)
		map->flag_s++;
		map->s = map->tab[1];
	assignment_identifiers_colours(map);
}
