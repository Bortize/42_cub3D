/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_player_look.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:26:20 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/17 17:32:23 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"
/*
** Ajusta los valores de la direccion hacía donde mira el jugador en el momento
** de iniciar el juego en funcion del eje cardinal donde se encontro al jugador
*/
void	where_player_look(t_cub3d *cub, char c)
{
	if (c == 'N')
	{
		cub->graphic.player_dir_x = 0;
		cub->graphic.player_dir_y = -1;
		cub->graphic.player_plane_x = 1;
		cub->graphic.player_plane_y = 0;
	}
	if (c == 'S')
	{
		cub->graphic.player_dir_x = 0;
		cub->graphic.player_dir_y = 1;
		cub->graphic.player_plane_x = -1;
		cub->graphic.player_plane_y = 0;
	}
	if (c == 'E')
	{
		cub->graphic.player_dir_x = 1;
		cub->graphic.player_dir_y = 0;
		cub->graphic.player_plane_x = 0;
		cub->graphic.player_plane_y = 1;
	}
	if (c == 'W')
	{
		cub->graphic.player_dir_x = -1;
		cub->graphic.player_dir_y = 0;
		cub->graphic.player_plane_x = 0;
		cub->graphic.player_plane_y = -1;
	}
}
