/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_plane_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:58:05 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/04 18:13:54 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

/*
** Concatena todas las lineas que ha ido encontrando el GNL en un solo string
** poniendo un caracter random 'p' entre línea y línea para luego poder sepa-
** rarlas y asignar cada linea a su respectivo puntero.
*/
int	save_plane_lines(char *str, map_plan *plan)
{
	plan->one_line_plan = ft_strjoin(plan->one_line_plan, str);
	plan->one_line_plan = ft_strjoin(plan->one_line_plan, "p");
	ft_printf("Concatenation Linea %s \n", plan->one_line_plan);
	return (0);
}
