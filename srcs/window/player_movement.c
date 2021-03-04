/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 00:00:29 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/05 00:04:27 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d"
/*
** Devuelve el valor del movimiento frotnal o trasero si ha cambiado respecto
** al estado anteriror.
*/
int		moving(t_cub3d *cub)
{
	return (cub->move.frontal || cub->move.lateral);
}
/*
** Devuelve el valor de la rotación si ha cambiado respecto
** al estado anteriror.
*/
int		rotating(t_cub3d *cub)
{
	return (cub->move.rotating);
}

