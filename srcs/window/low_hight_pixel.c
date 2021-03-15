/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_hight_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:00:56 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/10 21:05:39 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** calculate lowest and highest pixel to fill in current stripe
*/

void	low_hight_pixel(t_window *win, t_parse *map)
{
	win->drawstart = -win->lineheight / 2 + map->height / 2;
	if (win->drawstart < 0)
		win->drawstart = 0;
	win->drawend = win->lineheight / 2 + map->height / 2;
	if (win->drawend >= map->height)
		win->drawend = map->height - 1;
	if (win->drawend < 0)
		win->drawend = 0;
}
