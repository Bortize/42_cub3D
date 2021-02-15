/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 09:16:03 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/15 14:20:07 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"
/*
** Comprueba si algun flag de movimiento (forwad, backward, right, left) esta
** activado para ejecutar la correspondiente funcion en "movement" que hace
** que se produzca ese movimiento.
*/
int		if_moving(t_cub3d *cub)
{
	if (cub->move.forward || cub->move.backward ||
	cub->move.right || cub->move.left)
		return (1);
	return (0);
}
/*
** Comprueba si algun flag de rotacion (left, right) esta activado para
** ejecutar la correspondiente funcion en "rotation" que hace que se produzca
** ese movimiento.
*/
int		if_rotating(t_cub3d *cub)
{
	if (cub->move.rotating_left || cub->move.rotating_right)
		return (1);
	return (0);
}
