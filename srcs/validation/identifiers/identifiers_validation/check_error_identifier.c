/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_identifier.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 01:05:20 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/15 01:16:46 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_error_identifier(t_cub3d *cub)
{
	if (cub->map.flag_widht > 1 || cub->map.flag_no > 1 ||
	cub->map.flag_so > 1 || cub->map.flag_ea > 1 ||
	cub->map.flag_we > 1 || cub->map.flag_s > 1 ||
	cub->map.flag_ceilling > 1 || cub->map.flag_floor > 1)
	{
		print_error("The map contains repeated identifiers");
	}
	if (cub->map.i > 8)
		print_error("There are too many Identifiers, check your map");
}
