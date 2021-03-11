/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_calculations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 01:45:10 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/11 02:11:32 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** texturing calculations
*/

void	texture_calculations(t_raycast *rcast, t_player *p)
{
	if (rcast->side <= 1)
		rcast->wallx = p->posy + rcast->perpwalldist * rcast->raydiry;
	else
		rcast->wallx = p->posx + rcast->perpwalldist * rcast->raydirx;
			rcast->wallx -= (floor)(rcast->wallx);
}
