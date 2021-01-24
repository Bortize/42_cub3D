/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_plan.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 20:52:45 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/24 17:32:40 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

/*
** Chequea que cada linea del plano contenga los valores permitidos en el
** subject y en tal caso, calcula la longitud de cada linea y cada vez que
** entra las va comparando para quedarse con la que tiene la mayor longitud,
** que sera utilizada para reservar memoría para la matriz mas adelante.
*/
int		validate_plan(char *str, t_cub3d *cub3d)
{
	if (cub->plan.values_ok != 1)
	{
		check_characters_plane(str, cub);
		if (cub->plan.row_len < ft_strlen(str))
			cub->plan.row_len = ft_strlen(str);
		return (1);
	}
	else
	{
		cub->plan.plan[cub->plan.i] = str;
		cub->plan.i++;
	}
	return (0);
}
