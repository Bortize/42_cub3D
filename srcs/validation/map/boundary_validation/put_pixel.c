/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:20:31 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/10 17:23:15 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Assigns the fill value to the position indicated in the plane.
*/

char	put_pixel(int x, int y, t_cub3d *cub)
{
	cub->plan.plan_tmp[y][x] = 'f';
	return (cub->plan.plan_tmp[y][x]);
}
