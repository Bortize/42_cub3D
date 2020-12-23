/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validation_s.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:13:30 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/23 18:08:36 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

void	texture_validation_s(map_config *map)
{
	path_validation(map->tab[1]);
	if (map->flag_s == 0)
	{
		map->flag_s++;
		map->i++;
		map->s = map->tab[1];
	}
	else
	{
		print_error("El fichero '.cub' contiene identificadores "
			"duplicados. \nPor favor, introduzca un fichero válido");
	}
}
