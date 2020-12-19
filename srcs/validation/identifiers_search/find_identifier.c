/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_identifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:02:55 by bortize           #+#    #+#             */
/*   Updated: 2020/12/19 21:51:08 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

/*	Call-Function --> read_map
**	Elimina todos los espacios y tabulaciones que contiene la linea que recibe por
**	parámetro para agrupar los string encontrados en un vector y poder identificar
**	sus valores. Tambien comprueba si el mapa tiene identificadores iguales para
**	devolver un error en ese caso
*/
int find_identifier(char *str, map_config *map)
{
	if ((map->tab = ft_split_plus(str, ' ', '\t')))
	{
		if (map->tab[2] == NULL)
			assignment_identifiers_textures(map);
		else if (map->tab[3] == NULL)
			assignment_identifiers_resolution(map);
		else if (ft_strchr(map->tab[0], '0') || ft_strchr(map->tab[0], '1'))
			print_error("Ha introducido un fichero que no cumple las reglas."
			 " Por favor, introduzca uno que contenga el PLANO DEL MAPA al"
			 " final.");
		else
			print_error("Hay demasiados valores en el identificador");

	}
	if (map->flag_widht > 1 || map->flag_no > 1 || map->flag_so > 1 ||
	map->flag_ea > 1 || map->flag_we > 1 || map->flag_s > 1 ||
	map->flag_ceilling > 1 || map->flag_floor > 1)
	{
		print_error("El mapa contiene identificadores repetidos."
			" Por favor, introduzca una mapa válido");
	}
	if (map->i > 8)
	{
		print_error("Hay demasiados Identidicadores, revise su mapa");
	}
	return (0);
}
