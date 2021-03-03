/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:52:36 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/03 15:42:17 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

/*	Call-Function -->
**	Inicializa todas las variables de la estructura para permitirnos poder
**	empezar a trabajar con ellas. Ademas elimina el valor basuara que pudieran
**	contener a la hora de su declaración
*/
void	init_identifiers(t_cub3d *cub)
{
	cub->map.i = 0;
	cub->map.width = 0;
	cub->map.flag_widht = 0;
	cub->map.height = 0;
	cub->map.flag_height = 0;
	cub->map.no = 0;
	cub->map.flag_no = 0;
	cub->map.so = 0;
	cub->map.flag_so = 0;
	cub->map.ea = 0;
	cub->map.flag_ea = 0;
	cub->map.we = 0;
	cub->map.flag_we = 0;
	cub->map.s = 0;
	cub->map.flag_s = 0;
	cub->map.flag_floor = 0;
	cub->map.flag_ceilling = 0;
	cub->map.flag_map_ready = 0;
}

void	init_map(t_cub3d *cub)
{
	cub->plan.i = 0;
	cub->plan.rows_size = 0;
	cub->plan.row_len = 0;
	cub->plan.values_ok = 0;
	cub->plan.one_line_plan = "";
	cub->plan.boundary_value = '1';
	cub->plan.fill_value = 'f';
	cub->plan.sprite_value = '2';
	cub->plan.player_init_position_x = 0;//	Vector de posicion del jugador x (inicial)
	cub->plan.player_init_position_y = 0;
}

void	init_window(t_cub3d *cub)
{
	cub->graphic.player_pos_x = 0;
	cub->graphic.player_pos_y = 0;
	//cub->graphic.line_height = ;
	cub->move.frontal = 0;// flag movimiento frontal y trasero del jugador.
	cub->move.lateral = 0;// flag moviemto lateral del jugador
	cub->move.rotating = 0;// flag rotación
}

void	init_sprites(t_cub3d *cub)
{
	cub->sprites = NULL;
	cub->count_sprites = 0;
}

void	init_structures(t_cub3d *cub)
{
	init_identifiers(cub);
	init_map(cub);
	init_window(cub);
	init_sprites(cub);
	cub->flag_malloc_sprites = 0;
}

