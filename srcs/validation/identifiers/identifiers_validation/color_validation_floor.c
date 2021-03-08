/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validation_floor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:45:54 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/08 20:54:41 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_validation_floor(t_cub3d *cub)
{
	const char *new;
	const char *new2;

	if (ft_strcmp("F", cub->map.tab[0]) == 0)
	{
		if (cub->map.tab[2] == NULL)
		{
			cub->map.flag_floor++;
			cub->map.i++;
			cub->map.tabcf = ft_split(cub->map.tab[1], ',');
			validation_identifiers_floor(cub);
//			ft_printf(" 🧪 -->  %i \n", cub->map.floor[0]);
//			ft_printf(" 🧪 -->  %i \n", cub->map.floor[1]);
//			ft_printf(" 🧪 -->  %i \n\n", cub->map.floor[2]);
			return (0);
		}
		if (cub->map.tab[3] == NULL)
		{
			cub->map.flag_floor++;
			cub->map.i++;
			new = ft_strjoin(cub->map.tab[0], cub->map.tab[1]);
			cub->map.tabcf = ft_split(new, ',');
			validation_identifiers_floor(cub);
//			ft_printf(" 🧪 -->  %i \n", cub->map.floor[0]);
//			ft_printf(" 🧪 -->  %i \n", cub->map.floor[1]);
//			ft_printf(" 🧪 -->  %i \n\n", cub->map.floor[2]);
			return (0);
		}
		if (cub->map.tab[4] == NULL)
		{
			cub->map.flag_ceilling++;
			cub->map.i++;
			new = ft_strjoin(cub->map.tab[1], cub->map.tab[2]);
			new2 = ft_strjoin(new, cub->map.tab[3]);
			cub->map.tabcf = ft_split(new2, ',');
			validation_identifiers_floor(cub);
			ft_printf(" 🧪 -->  %i \n", cub->map.floor[0]);
			ft_printf(" 🧪 -->  %i \n", cub->map.floor[1]);
			ft_printf(" 🧪 -->  %i \n\n", cub->map.floor[2]);
			return (0);
		}
	}
	return (0);
}
