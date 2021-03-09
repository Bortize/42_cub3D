/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_start_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 23:15:50 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/10 00:24:09 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
** Saves the position of the player when found. It saves it in 2 coordinates where
** 'x' corresponds to the index of the vector number where it was found and 'y'
** to the index of the string where it was found.
*/
int	player_start_position(char *str, t_cub3d *cub)
{
	if ((str[cub->plan.i] == 'N') || (str[cub->plan.i] == 'S') ||
	(str[cub->plan.i] == 'E') || (str[cub->plan.i] == 'W'))
	{
		where_player_look(cub, str[cub->plan.i]);
		cub->plan.player_init_position_x = (double)cub->plan.i + 0.5;
		cub->plan.player_init_position_y = (double)cub->plan.rows_size + 0.5;
		str[cub->plan.i] = '0';
	}
	return (0);
}
