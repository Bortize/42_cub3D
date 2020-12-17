/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment_identifiers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:57:35 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/17 14:06:10 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/*	Call-Function --> find_identifier
**	Comprueba el valor del indicice [0] despues de que haya sido deparado por
**	ft_split_plus para saber que identificador es y poder asigar el valor de [1]
**	y[2] a la variable que le corresponde dentro de la estructura
*/
void	assignment_identifiers_resolution(map_config *map)
{
	if (ft_strcmp("R", map->tab[0]) == 0)
		map->flag_widht++;
		map->i++;
		integer_validation_resolution(map);
		map->width = ft_atoi(map->tab[1]);
		map->height = ft_atoi(map->tab[2]);
		ft_printf("🧪w --> %i \n", map->width);
		ft_printf("🧪h --> %i \n\n\n", map->height);
}

/*	Call-Function --> assignment_identifiers
**	Comprueba el valor del indicice [0] despues de que haya sido deparado por
**	ft_split_plus para saber que identificador es y poder asigar el valor de [1]
**	y [2] a la variable que le corresponde dentro de la estructura
*/
void	assignment_identifiers_colours(map_config *map)
{
	if (ft_strcmp("C", map->tab[0]) == 0)
	{
		map->flag_ceilling++;
		map->i++;
		map->tabcf = ft_split(map->tab[1], ',');
		validation_identifiers_ceilling(map);
		ft_printf(" 🧪 -->  %i \n", map->ceilling[0]);
		ft_printf(" 🧪 -->  %i \n", map->ceilling[1]);
		ft_printf(" 🧪 -->  %i \n\n", map->ceilling[2]);
	}
	if (ft_strcmp("F", map->tab[0]) == 0)
	{
		map->flag_floor++;
		map->i++;
		map->tabcf = ft_split(map->tab[1], ',');
		validation_identifiers_floor(map);
		ft_printf(" 🧪 -->  %i \n", map->floor[0]);
		ft_printf(" 🧪 -->  %i \n", map->floor[1]);
		ft_printf(" 🧪 -->  %i \n\n", map->floor[2]);
	}
}

/*	Call-Function --> find_identifier
**	Comprueba el valor del indicice [0] despues de que haya sido deparado por
**	ft_split_plus para saber que identificador es y poder asigar el valor de [1]
**	a la variable que le corresponde dentro de la estructura
*/
void	assignment_identifiers(map_config *map)
{
	ft_printf("🧪 --> %s \n", map->tab[0]);
	ft_printf("🧪 --> %s \n\n\n\n", map->tab[1]);
	if (ft_strcmp("NO", map->tab[0]) == 0)
	{
		map->flag_no++;
		map->i++;
		map->no = map->tab[1];
	}
	if (ft_strcmp("SO", map->tab[0]) == 0)
	{
		map->flag_so++;
		map->i++;
		map->so = map->tab[1];
	}
	if (ft_strcmp("EA", map->tab[0]) == 0)
	{
		map->flag_ea++;
		map->i++;
		map->ea = map->tab[1];
	}
	if (ft_strcmp("WE", map->tab[0]) == 0)
	{
		map->flag_we++;
		map->i++;
		map->we = map->tab[1];
	}
	if (ft_strcmp("S", map->tab[0]) == 0)
	{
		map->flag_s++;
		map->i++;
		map->s = map->tab[1];
	}
	assignment_identifiers_colours(map);
}
