/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_validation_r.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:54:56 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/20 15:57:10 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

void	screen_validation_r(map_config *map)
{
	if (ft_strcmp("R", map->tab[0]) == 0)
	{
		map->flag_widht++;
		map->i++;
		integer_validation_resolution(map);
		map->width = ft_atoi(map->tab[1]);
		map->height = ft_atoi(map->tab[2]);
		ft_printf("🧪w --> %i \n", map->width);
		ft_printf("🧪h --> %i \n\n\n", map->height);
	}
}