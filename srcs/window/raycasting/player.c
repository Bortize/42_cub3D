/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 09:16:03 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/19 11:16:21 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"
/*
** Devuelve el valor del movimiento frotnal o trasero si ha cambiado respecto
** al estado anteriror.
*/
int		if_moving(t_cub3d *cub)
{
	return (cub->move.frontal || cub->move.lateral);
}
/*
** Devuelve el valor de la rotación si ha cambiado respecto
** al estado anteriror.
*/
int		if_rotating(t_cub3d *cub)
{
	return (cub->move.rotating);
}
