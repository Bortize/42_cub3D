/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 19:12:12 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/05 17:48:09 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../headers/cub3d.h"
/*
** Devuelve la posicion del jugador en la matriz plan->plan;
*/
char	get_pixel(int x, int y, map_plan *plan)
{
	ft_printf("El algoritmo esta en: %c \n", plan->plan[x][y]);
	return (plan->plan[x][y]);
}
