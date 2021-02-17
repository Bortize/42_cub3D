/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:40:20 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/17 19:52:35 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

void	set_plan_position(t_cub3d *cub, double x, double y)
{
	if (cub->plan.plan[(int)cub->graphic.player_pos_y][(int)x] == '0')
		cub->graphic.player_pos_x = x;
	if (cub->plan.plan[(int)y][(int)cub->graphic.player_pos_x] == '0')
		cub->graphic.player_pos_y = y;
}

void	move_frontal(t_cub3d *cub)
{
	double	pos_x;
	double	pos_y;
	double  speed;

	speed = MV_SPEED * cub->move.frontal;
	pos_x = cub->graphic.player_pos_x + cub->graphic.player_dir_x * speed;
	pos_y = cub->graphic.player_pos_y + cub->graphic.player_dir_y * speed;
	set_plan_position(cub, pos_x, pos_y);
}


void	move_lateral(t_cub3d *cub)
{
	double	pos_x;
	double	pos_y;
	double	speed;

	speed = MV_SPEED * cub->move.lateral;
	pos_x = cub->graphic.player_pos_x - cub->graphic.player_dir_y * speed;
	pos_y = cub->graphic.player_pos_y + cub->graphic.player_dir_x * speed;
	set_plan_position(cub, pos_x, pos_y);
}

/*
** Funcionees de movimiento del jugador
*/
void	movement(t_cub3d *cub)
{
	move_frontal(cub);
	move_lateral(cub);
//	if (cub->move.escape == 1)
//		print_error("cub3d Cerrado\n");
}
