/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validation_s.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:13:30 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/14 03:29:56 by rnavarre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_validation_s(t_cub3d *cub)
{
	path_validation(cub->map.tab[1]);
	if (cub->map.flag_s == 0)
	{
		cub->map.flag_s++;
		cub->map.i++;
		cub->map.s = ft_strdup(cub->map.tab[1]);
	}
	else
	{
		print_error("El fichero '.cub' contiene identificadores "
			"duplicados. \nPor favor, introduzca un fichero válido");
	}
}
