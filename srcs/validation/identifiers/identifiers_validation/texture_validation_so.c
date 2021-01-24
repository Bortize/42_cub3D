/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validation_so.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:04:24 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/24 17:24:33 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../headers/cub3d.h"

void	texture_validation_so(t_cub3d *cub)
{
	path_validation(cub->map.tab[1]);
	if (cub->map.flag_so == 0)
	{
		cub->map.flag_so++;
		cub->map.i++;
		cub->map.so = cub->map.tab[1];
	}
	else
	{
		print_error("El fichero '.cub' contiene identificadores "
			"duplicados. \nPor favor, introduzca un fichero válido");
	}
}
