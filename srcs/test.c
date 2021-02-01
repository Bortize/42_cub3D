/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:48:09 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/01 15:30:04 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../headers/cub3d.h"
#ifndef CUB3D_H
#define CUB3D_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <math.h>

#include "../minilibx_opengl/mlx.h"
#include "../printf/libft/libft.h"
//#include "map1.h"
#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

int worldMap[mapWidth][mapHeight] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 0, 0, 0, 5, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

// Initial values
//1280*620
#define WIN_X           640
#define WIN_Y           480
#define INIT_P_POS_X    22
#define INIT_P_POS_Y    12
#define INIT_P_DIR_X    -1
#define INIT_P_DIR_Y    0
#define INIT_P_PLANE_X  0
#define INIT_P_PLANE_Y  0.66
#define MV_SPEED 		0.199		//0.199
#define ROT_SPEED		0.1745		//0.1745
#define AMB_LIGHT       7

// Colors
#define WHITE           0xFFFFFF
#define RED             0xFF0000
#define GREEN           0x00FF00
#define BLUE            0x0000FF
#define BLACK           0x000000

typedef struct      s_raycaster
{
  void	          *mlx_ptr;
  void	          *win_ptr;
  double          player_pos_x;//		El vector de posicion del jugador.
  double          player_pos_y;//		El vector de posicion del jugador.
  double          player_dir_x;//		La direccion del jugador.
  double          player_dir_y;//		La direccion del jugador.
  double          player_plane_x;//		Plano de la camara del jugador.
  double          player_plane_y;//		Plano de la camara del jugador.
  double          ray_dir_x;//			Direccion del pixel del plano de la camara.
  double          ray_dir_y;//			Direccion del pixel del plano de la camara.
  int             map_x;//				Cuadrado actual del mapa donde se encuentra el rayo.
  int             map_y;//				Cuadrado actual del mapa donde se encuentra el rayo.
  double          side_dist_x;//		Distancia que el rayo tiene que recorrer desde su posicion inicial hasta el primer lado de 'x'
  double          side_dist_y;//		Distancia que el rayo tiene que recorrer desde su posicion inicial hasta el primer lado de 'y'
  double          delta_dist_x;//		Distancia que el rayo tiene que recorrer de 1 lado x al siguiente lado x.
  double          delta_dist_y;//		Distancia que el rayo tiene que recorrer de 1 lado y al siguiente lado y.
  int             step_x;//				Dirección en la que el jugador tiene que avanzar.
  int             step_y;//				Direccion en la que le jugador tiene. que avanzar.
  int             side;//
  int             draw_start;//
  int             draw_end;//
  double          perp_wall_dist;//
} t_raycaster;


#endif


int           init(t_raycaster *rc)
{


  rc->mlx_ptr = NULL;
  rc->win_ptr = NULL;
  rc->player_pos_x = INIT_P_POS_X;
  rc->player_pos_y = INIT_P_POS_Y;
  rc->player_dir_x = INIT_P_DIR_X;
  rc->player_dir_y = INIT_P_DIR_Y;
  rc->player_plane_x = INIT_P_PLANE_X;
  rc->player_plane_y = INIT_P_PLANE_Y;

  if(!(rc->mlx_ptr = mlx_init()))
  {
	fprintf(stderr,"SDL initialization failed\n");
    return (-1);
  }
  if (!(rc->win_ptr = mlx_new_window(rc->mlx_ptr, WIN_X, WIN_Y, "mx 42")))
  {
    fprintf(stderr,"Window creation failed\n");
    return (-1);
  }
  return (0);
}
void	refresh_screen(t_raycaster *rc){
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < WIN_X)
	{
		while (y < WIN_Y)
		{
			mlx_pixel_put(rc->mlx_ptr, rc->win_ptr, x, y, 0x000000);
			y++;
		}
		y=0;
		x++;
	}
}

void          initial_calc(t_raycaster *rc, int x)
{
  double      camera_x;// coordenada x en el plano de la camara que represneta la actual coordenada x de la pantalla.
// AHORA SE PROCEDE A CALCULAR LA DIRECCION DE LA SEMIRECTA.
  camera_x = 2 * x / (double)(WIN_X) - 1;
  rc->ray_dir_x = rc->player_dir_x + rc->player_plane_x * camera_x;
  rc->ray_dir_y = rc->player_dir_y + rc->player_plane_y * camera_x;
  rc->map_x = (int)(rc->player_pos_x);
  rc->map_y = (int)(rc->player_pos_y);
  rc->delta_dist_x = sqrt(1 + pow(rc->ray_dir_y, 2) / pow(rc->ray_dir_x, 2));
  rc->delta_dist_y = sqrt(1 + pow(rc->ray_dir_x, 2) / pow(rc->ray_dir_y, 2));
  if (rc->ray_dir_x < 0)
  {
    rc->step_x = -1;
    rc->side_dist_x = (rc->player_pos_x - rc->map_x) * rc->delta_dist_x;
  }
  else
  {
    rc->step_x = 1;
    rc->side_dist_x = (rc->map_x + 1.0 - rc->player_pos_x) * rc->delta_dist_x;
  }
  if (rc->ray_dir_y < 0)
  {
    rc->step_y = -1;
    rc->side_dist_y = (rc->player_pos_y - rc->map_y) * rc->delta_dist_y;
  }
  else
  {
    rc->step_y = 1;
    rc->side_dist_y = (rc->map_y + 1.0 - rc->player_pos_y) * rc->delta_dist_y;
  }
}

