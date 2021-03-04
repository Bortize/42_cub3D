/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_identifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:02:55 by bortize           #+#    #+#             */
/*   Updated: 2021/03/04 02:28:10 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	Call-Function --> read_map
**	Elimina todos los espacios y tabulaciones que contiene la linea que recibe
**	por parámetro para agrupar los string encontrados en un vector y poder
**	identificar sus valores. Tambien comprueba si el mapa tiene identificadores
**	iguales para devolver un error en ese caso
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
			print_error("El fichero .cub NO contiene el plano del mapa al final");
		else
			print_error("Hay demasiados valores en el identificador");
	}
	if (cub->map.flag_widht > 1 || cub->map.flag_no > 1 || cub->map.flag_so > 1 ||
	cub->map.flag_ea > 1 || cub->map.flag_we > 1 || cub->map.flag_s > 1 ||
	cub->map.flag_ceilling > 1 || cub->map.flag_floor > 1)
	{
		print_error("El mapa contiene identificadores repetidos."
			" Por favor, introduzca una mapa válido");
	}
	if (cub->map.i > 8)
		print_error("Hay demasiados Identidicadores, revise su mapa");
	return (0);
}
