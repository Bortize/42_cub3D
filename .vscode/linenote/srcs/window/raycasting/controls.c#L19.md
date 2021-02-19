```c
int		key_press(int keycode, t_cub3d *cub)
{
	int a;

	if (keycode == KEY_ESCAPE)
		cub->move.escape = 1;
	if (keycode == KEY_W)
		cub->move.frontal++;
	if (keycode == KEY_S)
		cub->move.frontal--;
	if (keycode == KEY_D)
		cub->move.lateral++;
	if (keycode == KEY_A)
		cub->move.lateral--;
	if (keycode == KEY_RIGHT)
		cub->move.rotating++;
	if (keycode == KEY_LEFT)
		cub->move.rotating--;
	if (keycode == KEY_6)
		a = 0;
//	if (keycode == KEY_SHIFT)
//		game->player.shifting = true;
	return (0);
}
```
Esta funcion escucha si se produce cualquier evento de presión del teclado relacionadao con el movimiento del jugador. Si cualquiera de las keycodes que tiene guardadas es activada, desplazará al jugador en la dirección que indica.

El movimiento frontal abarca tanto el desplazamiento frontal como el desplzamiento hacía atrás, solo que por tema de hacer el codigo mas legible lo llamo solo frontal.
