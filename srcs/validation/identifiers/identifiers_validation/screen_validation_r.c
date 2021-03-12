/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_validation_r.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:54:56 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/12 13:24:02 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	screen_validation_r(t_cub3d *cub)
{
		int	max_widht;
		int max_height;

	if (ft_strcmp("R", cub->map.tab[0]) == 0)
	{
		cub->map.flag_widht++;
		cub->map.i++;
		integer_validation_resolution(cub);
		mlx_get_screen_size(cub->mlx.init, &max_widht, &max_height);
		cub->map.width = ft_atoi(cub->map.tab[1]);
		cub->map.height = ft_atoi(cub->map.tab[2]);
		if (cub->map.width > max_widht)
			cub->map.width = max_widht;
		if (cub->map.height > max_height)
			cub->map.height = max_height;
	}
}
