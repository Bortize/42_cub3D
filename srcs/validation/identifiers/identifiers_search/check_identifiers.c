/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:04:22 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/15 12:16:10 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**  It checks position 0 against any of the allowed identifiers.
**  If none is found, it handles the error and stops
**  at this point in the program.
*/

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
		print_error("One of the identifiers introduced is not valid \n");
	}
	return (0);
}
