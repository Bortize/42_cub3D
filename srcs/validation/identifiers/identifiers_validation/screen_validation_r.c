/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_validation_r.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:54:56 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/15 12:30:04 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	screen_validation_r(t_cub3d *cub)
{
	if (ft_strcmp("R", cub->map.tab[0]) == 0)
	{
		cub->map.flag_widht++;
		cub->map.i++;
		integer_validation_resolution(cub);
		cub->map.width = ft_atoi(cub->map.tab[1]);
		cub->map.height = ft_atoi(cub->map.tab[2]);
		if (cub->map.width <= 0 || cub->map.height <= 0)
			print_error("Resolution is not playable \n");
	}
}
