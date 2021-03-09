/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_player_look.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:26:20 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/08 20:01:17 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
** Ajusta los valores de la direccion hacía donde mira el jugador en el momento
** de iniciar el juego en funcion del eje cardinal donde se encontro al jugador
*/
void	where_player_look(t_cub3d *cub, char c)
{
	cub->p.dirx = 0;
	cub->p.diry = 0;
	if (c == 'N')
		cub->p.diry = -1;
	if (c == 'S')
		cub->p.diry = 1;
	if (c == 'E')
		cub->p.dirx = 1;
	if (c == 'W')
		cub->p.dirx = -1;
	cub->p.planex = cub->p.diry * -0.66;
	cub->p.planey = cub->p.dirx * 0.66;
}

