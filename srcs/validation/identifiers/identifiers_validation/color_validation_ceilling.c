/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validation_ceilling.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:42:41 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/09 01:27:31 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_validation_ceilling(t_cub3d *cub)
{
	const char *new;
	const char *new2;

	if (ft_strcmp("C", cub->map.tab[0]) == 0)
	{
		if (cub->map.tab[2] == NULL)
		{
			cub->map.flag_ceilling++;
			cub->map.i++;
			cub->map.tabcf = ft_split(cub->map.tab[1], ',');
			validation_identifiers_ceilling(cub);
			return (0);
		}
		if (cub->map.tab[3] == NULL)
		{
			cub->map.flag_ceilling++;
			cub->map.i++;
			new = ft_strjoin(cub->map.tab[0], cub->map.tab[1]);
			cub->map.tabcf = ft_split(new, ',');
			validation_identifiers_ceilling(cub);
			return (0);
		}
		if (cub->map.tab[4] == NULL)
		{
			cub->map.flag_ceilling++;
			cub->map.i++;
			new = ft_strjoin(cub->map.tab[1], cub->map.tab[2]);
			new2 = ft_strjoin(new, cub->map.tab[3]);
			cub->map.tabcf = ft_split(new2, ',');
			validation_identifiers_ceilling(cub);
			return (0);
		}
	}
	return (0);
}
