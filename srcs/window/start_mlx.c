/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:47:07 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/14 13:49:30 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_mlx(t_cub3d *cub)
{
	int	width;
	int	height;

	if (!(cub->mlx.init = mlx_init()))
		print_error("Failure to start MLX");
	printf("file config resolution %i %i\n", cub->map.width, cub->map.height);
	// TODO: Viendo que ya usas bmp_flag, tendremos que mejorar alguna parte del
	// código para que funcione segun el subject. Si usamos --save, no tendremos que ajustar la resolución
	// al máximo de la pantalla. Importante, cuando se use --save, no se debe
	// mostrar ninguna ventana, eso quiere decir que mlx_new_window no debe ser
	// llamado y, por tanto, ninguna función que dependa de cub->mlx.win
	// IMPORTANTE: Esto va a petar el programa cuando se use --save. Dos motivos esencialmente:
	// 	1. se usará mlx_hook..... para el teclado y para ver si la ventana se ha cerrado.
	// 	2. se usará mlx_image_to_window.
	if (!cub->bmp_flag)
	{
		mlx_get_screen_size(cub->mlx.init, &width, &height);
		printf("max resolution %i %i\n", width, height);
		if (cub->map.width > width)
			cub->map.width = width;
		if (cub->map.height > height)
			cub->map.height = height;
		cub->mlx.win = mlx_new_window(cub->mlx.init, cub->map.width,
			cub->map.height, "cub3D");
	}
	cub->mlx.img = mlx_new_image(cub->mlx.init, cub->map.width,
		cub->map.height);
	cub->mlx.addr = mlx_get_data_addr(cub->mlx.img, &cub->mlx.bpp,
		&cub->mlx.line_len, &cub->mlx.endian);
}
