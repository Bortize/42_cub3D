/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:24:21 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/09 15:52:13 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

int		game(t_cub3d *cub)
{
	raycasting(cub);

	if (if_moving(cub))
		movement(cub);
	if (if_rotating(cub))
		rotation(cub);
	return (0);
}
