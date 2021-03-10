/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_plan.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 20:52:45 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/10 19:21:52 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** It checks that each line of the plane contains the values allowed in the
** subject and if so, it calculates the length of each line and each time it
** enters it compares them to keep the one with the longest length, which will
** be used to reserve memory for the matrix later on.
*/

int		validate_plan(char *str, t_cub3d *cub)
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
