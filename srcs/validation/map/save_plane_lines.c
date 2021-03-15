/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_plane_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:58:05 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/15 01:22:59 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		save_plane_lines(char *str, t_cub3d *cub)
{
	char	*aux;

	aux = cub->plan.one_line_plan;
	cub->plan.one_line_plan = ft_strjoin(aux, str);
	free(aux);
	aux = cub->plan.one_line_plan;
	cub->plan.one_line_plan = ft_strjoin(aux, "p");
	free(aux);
	return (0);
}
