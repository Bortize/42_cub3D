/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_identifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:02:55 by bortize           #+#    #+#             */
/*   Updated: 2020/12/13 23:16:21 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int find_identifier(char *str, map_config *map)
{
	if ((map->tab = ft_split_plus(str, ' ', '\t')))
	{
		if (map->tab[2] == NULL)
		{
			assignment_identifiers(map);
		}
		else if (map->tab[3] == NULL)
		{
			assignment_identifiers_resolution(map);
		}
		else
			ft_printf("HAY DEMASIDADOS VALORES EN LA MISMA LINEA \n");
	}
	return (0);
}