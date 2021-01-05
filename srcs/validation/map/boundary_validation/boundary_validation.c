/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundary_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:59:10 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/05 01:19:15 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../headers/cub3d.h"
/*
** Recorre el plano del mapa partiendo desde la posicon del jugador. Utiliza el
** metodo por inundación hasta los límites del muro. Cuando encuentra un valor
** del suelo valido, lo rellena con 'f' y sigue avanzadno
*/
void	boundary_fill(int x, int y, int fill_value, int boundary_value, map_plan *plan)
{
	if ((get_pixel(x, y, &plan) != fill_value) && (get_pixel(x, y) != boundary_value))
	{
		put_pixel(plan->player_position_x, plan->player_positon_y, fill_value);
	}
}
