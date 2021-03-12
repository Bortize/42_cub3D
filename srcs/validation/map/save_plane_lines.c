/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_plane_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:58:05 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/12 20:38:17 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** It concatenates all the lines found by the GNL in a single string by
** putting a random character 'p' between each line to separate them (the
** character p serves as a separator identifier between strings) and assign
** each line to its respective pointer.
*/

int	save_plane_lines(char *str, t_cub3d *cub)
{
	cub->plan.one_line_plan = ft_strjoin(cub->plan.one_line_plan, str);
	cub->plan.one_line_plan = ft_strjoin(cub->plan.one_line_plan, "p");
	return (0);
}
