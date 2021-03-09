/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:44:05 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/05 20:51:31 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
** Escucha si una tecla es presionada y activa el flag perteniente a
** esa tecla para luego poder gestioanrla en la funcion "player"
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
** Escucha cuando una tecla es soltada y desactiva el flag perteniente a
** esa tecla (0) para luego poder gestioanrla en la funcion "player"
*/
int		key_release(int keycode, t_cub3d *cub)
{
	if (keycode == KEY_ESC)
		print_error("Cerrando Cub3D");
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
