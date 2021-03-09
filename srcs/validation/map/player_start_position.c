/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_start_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:15:50 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/09 01:45:04 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
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
		where_player_look(cub, str[cub->plan.i]);
		cub->plan.player_init_position_x = (double)cub->plan.i + 0.5;
		cub->plan.player_init_position_y = (double)cub->plan.rows_size + 0.5;
		str[cub->plan.i] = '0';
	}
	return (0);
}
