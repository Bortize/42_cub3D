/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:27:48 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/15 22:26:32 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../headers/cub3d.h"

int	integer_validation(map_config *map)
{
	int i;
	int j;

	i = 0;
	while(i < 3)
	{
		j = 0;
		while(j < 3)
		{
			if (ft_isdigit(map->tabcf[i][j]))
				ft_printf("el numero %i es un entero \n", map->tabcf[i][j]);
			else
			{
				ft_printf("el numero %i NO es un entero \n", map->tabcf[i][j]);
				exit (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}
