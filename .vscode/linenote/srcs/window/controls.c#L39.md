```c
int		key_release(int keycode, t_cub3d *cub)
{
	if (keycode == KEY_ESCAPE)
		print_error("Adios al cub3d");
	if (keycode == KEY_W)
		cub->move.frontal--;
	if (keycode == KEY_S)
		cub->move.frontal++;
	if (keycode == KEY_D)
		cub->move.lateral--;
	if (keycode == KEY_A)
		cub->move.lateral++;
	if (keycode == KEY_RIGHT)
		cub->move.rotating--;
	if (keycode == KEY_LEFT)
		cub->move.rotating++;
//	if (keycode == KEY_SHIFT)
//		game->player.shifting = true;
	return (0);
}
```

Esta función escucha cuando una tecla relacionada con el movimiento del jugador deja de ser presionada. Si cualquiera de las keycodes que tiene guardadas es activada, dejara de desplazarse el jugador en la dirección en la que lo  estaba haciendo.
