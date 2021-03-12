/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_identifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:02:55 by bortize           #+#    #+#             */
/*   Updated: 2021/03/12 17:08:10 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** It removes all spaces and tabs contained in the line it receives as a
** parameter to group the strings found in a vector to identify their values.
** It also checks if the map has equal identifiers to return an error if so.
*/

int	find_identifiers(char *str, t_cub3d *cub)
{
	if ((cub->map.tab = ft_split_plus(str, ' ', '\t')))
	{
		check_identifiers(cub);
		if (cub->map.tab[2] == NULL)
			assignment_identifiers_text_colour(cub);
		else if (cub->map.tab[3] == NULL)
			assignment_identifiers_resolution(cub);
		else if (cub->map.tab[4] == NULL)
			assignment_identifiers_text_colour(cub);
		else if (ft_strchr(cub->map.tab[0], '0') || ft_strchr(cub->map.tab[0], '1'))
			print_error("He plan must follow the identifiers");
		else
			print_error("There are too many values in the identifier");
	}
	if (cub->map.flag_widht > 1 || cub->map.flag_no > 1 ||
	cub->map.flag_so > 1 || cub->map.flag_ea > 1 ||
	cub->map.flag_we > 1 || cub->map.flag_s > 1 ||
	cub->map.flag_ceilling > 1 || cub->map.flag_floor > 1)
	{
		print_error("The map contains repeated identifiers");
	}
	if (cub->map.i > 8)
		print_error("There are too many Identifiers, check your map");
	return (0);
}
