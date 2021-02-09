/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 09:16:03 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/09 09:35:30 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

int		if_moving(t_cub3d *cub)
{
	if (cub->move.forward ||
	cub->move.backward ||
	cub->move.right ||
	cub->move.left)
		return (1);
	return (0);
}

int		if_rotating(t_cub3d *cub)
{
	if (cub->move.rotating_left ||
	cub->move.rotating_right)
		return (1);
	return (0);
}
