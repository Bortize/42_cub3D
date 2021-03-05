/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:44:45 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/05 11:24:53 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	graphic(t_cub3d *cub)
{
	cub->p.posx = cub->plan.player_init_position_x;
	cub->p.posy = cub->plan.player_init_position_y;
	start_mlx(&cub);
	load_textures(cub);
	mlx_do_key_autorepeatoff(cub->mlx.init);
	mlx_hook(cub->mlx.win, KEYPRESS, 0, key_press, cub);
	mlx_hook(cub->mlx.win, KEYRELEASE, 0, key_release, cub);
	mlx_loop_hook(cub->mlx.init, game, cub);
	raycast(cub);
}
