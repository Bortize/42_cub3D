/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_start_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:15:50 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/01 13:02:13 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"
/*
** Guarda la posicion del jugador cuando la encuentra. La guarda en 2 coordenadas
** dónde 'x' corresponde al índe del número de vector donde se encontro e 'y' al
** índice del string donde se encontró
*/
int	player_start_position(char *str, t_cub3d *cub)
{
	if ((str[cub->plan.i] == 'N') || (str[cub->plan.i] == 'S') || (str[cub->plan.i] == 'E')
		|| (str[cub->plan.i] == 'W'))
	{
		cub->plan.player_init_position_x = cub->plan.rows_size;
		cub->plan.player_init_position_y = cub->plan.i;
		ft_printf("se encontro al jugador en la posición %d %d \n", cub->plan.player_init_position_x, cub->plan.player_init_position_y);
	}
	return (0);
}
