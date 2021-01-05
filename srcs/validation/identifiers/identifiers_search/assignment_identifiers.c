/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment_identifiers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:57:35 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/04 19:16:57 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../headers/cub3d.h"

/*
**	Is called by --> find_identifier(char *str, map_config *map);
**	Comprueba el valor del indicice [0] despues de que haya sido deparado por
**	ft_split_plus para saber que identificador es y poder asigar el valor de [1]
**	y[2] a la variable que le corresponde dentro de la estructura
**	Call to the function --> integer_validation_resolution(map);
*/

void	assignment_identifiers_resolution(map_config *map)
{
	screen_validation_r(map);
}

/*	Is called by --> assignment_identifiers(map_config *map)
**	Comprueba el valor del indicice [0] despues de que haya sido deparado por
**	ft_split_plus para saber que identificador es y poder asigar el valor de [1]
**	y [2] a la variable que le corresponde dentro de la estructura
**	Call to the function --> validation_identifiers_ceilling(map);
*/

void	assignment_identifiers_colours(map_config *map)
{
	color_validation_ceilling(map);
	color_validation_floor(map);
}

/*
**	Call-Function --> find_identifier
**	Comprueba el valor del indicice [0] despues de que haya sido separado por
**	ft_split_plus para saber que identificador es y poder asigar el valor de [1]
**	a la variable que le corresponde dentro de la estructura
*/

int	assignment_identifiers_text_colour(map_config *map)
{
	ft_printf("🧪 --> %s \n", map->tab[0]);
	ft_printf("🧪 --> %s \n\n\n\n", map->tab[1]);
	if ((ft_strcmp("NO", map->tab[0]) == 0))
		texture_validation_no(map);
	if (ft_strcmp("SO", map->tab[0]) == 0)
		texture_validation_so(map);
	if (ft_strcmp("EA", map->tab[0]) == 0)
		texture_validation_ea(map);
	if (ft_strcmp("WE", map->tab[0]) == 0)
		texture_validation_we(map);
	if (ft_strcmp("S", map->tab[0]) == 0)
		texture_validation_s(map);
	assignment_identifiers_colours(map);
	return (0);
}
