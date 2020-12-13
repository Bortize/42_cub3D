/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_identifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:02:55 by bortize           #+#    #+#             */
/*   Updated: 2020/12/13 14:36:39 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int find_identifier(char *str, map_config *map)
{
	if ((map->tab = ft_split_plus(str, ' ', '\t')))
	{
		if (map->tab[2] == NULL)
		{
			if (ft_strcmp("NO", map->tab[0]) == 0)
				ft_printf("vamos \n");
			if (ft_strcmp("SO", map->tab[0]) == 0)
				ft_printf("vamos \n");
			if (ft_strcmp("EA", map->tab[0]) == 0)
				ft_printf("vamos \n");
			if (ft_strcmp("WE", map->tab[0]) == 0)
				ft_printf("vamos \n");
			if (ft_strcmp("S", map->tab[0]) == 0)
				ft_printf("vamos \n");
			if (ft_strcmp("C", map->tab[0]) == 0)
				ft_printf("vamos \n");
			if (ft_strcmp("F", map->tab[0]) == 0)
				ft_printf("vamos \n");
			ft_printf("Identifier found -->  %s \n", map->tab[0]);
			ft_printf("Value found -->  %s \n\n", map->tab[1]);
		}
		else if (map->tab[3] == NULL)
		{
			ft_printf("Identifier found -->  %s \n", map->tab[0]);
			ft_printf("Value found -->  %s \n", map->tab[1]);
			ft_printf("Value found -->  %s \n\n", map->tab[2]);
		}
		else
			ft_printf("HAY DEMASIDADOS VALORES EN LA MISMA LINEA \n");
	}
	return (0);
}
