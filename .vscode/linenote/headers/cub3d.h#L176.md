```c
typedef struct	s_cub3d
{
	double		*zbuffer;
	t_parse		map;// Parseo del juego
	t_map		plan;// Plano del juego
	t_mlx		mlx;// Configuracion mlx
	t_controls	ctrl;// Controloes del juego
	t_raycast	rcast;// Raycast
	t_player	p;// Jugador
	t_window	win;// Ventana
//	t_texture	tex[4];// Array de configuracion de texturas para los muros y sprite
	t_textures	tex;
	t_sprite	*sprites;// arry de sprites. Donde se almacenan las posiciones de todod los sprites
	int			*spriteorder;
	int			bmp_flag;
}				t_cub3d;
```
