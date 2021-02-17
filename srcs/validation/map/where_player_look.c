/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_player_look.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:26:20 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/17 18:30:46 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
** Ajusta los valores de la direccion hacía donde mira el jugador en el momento
** de iniciar el juego en funcion del eje cardinal donde se encontro al jugador
*/
void	where_player_look(t_cub3d *cub, char c)
{
	t_window *g;

	g = &cub->graphic;
	g->player_dir_x = 0;
	g->player_dir_y = 0;
	if (c == 'N')
		g->player_dir_y = -1;
	if (c == 'S')
		g->player_dir_y = 1;
	if (c == 'E')
		g->player_dir_x = 1;
	if (c == 'W')
		g->player_dir_x = -1;
	g->player_plane_x = -g->player_dir_y;
	g->player_plane_y = g->player_dir_x;
}

