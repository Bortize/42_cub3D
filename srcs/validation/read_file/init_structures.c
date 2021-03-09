/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:52:36 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/09 01:52:15 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

/*	Call-Function -->
**	Inicializa todas las variables de la estructura para permitirnos poder
**	empezar a trabajar con ellas. Ademas elimina el valor basuara que pudieran
**	contener a la hora de su declaración
*/
void	init_structures(t_cub3d *cub)
{
	ft_bzero(cub, sizeof(t_cub3d));
	cub->plan.one_line_plan = "";
	cub->plan.boundary_value = '1';
	cub->plan.fill_value = 'f';
	cub->plan.sprite_value = '2';
}

