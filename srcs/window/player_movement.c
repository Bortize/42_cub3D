/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 00:00:29 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/10 19:11:33 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Returns the value of the front or rear movement if it has changed with
** respect to the previous state
*/

int	moving(t_cub3d *cub)
{
	return (cub->ctrl.forward || cub->ctrl.sideways);
}

/*
** Returns the rotation value if it has changed from the previous state
*/

int	rotating(t_cub3d *cub)
{
	return (cub->ctrl.rotate);
}
