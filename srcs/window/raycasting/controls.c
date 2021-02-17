/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:44:05 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/17 20:04:07 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

/*
** Escucha si una tecla es presionada y activa el flag perteniente a
** esa tecla para luego poder gestioanrla en la funcion "player"
*/
int		key_press(int keycode, t_cub3d *cub)
{
	int a;

	if (keycode == KEY_ESCAPE)
		cub->move.escape = 1;
	if (keycode == KEY_W)
		cub->move.frontal++;
	if (keycode == KEY_S)
		cub->move.frontal--;
	if (keycode == KEY_D)
		cub->move.lateral++;
	if (keycode == KEY_A)
		cub->move.lateral--;
	if (keycode == KEY_RIGHT)
		cub->move.rotating++;
	if (keycode == KEY_LEFT)
		cub->move.rotating--;
	if (keycode == KEY_6)
		a = 0;
//	if (keycode == KEY_SHIFT)
//		game->player.shifting = true;
	return (0);
}

/*
** Escucha cuando una tecla es soltada y desactiva el flag perteniente a
** esa tecla (0) para luego poder gestioanrla en la funcion "player"
*/
int		key_release(int keycode, t_cub3d *cub)
{
	if (keycode == KEY_ESCAPE)
		print_error("Adios al cub3d");
	if (keycode == KEY_W)
		cub->move.frontal--;
	if (keycode == KEY_S)
		cub->move.frontal++;
	if (keycode == KEY_D)
		cub->move.lateral--;
	if (keycode == KEY_A)
		cub->move.lateral++;
	if (keycode == KEY_RIGHT)
		cub->move.rotating--;
	if (keycode == KEY_LEFT)
		cub->move.rotating++;
//	if (keycode == KEY_SHIFT)
//		game->player.shifting = true;
	return (0);
}
