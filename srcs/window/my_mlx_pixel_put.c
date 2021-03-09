/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:25:06 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/10 00:49:13 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"
/*
** Draw all the pixels in the buffer so that you have your frame ready
** to be sent to the window
*/
inline void	my_mlx_pixel_put(t_cub3d *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->mlx.addr + (y * cub->mlx.line_len + x * (cub->mlx.bpp / 8));
	*(unsigned int*)dst = color;
}
