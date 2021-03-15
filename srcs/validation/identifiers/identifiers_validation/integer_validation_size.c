/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_validation_size.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 09:04:22 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/15 12:20:10 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Controla el error si le pasan un rango de color superior a '255' a cada
**	parametro del cielo y el suelo
*/

int	integer_validation_size(t_cub3d *cub)
{
	size_t num;

	num = 0;
	while (num < 3)
	{
		if ((cub->map.tabcf[num] == NULL)
			|| (cub->map.tabcf[num][0] == '-')
			|| (!(ft_strevery(cub->map.tabcf[num], ft_isdigit)))
			|| (ft_atoi(cub->map.tabcf[num]) > 255))
			print_error("The color range exceeds the allowed range. Fix it \n");
		num++;
	}
	return (0);
}
