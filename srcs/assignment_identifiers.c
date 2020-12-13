/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment_identifiers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:57:35 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/13 19:12:42 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	assignment_identifiers(map_config *map)
{
	int difference;

	difference = 0;
	ft_printf("Identifier found ℹ️  -->  %s \n", map->tab[0]);
	ft_printf("Value found 🔎 -->  %s \n", map->tab[1]);
	ft_printf("Value assigned 🧪 -->  %s \n\n", map->tab[1]);
	if (ft_strcmp("NO", map->tab[0]) == 0)
		map->no = map->tab[1];
	if (ft_strcmp("SO", map->tab[0]) == 0)
		map->so = map->tab[1];
	if (ft_strcmp("EA", map->tab[0]) == 0)
		map->ea = map->tab[1];
	if (ft_strcmp("WE", map->tab[0]) == 0)
		map->we = map->tab[1];
	if (ft_strcmp("S", map->tab[0]) == 0)
		map->s = map->tab[1];
	return (0);
}
