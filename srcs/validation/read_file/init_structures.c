/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:52:36 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/08 12:43:50 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

/*	Call-Function -->
**	Inicializa todas las variables de la estructura para permitirnos poder
**	empezar a trabajar con ellas. Ademas elimina el valor basuara que pudieran
**	contener a la hora de su declaración
*/
/*
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

static void	init_mlx(t_cub3d *cub)
{
	cub->mlx.init = 0;
	cub->mlx.win = 0;
	cub->mlx.img = 0;
	cub->mlx.addr = 0;
	cub->mlx.bpp = 0;
	cub->mlx.line_len = 0;
	cub->mlx.endian = 0;
}

static void	init_player(t_cub3d *cub)
{
	cub->p.posx = 0;
	cub->p.posy = 0;
	cub->p.dirx = 0;
	cub->p.diry = 0;
	cub->p.planex = 0;
	cub->p.planey = 0;
}

static void	init_raycast(t_cub3d *cub)
{
	cub->rcast.x = 0;
	cub->rcast.camerax = 0;
	cub->rcast.raydirx  = 0;
	cub->rcast.raydiry = 0;
	cub->rcast.mapx = 0;
	cub->rcast.mapy = 0;
	cub->rcast.sidedistx = 0;
	cub->rcast.sidedisty = 0;
	cub->rcast.deltadistx = 0;
	cub->rcast.deltadisty = 0;
	cub->rcast.perpwalldist = 0;
	cub->rcast.stepx = 0;
	cub->rcast.stepy = 0;
	cub->rcast.hit = 0;
	cub->rcast.side = 0;
	cub->rcast.wallx = 0;
	cub->rcast.texnum = 0;
}

static void	init_window(t_cub3d *cub)
{
	cub->win.lineheight = 0;
	cub->win.drawstart = 0;
	cub->win.drawend = 0;
}

static void	init_texture(t_cub3d *cub)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_bzero(&cub->tex.walls[i], sizeof(t_texture));
		i++;
	}
}
*/

void	init_structures(t_cub3d *cub)
{
	ft_bzero(cub, sizeof(t_cub3d));
	cub->plan.one_line_plan = "";
	cub->plan.boundary_value = '1';
	cub->plan.fill_value = 'f';
	cub->plan.sprite_value = '2';
	//init_identifiers(cub);
	//init_map(cub);
	//init_mlx(cub);
	//init_raycast(cub);
	//init_player(cub);
	//init_window(cub);
	//init_texture(cub);
}

