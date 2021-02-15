/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:24:21 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/15 14:10:48 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"
/*
** Gestiona toda la parte del movimiento del jugador y el lanzamiento de rayos
*/
int		game(t_cub3d *cub)
{
	raycasting(cub);

	if (if_moving(cub))
		movement(cub);
	if (if_rotating(cub))
		rotation(cub);
	return (0);
}
