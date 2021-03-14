/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:44:45 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/14 13:49:30 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	win_close(t_cub3d *cub)
{
	exit(EXIT_SUCCESS);
}

void	graphic(t_cub3d *cub)
{
	cub->p.posx = cub->plan.player_init_position_x;
	cub->p.posy = cub->plan.player_init_position_y;
	start_mlx(cub);
	load_textures(cub);
	mlx_do_key_autorepeatoff(cub->mlx.init);
	mlx_hook(cub->mlx.win, KEYPRESS, KEYPRESSMASK, key_press, cub);
	mlx_hook(cub->mlx.win, KEYRELEASE, KEYRELEASEMASK, key_release, cub);
	mlx_hook(cub->mlx.win, WINDOWCLOSE, WINDOWCLOSEMASK, win_close, cub);
	mlx_loop_hook(cub->mlx.init, game, cub);
	raycast_init(cub);
	mlx_loop(cub->mlx.init);
}
