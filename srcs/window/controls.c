/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:44:05 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/17 14:25:43 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** It listens if a key is pressed and activates the flag belonging to that
** key in order to manage it in the "player" function.
*/

int	key_press(int keycode, t_cub3d *cub)
{
	if (keycode == KEY_ESC)
		cub->ctrl.esc = 1;
	if (keycode == KEY_W)
		cub->ctrl.forward++;
	if (keycode == KEY_S)
		cub->ctrl.forward--;
	if (keycode == KEY_D)
		cub->ctrl.sideways++;
	if (keycode == KEY_A)
		cub->ctrl.sideways--;
	if (keycode == KEY_RIGHT)
		cub->ctrl.rotate++;
	if (keycode == KEY_LEFT)
		cub->ctrl.rotate--;
	return (0);
}

/*
** Listens when a key is released and deactivates the flag belonging to
** that key (0) in order to manage it in the "player" function.
*/

int	key_release(int keycode, t_cub3d *cub)
{
	if (keycode == KEY_ESC)
	{
		system("leaks -fullContent cub3D");
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_W)
		cub->ctrl.forward--;
	if (keycode == KEY_S)
		cub->ctrl.forward++;
	if (keycode == KEY_D)
		cub->ctrl.sideways--;
	if (keycode == KEY_A)
		cub->ctrl.sideways++;
	if (keycode == KEY_RIGHT)
		cub->ctrl.rotate--;
	if (keycode == KEY_LEFT)
		cub->ctrl.rotate++;
	return (0);
}
