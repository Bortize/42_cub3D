/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:40:03 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/19 13:41:21 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	my_mlx_pixel_put(t_window *graphic, int x, int y, int color)
{
	char	*dst;

	dst = graphic->addr + (y * graphic->line_length + x * (graphic->bpp / 8));
	*(unsigned int*)dst = color;
}
