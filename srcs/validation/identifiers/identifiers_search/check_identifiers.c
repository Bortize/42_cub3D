/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:04:22 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/04 19:17:04 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../headers/cub3d.h"

int	check_identifiers(map_config *map)
{
	if ((ft_strcmp("R", map->tab[0]) == 0) ||
		(ft_strcmp("NO", map->tab[0]) == 0) ||
		(ft_strcmp("SO", map->tab[0]) == 0) ||
		(ft_strcmp("EA", map->tab[0]) == 0) ||
		(ft_strcmp("WE", map->tab[0]) == 0) ||
		(ft_strcmp("S", map->tab[0]) == 0) ||
		(ft_strcmp("C", map->tab[0]) == 0) ||
		(ft_strcmp("F", map->tab[0]) == 0))
	{
		return (0);
	}
	else
	{
		print_error("Uno de los identificadores introducdios NO ES VALIDO.");
	}
	return (0);
}
