/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_identifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:52:36 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/23 16:30:42 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

/*	Call-Function -->
**	Inicializa todas las variables de la estructura para permitirnos poder
**	empezar a trabajar con ellas. Ademas elimina el valor basuara que pudieran
**	contener a la hora de su declaración
*/
void	init_identifiers(map_config *map)
{
	map->i = 0;
	map->width = 0;
	map->flag_widht = 0;
	map->height = 0;
	map->flag_height = 0;
	map->no = 0;
	map->flag_no = 0;
	map->so = 0;
	map->flag_so = 0;
	map->ea = 0;
	map->flag_ea = 0;
	map->we = 0;
	map->flag_we = 0;
	map->s = 0;
	map->flag_s = 0;
	map->flag_floor = 0;
	map->flag_ceilling = 0;
	map->flag_map_ready = 0;
}

void	init_plan_values(map_plan *plan)
{
	plan->i = 0;
	plan->plan_row_size = 0;
	plan->row_len = 0;
}
