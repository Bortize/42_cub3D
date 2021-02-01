/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_plane_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:58:05 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/01 12:28:42 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

/*
** Concatena todas las lineas que ha ido encontrando el GNL en un solo string
** poniendo un caracter random 'p' entre línea y línea para luego poder sepa-
** rarlas (el caracter p me sirve como identidicador de separdor entre cadenas
** ) y asignar cada linea a su respectivo puntero.
*/
int	save_plane_lines(char *str, t_cub3d *cub)
{
	cub->plan.one_line_plan = ft_strjoin(cub->plan.one_line_plan, str);
	cub->plan.one_line_plan = ft_strjoin(cub->plan.one_line_plan, "p");
	ft_printf("Concatenation Linea %s \n", cub->plan.one_line_plan);
	return (0);
}