void          perform_dda(t_raycaster *rc)
{
  int         hit;

  hit = 0;
  while (hit == 0)
  {
    if (rc->side_dist_x < rc->side_dist_y)
    {
      rc->side_dist_x += rc->delta_dist_x;
      rc->map_x += rc->step_x;
      rc->side = 0;
    }
    else
    {
      rc->side_dist_y += rc->delta_dist_y;
      rc->map_y += rc->step_y;
      rc->side = 1;
    }
    if (worldMap[rc->map_x][rc->map_y] > 0)
      hit = 1;
  }
}

void          calc_wall_height(t_raycaster *rc)
{
  int         line_height;

  if (rc->side == 0)
    rc->perp_wall_dist = (rc->map_x - rc->player_pos_x + (1 - rc->step_x) / 2) / rc->ray_dir_x;
  else
    rc->perp_wall_dist = (rc->map_y - rc->player_pos_y + (1 - rc->step_y) / 2) / rc->ray_dir_y;
  line_height = (int)(WIN_Y / rc->perp_wall_dist);
  rc->draw_start = -line_height / 2 + WIN_Y / 2;
  if (rc->draw_start < 0)
    rc->draw_start = 0;
  rc->draw_end = line_height / 2 + WIN_Y / 2;
  if (rc->draw_end >= WIN_Y)
    rc->draw_end = WIN_Y - 1;
}

void          draw_vert_line(t_raycaster *rc, int x)
{
	int color;
	int y;

	color = BLUE;
	if (worldMap[rc->map_x][rc->map_y] == 1)
		color = WHITE;
	if (worldMap[rc->map_x][rc->map_y] == 2)
		color = GREEN;
	if (worldMap[rc->map_x][rc->map_y] == 3)
		color = GREEN;
	if(worldMap[rc->map_x][rc->map_y] == 4)
		color = RED;
	if (worldMap[rc->map_x][rc->map_y] == 5)
		color = BLACK;

	if (rc->side == 1)
		color = color + 3000;
	else
		color = color;

	y = rc->draw_start;
	while (y < rc->draw_end)
	{
		mlx_pixel_put(rc->mlx_ptr, rc->win_ptr, x, y, color);
		y++;
	}
}

int handle_events(int key, t_raycaster *rc)
{
	double oldDirX;
	double oldPlaneX;
		if (key == 53)
		{
			system("killall a.out && clear");
			return (-1);
		}
		if (key == 125 || key == 126 || key == 124 || key == 123)
		{
			if (key == 126)
			{
				if (worldMap[(int)(rc->player_pos_x + rc->player_dir_x * MV_SPEED)][(int)(rc->player_pos_y)] == 0)
					rc->player_pos_x += rc->player_dir_x * MV_SPEED;
				if (worldMap[(int)(rc->player_pos_x)][(int)(rc->player_pos_y + rc->player_dir_y * MV_SPEED)] == 0)
					rc->player_pos_y += rc->player_dir_y * MV_SPEED;
			}
			if (key == 125)
			{
				if (worldMap[(int)(rc->player_pos_x - rc->player_dir_x * MV_SPEED)][(int)(rc->player_pos_y)] == 0)
					rc->player_pos_x -= rc->player_dir_x * MV_SPEED;
				if (worldMap[(int)(rc->player_pos_x)][(int)(rc->player_pos_y - rc->player_dir_y * MV_SPEED)] == 0)
					rc->player_pos_y -= rc->player_dir_y * MV_SPEED;
			}
			if (key == 124)
			{
				oldDirX = rc->player_dir_x;
				rc->player_dir_x = rc->player_dir_x * cos(-ROT_SPEED) - rc->player_dir_y * sin(-ROT_SPEED);
				rc->player_dir_y = oldDirX * sin(-ROT_SPEED) + rc->player_dir_y * cos(-ROT_SPEED);
				oldPlaneX = rc->player_plane_x;
				rc->player_plane_x = rc->player_plane_x * cos(-ROT_SPEED) - rc->player_plane_y * sin(-ROT_SPEED);
				rc->player_plane_y = oldPlaneX * sin(-ROT_SPEED) + rc->player_plane_y * cos(-ROT_SPEED);
			}
			if (key == 123)
			{
				oldDirX = rc->player_dir_x;
				rc->player_dir_x = rc->player_dir_x * cos(ROT_SPEED) - rc->player_dir_y * sin(ROT_SPEED);
				rc->player_dir_y = oldDirX * sin(ROT_SPEED) + rc->player_dir_y * cos(ROT_SPEED);
				oldPlaneX = rc->player_plane_x;
				rc->player_plane_x = rc->player_plane_x * cos(ROT_SPEED) - rc->player_plane_y * sin(ROT_SPEED);
				rc->player_plane_y = oldPlaneX * sin(ROT_SPEED) + rc->player_plane_y * cos(ROT_SPEED);
			}
		}
	return (0);
}

// Principal loop
int raycasting(int key, t_raycaster *rc)
{
	int x;

	x = 0;
	refresh_screen(rc);
	//for
	while (x < WIN_X)
    {
		initial_calc(rc, x);
		perform_dda(rc);
    	calc_wall_height(rc);
		draw_vert_line(rc, x);
	  	x++;
    }
	if (handle_events(key,rc) != 0)
		return (-1);
	return (0);
}

int		main(void)
{
	t_raycaster		*rc;

	rc = malloc(sizeof(t_raycaster));
	if (init(rc) != 0)
		return (-1);

	mlx_hook(rc->win_ptr, 2, 1L << 0, &raycasting, rc);
	mlx_hook(rc->win_ptr, 3, 1L << 1, &raycasting, rc);
	//mlx_key_hook(rc->win_ptr, raycasting, rc);
	mlx_loop(rc->mlx_ptr);

	return(0);
}
