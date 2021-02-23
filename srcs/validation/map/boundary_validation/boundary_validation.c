/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundary_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:37:12 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/23 14:06:06 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
** Recorre el plano del mapa partiendo desde la posicion del jugador. Utiliza el
** metodo por inundación hasta los límites del muro. Cuando encuentra un valor
** del suelo valido, lo rellena con 'f' y sigue avanzando
*/
int	boundary_fill(int x, int y, int fill_value, int boundary_value, t_cub3d *cub)
{
	if ((x < 0 || x > cub->plan.rows_size) && (y < 0 || y > (int)cub->plan.row_len))
		print_error("El plano contiene un muro que no esta cerrado");
	ft_printf("El algoritmo esta en la coordenada %i %i y contiene %c \n", x, y, cub->plan.plan_tmp[x][y]);
	if ((cub->plan.plan_tmp[x][y] == 'f') || (cub->plan.plan_tmp[x][y] == '1') || (cub->plan.plan_tmp[x][y] == '2'))
		{
		ft_printf("🚫 El valor no puede modificarse \n");
	}
	else
	{
		put_pixel(x, y, cub);
		return (boundary_fill(x - 1, y, fill_value, boundary_value, cub) &&
		boundary_fill(x -1, y + 1, fill_value, boundary_value, cub) &&
		boundary_fill(x, y + 1, fill_value, boundary_value, cub) &&
		boundary_fill(x + 1, y + 1, fill_value, boundary_value, cub) &&
		boundary_fill(x + 1, y, fill_value, boundary_value, cub) &&
		boundary_fill(x + 1, y - 1, fill_value, boundary_value, cub) &&
		boundary_fill(x, y - 1, fill_value, boundary_value, cub) &&
		boundary_fill(x - 1, y - 1, fill_value, boundary_value, cub));
	}
	return (1);
}
