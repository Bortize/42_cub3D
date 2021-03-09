/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_player_look.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:26:20 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/10 00:26:36 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
** Adjusts the values of the direction in which the player is facing at the
** moment of starting the game according to the cardinal axis where the player
** was found.
*/
void	where_player_look(t_cub3d *cub, char c)
{
	cub->p.dirx = 0;
	cub->p.diry = 0;
	if (c == 'N')
		cub->p.diry = -1;
	if (c == 'S')
		cub->p.diry = 1;
	if (c == 'E')
		cub->p.dirx = 1;
	if (c == 'W')
		cub->p.dirx = -1;
	cub->p.planex = cub->p.diry * -0.66;
	cub->p.planey = cub->p.dirx * 0.66;
}

