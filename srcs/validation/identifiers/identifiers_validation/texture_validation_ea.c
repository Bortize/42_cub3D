/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validation_ea.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:08:26 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/16 16:13:59 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_validation_ea(t_cub3d *cub)
{
	path_validation(cub->map.tab[1]);
	if (cub->map.flag_ea == 0)
	{
		cub->map.flag_ea++;
		cub->map.i++;
		cub->map.ea = ft_strdup(cub->map.tab[1]);
	}
	else
	{
		print_error("The '.cub' file contains duplicate identifiers\n");
	}
}
