/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundary_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:37:12 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/10 00:23:12 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
** Travels around the map starting from the player's position. Use the flooding
** method up to the limits of the wall. When it finds a valid ground value valid
** ground value, it fills it with 'f' and moves on.
*/
int	boundary_fill(int x, int y, int fill_value, int boundary_value, t_cub3d *cub)
{
	if ((y < 0 || y > cub->plan.rows_size) && (x < 0 ||
	x > (int)cub->plan.row_len))
		print_error("The plan contains a wall that is not closed");
	if ((cub->plan.plan_tmp[y][x] == 'f') ||
	(cub->plan.plan_tmp[y][x] == '1') ||
	(cub->plan.plan_tmp[y][x] == '2'))
	{
		ft_printf("🚫 The value cannot be changed \n");
	}
	else
	{
		put_pixel(x, y, cub);
		return 1;
		return (boundary_fill(x - 1, y, fill_value, boundary_value, cub) &&
		boundary_fill(x, y + 1, fill_value, boundary_value, cub) &&
		boundary_fill(x + 1, y, fill_value, boundary_value, cub) &&
		boundary_fill(x, y - 1, fill_value, boundary_value, cub));
	}
	return (1);
}
