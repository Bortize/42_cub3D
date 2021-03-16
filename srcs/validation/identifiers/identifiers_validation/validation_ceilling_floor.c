/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_ceilling_floor.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:00:34 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/16 16:04:12 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Validates if the values received in C and F are in the range 255
** and if so transforms the type to integer. To do this, you must
** cast the integers to (char *)
*/

void	validation_identifiers_ceilling(t_cub3d *cub)
{
	integer_validation_size(cub);
	if (cub->map.tabcf[3] == NULL)
	{
		integer_validation(cub);
		cub->map.ceilling[0] = ft_atoi(cub->map.tabcf[0]);
		cub->map.ceilling[1] = ft_atoi(cub->map.tabcf[1]);
		cub->map.ceilling[2] = ft_atoi(cub->map.tabcf[2]);
	}
	else
	{
		print_error("There are too many values in the identifier\n");
	}
	cub->map.ceilling_conv = ((256 * 256) * cub->map.ceilling[0] +
	256 * cub->map.ceilling[1] + cub->map.ceilling[2]);
}

void	validation_identifiers_floor(t_cub3d *cub)
{
	integer_validation_size(cub);
	if (cub->map.tabcf[3] == NULL)
	{
		integer_validation(cub);
		cub->map.floor[0] = ft_atoi(cub->map.tabcf[0]);
		cub->map.floor[1] = ft_atoi(cub->map.tabcf[1]);
		cub->map.floor[2] = ft_atoi(cub->map.tabcf[2]);
	}
	else
	{
		print_error("There are too many values in the identifier\n");
	}
	cub->map.floor_conv = ((256 * 256) * cub->map.floor[0] +
	256 * cub->map.floor[1] + cub->map.floor[2]);
}
