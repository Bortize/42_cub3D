/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_identifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:02:55 by bortize           #+#    #+#             */
/*   Updated: 2020/12/12 12:00:02 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int find_identifier(char *str, map_config *map)
{
	map->tab = 0;
	if ((map->tab = ft_split(str, ' ')))
	{
		if (map->tab[3] == NULL)
		{
			ft_printf("Identifier found -->  %s \n", map->tab[0]);
			ft_printf("Value found -->  %s \n", map->tab[1]);
			ft_printf("Value found -->  %s \n", map->tab[2]);
			ft_printf("Value found -->  %s \n\n", map->tab[3]);
		}
		else if (map->tab[2] == NULL)
		{
			ft_printf("Identifier found -->  %s \n", map->tab[0]);
			ft_printf("Value found -->  %s \n", map->tab[1]);
			ft_printf("Value found -->  %s \n\n", map->tab[2]);
		}
		else if (map->tab[2])
		{
			ft_printf("Identifier found -->  %s \n", map->tab[0]);
			ft_printf("Value found -->  %s \n\n", map->tab[1]);
		}
//		if (map->tab > 4 || map->tab < 2)
//			return (-1);
//		else
//		{
//			ft_printf("todo correcto \n");
//		}
	}
	return (0);
}
