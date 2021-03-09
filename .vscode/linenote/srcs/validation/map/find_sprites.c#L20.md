```c void	find_sprites(t_cub3d *cub)
{
	int x;// coordenada x del plano
	int y;// coordeanda y del plano
	int i;// iterador del string
	int s;// contador de sprites encontrados

	i = 0;
	x = 0;
	s = 0;
	y = 0;
	cub->sprites = malloc(sizeof(t_sprite) * cub->map.count_sprites);
	while ((cub->plan.one_line_plan[i]) != '\0')
	{
		if (cub->plan.one_line_plan[i] == 'p')
		{
			x = 0;// restablece el contador de x a 0 ya que esta en una nueva fila
			y++;// suma +1 al numero de fila en el que se encuentra
		}
		if (cub->plan.one_line_plan[i] == '2')
		{
			cub->sprites[s].x = x - 0.5;// asigno el vector y que he encontrado
			cub->sprites[s].y = y + 0.5;// asigno el vector x que he encontrado
			s++;// avanzo una posicion el contador
		}
		i++;// Avanzo en el iterador que recorre el strign
		x++;// Avanzo en el iterador que recorre la la linea del mapa.
	}
}
```
