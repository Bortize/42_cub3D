/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:44:05 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/10 15:42:45 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

/*
** Activa el flag perteniente a su tecla asiganada cuadno esta es presionada
*/
int		key_press(int keycode, t_cub3d *cub)
{
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
//	if (keycode == KEY_SHIFT)
//		game->player.shifting = true;
	return (0);
}

/*
** Desativa el flag perteneciente a cada tecla cuado esta es desactivada
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
