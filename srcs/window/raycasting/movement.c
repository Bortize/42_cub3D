/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:40:20 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/09 09:49:55 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

void	move_forward(t_cub3d *cub)
{
	if (cub->plan.plan[(int)(cub->graphic.player_pos_y)][(int)
	(cub->graphic.player_pos_x + cub->graphic.player_dir_x * MV_SPEED)] == '0')
		cub->graphic.player_pos_x += cub->graphic.player_dir_x * MV_SPEED;

	if (cub->plan.plan[(int)(cub->graphic.player_pos_y +
	cub->graphic.player_dir_y * MV_SPEED)][(int)(cub->graphic.player_pos_x)]
	== '0')
		cub->graphic.player_pos_y += cub->graphic.player_dir_y * MV_SPEED;
}

void	move_backward(t_cub3d *cub)
{
	if (cub->plan.plan[(int)(cub->graphic.player_pos_y)]
	[(int)(cub->graphic.player_pos_x - cub->graphic.player_dir_x * MV_SPEED)]
	== '0')
		cub->graphic.player_pos_x -= cub->graphic.player_dir_x * MV_SPEED;

	if (cub->plan.plan[(int)(cub->graphic.player_pos_y -
	cub->graphic.player_dir_y * MV_SPEED)][(int)(cub->graphic.player_pos_x)]
	== '0')
		cub->graphic.player_pos_y -= cub->graphic.player_dir_y * MV_SPEED;
}

void	move_right(t_cub3d *cub)
{
	if (cub->plan.plan[(int)(cub->graphic.player_pos_y)]
	[(int)(cub->graphic.player_pos_x - cub->graphic.player_dir_y * MV_SPEED)]
	== '0')
		cub->graphic.player_pos_x -= cub->graphic.player_dir_y * MV_SPEED;

	if (cub->plan.plan[(int)(cub->graphic.player_pos_y -
	cub->graphic.player_dir_x * MV_SPEED)][(int)(cub->graphic.player_pos_x)]
	== '0')
		cub->graphic.player_pos_y += cub->graphic.player_dir_x * MV_SPEED;
}

void	move_left(t_cub3d *cub)
{
	if (cub->plan.plan[(int)(cub->graphic.player_pos_y)]
	[(int)(cub->graphic.player_pos_x + cub->graphic.player_dir_y * MV_SPEED)]
	== '0')
		cub->graphic.player_pos_x += cub->graphic.player_dir_y * MV_SPEED;

	if (cub->plan.plan[(int)(cub->graphic.player_pos_y +
	cub->graphic.player_dir_x * MV_SPEED)][(int)(cub->graphic.player_pos_x)]
	== '0')
		cub->graphic.player_pos_y -= cub->graphic.player_dir_x * MV_SPEED;
}

void	scape(void)
{
		print_error("Escape");
}

/*
** Funcionees de movimiento del jugador
*/
void	movement(t_cub3d *cub)
{
	if (cub->move.forward == 1)
		move_forward(cub);
	if (cub->move.backward == 1)
		move_backward(cub);
	if (cub->move.left == 1)
		move_left(cub);
	if (cub->move.right == 1)
		move_right(cub);
	if (cub->move.escape == 1)
		scape();
}
