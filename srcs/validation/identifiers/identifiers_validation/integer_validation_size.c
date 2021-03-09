/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_validation_size.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 09:04:22 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/09 23:43:57 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Controla el error si le pasan un rango de color superior a '255' a cada
**	parametro del cielo y el suelo
*/
int	integer_validation_size(t_cub3d *cub)
{
	if ((ft_atoi(cub->map.tabcf[0]) > 255) ||
		(ft_atoi(cub->map.tabcf[1]) > 255) ||
		(ft_atoi(cub->map.tabcf[2]) > 255))
			print_error("The color range exceeds the allowed range. Fix it");
	return (0);
}
