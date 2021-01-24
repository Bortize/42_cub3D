/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:04:22 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/24 17:24:33 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../headers/cub3d.h"

int	check_identifiers(t_cub3d *cub)
{
	if ((ft_strcmp("R", cub->map.tab[0]) == 0) ||
		(ft_strcmp("NO", cub->map.tab[0]) == 0) ||
		(ft_strcmp("SO", cub->map.tab[0]) == 0) ||
		(ft_strcmp("EA", cub->map.tab[0]) == 0) ||
		(ft_strcmp("WE", cub->map.tab[0]) == 0) ||
		(ft_strcmp("S", cub->map.tab[0]) == 0) ||
		(ft_strcmp("C", cub->map.tab[0]) == 0) ||
		(ft_strcmp("F", cub->map.tab[0]) == 0))
	{
		return (0);
	}
	else
	{
		print_error("Uno de los identificadores introducdios NO ES VALIDO.");
	}
	return (0);
}
