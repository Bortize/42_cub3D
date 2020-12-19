/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment_identifiers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:57:35 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/19 19:41:35 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

/*
**	Is called by --> find_identifier(char *str, map_config *map);
**	Comprueba el valor del indicice [0] despues de que haya sido deparado por
**	ft_split_plus para saber que identificador es y poder asigar el valor de [1]
**	y[2] a la variable que le corresponde dentro de la estructura
**	Call to the function --> integer_validation_resolution(map);
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

/*	Is called by --> assignment_identifiers(map_config *map)
**	Comprueba el valor del indicice [0] despues de que haya sido deparado por
**	ft_split_plus para saber que identificador es y poder asigar el valor de [1]
**	y [2] a la variable que le corresponde dentro de la estructura
**	Call to the function --> validation_identifiers_ceilling(map);
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

/*
**	Call-Function --> find_identifier
**	Comprueba el valor del indicice [0] despues de que haya sido deparado por
**	ft_split_plus para saber que identificador es y poder asigar el valor de [1]
**	a la variable que le corresponde dentro de la estructura
*/

int	assignment_identifiers(map_config *map)
{
	ft_printf("🧪 --> %s \n", map->tab[0]);
	ft_printf("🧪 --> %s \n\n\n\n", map->tab[1]);
	if ((ft_strcmp("NO", map->tab[0]) == 0))
	{
		if (map->flag_no == 0)
		{
			path_validation(map->tab[1]);
			map->flag_no++;
			map->i++;
			map->no = map->tab[1];
		}
		else
		{
			print_error("El fichero '.cub' contiene identificadores "
				"duplicados. \nPor favor, introduzca un fichero válido");
		}	
	}
	if (ft_strcmp("SO", map->tab[0]) == 0)
	{
		path_validation(map->tab[1]);
		if (map->flag_so == 0)
		{
			map->flag_so++;
			map->i++;
			map->so = map->tab[1];
		}
		else
		{
			print_error("El fichero '.cub' contiene identificadores "
				"duplicados. \nPor favor, introduzca un fichero válido");
		}	
	}
	if (ft_strcmp("EA", map->tab[0]) == 0)
	{
		path_validation(map->tab[1]);
		if (map->flag_ea == 0)
		{
			map->flag_ea++;
			map->i++;
			map->ea = map->tab[1];
		}
		else
		{
			print_error("El fichero '.cub' contiene identificadores "
				"duplicados. \nPor favor, introduzca un fichero válido");
		}	
	}
	if (ft_strcmp("WE", map->tab[0]) == 0)
	{
		path_validation(map->tab[1]);
		if (map->flag_we == 0)
		{
			map->flag_we++;
			map->i++;
			map->we = map->tab[1];
		}
		else
		{
			print_error("El fichero '.cub' contiene identificadores "
				"duplicados.\n Por favor, introduzca un fichero válido");
		}	
	}
	if (ft_strcmp("S", map->tab[0]) == 0)
	{
		path_validation(map->tab[1]);
		if (map->flag_s == 0)
		{
			map->flag_s++;
			map->i++;
			map->s = map->tab[1];
		}
		else
		{
			print_error("El fichero '.cub' contiene identificadores "
				"duplicados. \nPor favor, introduzca un fichero válido");
		}	
	}
	assignment_identifiers_colours(map);
	return (0);
}
