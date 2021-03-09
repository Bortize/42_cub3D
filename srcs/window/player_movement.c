/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 00:00:29 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/05 14:54:46 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Devuelve el valor del movimiento frotnal o trasero si ha cambiado respecto
** al estado anteriror.
*/
int		moving(t_cub3d *cub)
{
	return (cub->ctrl.forward || cub->ctrl.sideways);
}
/*
** Devuelve el valor de la rotación si ha cambiado respecto
** al estado anteriror.
*/
int		rotating(t_cub3d *cub)
{
	return (cub->ctrl.rotate);
}

