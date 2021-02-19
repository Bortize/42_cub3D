```c
int	raycasting(t_cub3d *cub)
{
	int x;

	x = 0;
	refresh_screen(cub);
	//for
	while (x < cub->map.width)// Mientras x sea menor que el ancho de la resolucion de la ventana
	{
		initial_calc(cub, x);
		perform_dda(cub);// el algoritmo en bucle que va a calcular cuadno chocque el rayo
		calc_wall_height(cub);// Calcula la altura del muro una vez que el rayo choca con el muro
		draw_vert_line(cub, x);// Dibuja las franjas de los pixeles de izq a dcha
		raycast_texture(cub);
		cast_texture(cub);
		draw_textured_line(cub, x);
		x++;
	}
	mlx_put_image_to_window(cub->graphic.mlx, cub->graphic.mlx_win, cub->graphic.img, 0, 0);
//	if (handle_events(keycode, cub) != 0)
//		return (-1);
	return (0);
}
```

refresh_screen(cub);|
|-|

Refresca la pantalla para crear la nueva imagen
<br><br><br>

initial_calc(cub, x);|
|-|

Realiza los calculos iniciales para poder trabajar en el lanzaminto de rayos.
<br><br><br>

perform_dda(cub);|
|-|

Avanza por las baldosas del plano comprobando si el rayo ha impactado en algún muro.
<br><br><br>

calc_wall_height(cub);|
|-|

Calcula la altura de los muros utilizando la distancia perpecdicular en vez de la distancia real euclidiana.
<br><br><br>




draw_vert_line(cub, x);|
|-|

Selecciona el color para los muros en funcion de a donde apunte el rayo.
<br><br><br>

raycast_texture(cub);|
|-|

Añade las texturas a los muros
<br><br><br>

cast_texture(cub);|
|-|

Castea la textura para mostrar el pixel de la textura
<br><br><br>

draw_textured_line(cub, x);|
|-|


<br><br><br>

mlx_put_image_to_window(cub->graphic.mlx, cub->graphic.mlx_win, cub->graphic.img, 0, 0);|
|-|

Envia el frame que se ha dibujado a la ventana donde el jugador podrá visualizarlo.
<br><br><br>
