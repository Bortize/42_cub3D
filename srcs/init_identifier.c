/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_identifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:52:36 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/14 14:30:44 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	init_identifier(map_config *map)
{
	map->i = 0;
	map->width = 0;
	map->height= 0;
	map->no = 0;
	map->so = 0;
	map->ea = 0;
	map->we = 0;
	map->s = 0;
//	map->floor[3]= (0, 0, 0);
//	map->ceilling[3] = (0, 0, 0);
	map->tab = 0;
	//map->R = 0;
}
