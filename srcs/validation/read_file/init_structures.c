/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:52:36 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/15 00:49:10 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** It initializes all the variables of the structure to allow us to start
** working with them. It also eliminates the basuara value that they could
** contain at the time of their declaration.
*/

void	init_structures(t_cub3d *cub)
{
	ft_bzero(cub, sizeof(t_cub3d));
	cub->plan.one_line_plan = ft_strdup("");
	cub->plan.boundary_value = '1';
	cub->plan.fill_value = 'f';
	cub->plan.sprite_value = '2';
}
