/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment_identifiers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:57:35 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/15 00:34:47 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Is called by --> find_identifier(char *str, t_cub3d *cub);
** Check the value of the indicice [0] after it has been departed by
** ft_split_plus to know which identifier it is and to be able to assign the
** value of [1] and [2] to the variable that is and [2] to the corresponding
** variable in the structure.
*/

void	assignment_identifiers_resolution(t_cub3d *cub)
{
	screen_validation_r(cub);
}

/*
** Is called by --> assignment_identifiers(t_cub3d *cub)
** Checks the value of index [0] after it has been departed by ft_split_plus
** to know what identifier it is and to assign the value of [1] and [2] to the
** variable and [2] to the corresponding variable in the structure.
*/

void	assignment_identifiers_colours(t_cub3d *cub)
{
	color_validation_ceilling(cub);
	color_validation_floor(cub);
}

/*
** Call-Function --> find_identifier
** Checks the value of the index [0] after it has been separated by
** ft_split_plus to know which identifier it is and to assign the value of [1]
** to the corresponding variable in the structure.
*/

int		assignment_identifiers_text_colour(t_cub3d *cub)
{
	if ((ft_strcmp("NO", cub->map.tab[0]) == 0))
		texture_validation_no(cub);
	if (ft_strcmp("SO", cub->map.tab[0]) == 0)
		texture_validation_so(cub);
	if (ft_strcmp("EA", cub->map.tab[0]) == 0)
		texture_validation_ea(cub);
	if (ft_strcmp("WE", cub->map.tab[0]) == 0)
		texture_validation_we(cub);
	if (ft_strcmp("S", cub->map.tab[0]) == 0)
		texture_validation_s(cub);
	assignment_identifiers_colours(cub);
	return (0);
}
