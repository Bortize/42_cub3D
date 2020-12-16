/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_identifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:02:55 by bortize           #+#    #+#             */
/*   Updated: 2020/12/16 12:17:15 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int find_identifier(char *str, map_config *map)
{
	if ((map->tab = ft_split_plus(str, ' ', '\t')))
	{
		if (map->tab[2] == NULL)
			assignment_identifiers(map);
		else if (map->tab[3] == NULL)
			assignment_identifiers_resolution(map);
		else
			ft_printf("HAY DEMASIDADOS VALORES EN LA MISMA LINEA \n");
	}
	if (map->flag_no > 1 || map->flag_so > 1 || map->flag_ea > 1 ||
		map->flag_we > 1 || map->flag_s > 1)
	{
		print_error("El mapa contiene identificadores repetidos. \
			Introduzca una mapa válido /n");
	}
	return (0);
}
