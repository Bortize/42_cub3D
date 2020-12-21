/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validation_ceilling.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:42:41 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/21 12:43:32 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

void	color_validation_ceilling(map_config *map)
{
	if (ft_strcmp("C", map->tab[0]) == 0)
	{
		map->flag_ceilling++;
		map->i++;
		map->tabcf = ft_split(map->tab[1], ',');
		validation_identifiers_ceilling(map);
		ft_printf(" 🧪 -->  %i \n", map->ceilling[0]);
		ft_printf(" 🧪 -->  %i \n", map->ceilling[1]);
		ft_printf(" 🧪 -->  %i \n\n", map->ceilling[2]);
	}
}