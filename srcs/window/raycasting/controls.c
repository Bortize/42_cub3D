/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:44:05 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/16 20:50:23 by bgomez-r         ###   ########.fr       */
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
		cub->move.forward = 1;
	if (keycode == KEY_S)
		cub->move.backward = 1;
	if (keycode == KEY_D)
		cub->move.right = 1;
	if (keycode == KEY_A)
		cub->move.left = 1;
	if (keycode == KEY_RIGHT)
		cub->move.rotating_right = 1;
	if (keycode == KEY_LEFT)
		cub->move.rotating_left = 1;
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
		cub->move.forward = 0;
	if (keycode == KEY_S)
		cub->move.backward = 0;
	if (keycode == KEY_D)
		cub->move.right = 0;
	if (keycode == KEY_A)
		cub->move.left = 0;
	if (keycode == KEY_RIGHT)
		cub->move.rotating_right = 0;
	if (keycode == KEY_LEFT)
		cub->move.rotating_left = 0;
//	if (keycode == KEY_SHIFT)
//		game->player.shifting = true;
	return (0);
}
