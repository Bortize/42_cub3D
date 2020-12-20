/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validation_we.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:11:23 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/20 15:12:30 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

void	texture_validation_we(map_config *map)
{
	path_validation(map->tab[1]);
	if (map->flag_we == 0)
	{
		map->flag_we++;
		map->i++;
		map->we = map->tab[1];
	}
	else
	{
		print_error("El fichero '.cub' contiene identificadores "
			"duplicados.\n Por favor, introduzca un fichero válido");
	}	
}