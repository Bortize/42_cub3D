/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:43:42 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/09 13:38:11 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

int		rgb_to_hex(int r, int g, int b)
{
	int hexade_colour;

	hexade_colour = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (hexade_colour);
}

int		convert_colour(t_cub3d *cub3d)
{
	int r;
	int g;
	int b;

	r = 0;
	g = 0;
	b = 0;

		rgb_to_hex(r, g, b);
	return ((int)rgb_to_hex);
}
