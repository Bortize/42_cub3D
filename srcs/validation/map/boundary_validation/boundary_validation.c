/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundary_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:37:12 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/09 01:35:09 by bgomez-r         ###   ########.fr       */
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
	if ((y < 0 || y > cub->plan.rows_size) && (x < 0 || x > (int)cub->plan.row_len))
		print_error("El plano contiene un muro que no esta cerrado");
	if ((cub->plan.plan_tmp[y][x] == 'f') || (cub->plan.plan_tmp[y][x] == '1') || (cub->plan.plan_tmp[y][x] == '2'))
	{
		ft_printf("🚫 El valor no puede modificarse \n");
	}
	else
	{
		put_pixel(x, y, cub);
		return 1;
		return (boundary_fill(x - 1, y, fill_value, boundary_value, cub) &&
		boundary_fill(x, y + 1, fill_value, boundary_value, cub) &&
		boundary_fill(x + 1, y, fill_value, boundary_value, cub) &&
		boundary_fill(x, y - 1, fill_value, boundary_value, cub));
	}
	return (1);
}
