/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validation_no.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 14:59:18 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/24 17:24:33 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../headers/cub3d.h"

void	texture_validation_no(t_cub3d *cub)
{
	if (cub->map.flag_no == 0)
	{
		path_validation(cub->map.tab[1]);
		cub->map.flag_no++;
		cub->map.i++;
		cub->map.no = cub->map.tab[1];
	}
	else
	{
		print_error("El fichero '.cub' contiene identificadores "
			"duplicados. \nPor favor, introduzca un fichero válido");
	}
}
