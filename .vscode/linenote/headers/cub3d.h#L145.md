```c
typedef struct	s_cub3d
{
	t_identifiers	map;
	t_map			plan;
	t_window		graphic;
	t_controls		move;
	t_image			win;
	t_image			text[4];//	Representa los ejes cardianes donde (0 = Norte) (1 = Sur) (2 = Este) (3 = Oese)
	t_image			no_text;
	t_image			so_text;
	t_image			ea_text;
	t_image			we_text;
}				t_cub3d;
```
