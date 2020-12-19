/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_identifiers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:00:34 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/19 11:48:53 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/*
** Validates if the values received in C and F are in the range 255
** and if so transforms the type to integer. To do this, you must
** cast the integers to (char *)
*/
void	validation_identifiers_ceilling(map_config *map)
{
	integer_validation_size(map);
	if (map->tabcf[3] == NULL)
	{
		integer_validation(map);
		map->ceilling[0] = ft_atoi(map->tabcf[0]);
		map->ceilling[1] = ft_atoi(map->tabcf[1]);
		map->ceilling[2] = ft_atoi(map->tabcf[2]);
	}
	else
	{
		print_error("Hay demasiados valores en el identificador");
	}
}

void	validation_identifiers_floor(map_config *map)
{
	integer_validation_size(map);
	if (map->tabcf[3] == NULL)
	{
		integer_validation(map);
		map->floor[0] = ft_atoi(map->tabcf[0]);
		map->floor[1] = ft_atoi(map->tabcf[1]);
		map->floor[2] = ft_atoi(map->tabcf[2]);
	}
	else
	{
		print_error("Hay demasiados valores en el identificador");
	}
}
