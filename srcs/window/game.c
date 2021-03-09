/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:24:21 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/08 14:08:26 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game(t_cub3d *cub)
{
	if (moving(cub) || rotating(cub))
	{
		refresh_screen(cub);
		movement(cub);
		rotation(cub);
		raycast_init(cub);
	}
	sleep(0);
	return (0);
}
