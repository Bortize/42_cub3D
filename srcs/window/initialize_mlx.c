/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 19:13:44 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/19 18:49:02 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	initialize_mlx(t_cub3d *cub)
{
	cub->graphic.player_pos_x = cub->plan.player_init_position_y;
	cub->graphic.player_pos_y = cub->plan.player_init_position_x;
	if (!(cub->graphic.mlx = mlx_init()))
		print_error("Fallo al iniciar MLX");
	load_textures(cub);
	cub->graphic.mlx_win = mlx_new_window(cub->graphic.mlx, cub->map.width, cub->map.height, "cub3D");
	cub->graphic.img = mlx_new_image(cub->graphic.mlx, cub->map.width, cub->map.height);
	cub->graphic.addr = mlx_get_data_addr(cub->graphic.img, &cub->graphic.bpp, &cub->graphic.line_length, &cub->graphic.endian);
	mlx_do_key_autorepeatoff(cub->graphic.mlx);// cancela el auto repeat al presioanr una tecla para que no tenga que estar gastando recurso ineficientemente.
	mlx_hook(cub->graphic.mlx_win, KEYPRESS, 0, key_press, cub);
	mlx_hook(cub->graphic.mlx_win, KEYRELEASE, 0, key_release, cub);
	mlx_loop_hook(cub->graphic.mlx, game, cub);
	//mlx_destroy_image(cub->graphic.mlx, cub->graphic.img);
	raycasting(cub);// Pongo el raycasting aqui tambien ya que cuando no presiono tecla no rendererizo nada. Es para evitar la pantalla en negro del principio.
	mlx_loop(cub->graphic.mlx);// Inicia la randeriazacion de la ventana
}
