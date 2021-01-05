/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundary_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:59:10 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/05 23:28:18 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../headers/cub3d.h"
/*
** Recorre el plano del mapa partiendo desde la posicon del jugador. Utiliza el
** metodo por inundación hasta los límites del muro. Cuando encuentra un valor
** del suelo valido, lo rellena con 'f' y sigue avanzando
*/
void	boundary_fill(int x, int y, int fill_value, int boundary_value, map_plan *plan)
{
	ft_printf("El algoritmo esta en: %c \n", plan->plan[x][y]);
	if ((plan->plan[x][y] != 102) && (plan->plan[x][y] != 49) && (plan->plan[x][y] != 50))
	{
		put_pixel(plan->player_position_x, plan->player_position_y, plan);
		boundary_fill(x + 1, y, fill_value, boundary_value, plan);
		boundary_fill(x, y + 1, fill_value, boundary_value, plan);
		boundary_fill(x - 1, y, fill_value, boundary_value, plan);
		boundary_fill(x, y - 1, fill_value, boundary_value, plan);
	}
}
