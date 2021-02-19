/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:24:21 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/19 20:36:54 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"
/*
** Gestiona toda la parte del movimiento del jugador y el lanzamiento de rayos
*/
int		game(t_cub3d *cub)
{
	if (if_moving(cub) || if_rotating(cub))
	{
		rotation(cub);
		movement(cub);
		raycasting(cub);
	}
	sleep(0);
	return (0);
}
