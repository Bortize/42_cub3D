/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment_identifiers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:57:35 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/23 14:04:38 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Is called by --> find_identifier(char *str, t_cub3d *cub);
**	Comprueba el valor del indicice [0] despues de que haya sido deparado por
**	ft_split_plus para saber que identificador es y poder asigar el valor de [1]
**	y[2] a la variable que le corresponde dentro de la estructura
**	Call to the function --> integer_validation_resolution(cub);
*/

void	assignment_identifiers_resolution(t_cub3d *cub)
{
	screen_validation_r(cub);
}

/*	Is called by --> assignment_identifiers(t_cub3d *cub)
**	Comprueba el valor del indicice [0] despues de que haya sido deparado por
**	ft_split_plus para saber que identificador es y poder asigar el valor de [1]
**	y [2] a la variable que le corresponde dentro de la estructura
**	Call to the function --> validation_identifiers_ceilling(cub);
*/

void	assignment_identifiers_colours(t_cub3d *cub)
{
	color_validation_ceilling(cub);
	color_validation_floor(cub);
}

/*
**	Call-Function --> find_identifier
**	Comprueba el valor del indicice [0] despues de que haya sido separado por
**	ft_split_plus para saber que identificador es y poder asigar el valor de [1]
**	a la variable que le corresponde dentro de la estructura
*/

int	assignment_identifiers_text_colour(t_cub3d *cub)
{
	ft_printf("🧪 --> %s \n", cub->map.tab[0]);
	ft_printf("🧪 --> %s \n\n\n\n", cub->map.tab[1]);
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
