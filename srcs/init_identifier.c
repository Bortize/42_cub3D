/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_identifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortize <bortize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:52:36 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/09 22:18:26 by bortize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	init_identifier(map_config *map)
{
	map->i = 0;
	map->width = 0;
	map->height = 0;
	map->no = 0;
	map->so = 0;
	map->ea = 0;
	map->we = 0;
	map->s = 0;
	map->f = 0;
	map->c = 0;
}
