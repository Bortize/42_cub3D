/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_identifiers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:00:34 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/15 14:40:09 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../headers/cub3d.h"

/*
** Validates if the values received in C and F are in the range 255
** and if so transforms the type to integer. To do this, you must
** cast the integers to (char *)
*/
void	validation_identifiers_ceilling(map_config *map)
{
	char *str;
//									HAZ UN WHILE CON ISDIGIT para saber si es numero
	str = "borja";
	ft_printf("el nombre es %s \n", (str + 1));
	map->ceilling[0] = ft_atoi(map->tabcf[0]);// no tiene sentido hacer aqui el isdigit, hay que haceroa ntes para que no se que de nignun numero perdido ya que atoy convertira hasta que encuentre una letra,
	map->ceilling[1] = ft_isdigit(ft_atoi(map->tabcf[1]));
	map->ceilling[2] = ft_isdigit(ft_atoi(map->tabcf[2]));
}

void	validation_identifiers_floor(map_config *map)
{
	map->floor[0] = ft_atoi(map->tabcf[0]);
	map->floor[1] = ft_atoi(map->tabcf[1]);
	map->floor[2] = ft_atoi(map->tabcf[2]);
}
