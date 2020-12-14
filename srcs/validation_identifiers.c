/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_identifiers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 12:00:34 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/14 14:26:22 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../headers/cub3d.h"

/*
** Validates if the values received in C and F are in the range 255
** and if so transforms the type to integer. To do this, you must
** cast the integers to (char *)
*/
void	validation_identifiers(map_config *map)
{
	map->ptrcf[0] = ft_atoi(map->tabcf[0]);
	map->ptrcf[1] = ft_atoi(map->tabcf[1]);
	map->ptrcf[2] = ft_atoi(map->tabcf[2]);
}
