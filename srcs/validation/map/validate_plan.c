/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_plan.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 20:52:45 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/30 08:47:29 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

/*
** Chequea que cada linea del plano contenga los valores permitidos en el
** subject y en tal caso, calcula la longitud de cada linea y las va comparando
** para quedarse con la que tiene la mayor longitud, que sera utilizada para
** reservar memoría para la matriz mas adelante.
*/
int		validate_plan(char *str, map_plan *plan)
{
	if (plan->values_ok != 1)
	{
		check_characters_plane(str, plan);
		if (plan->row_len < ft_strlen(str))
			plan->row_len = ft_strlen(str);
		return (1);
	}
	else
	{
		plan->plan[plan->i] = str;
		plan->i++;
	}
	return (0);
}
