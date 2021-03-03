```c
	if (cub->count_sprites == 0)
		return ;
```
Si no se encontro ningún sprite no hay nada que dibujar, por lo que sale de la funcion directamente.<br><br><br>

```c
	i = -1;
	while (++i < cub->count_sprites)
		cub->sprites[i].dist = hypot(cub->sprites[i].x - cub->graphic.player_pos_x,
		cub->sprites[i].y - cub->graphic.player_pos_y);
```
Calcula la hipotenusa de todos los sprites que contiene el plano.
Para el cálculo, le pasa por parametro la diferencia que resulta de la resta de los vectores 'x' e 'y' de la posicion donde se encuentra el sprite que estemos calculando [i] con la del jugador.<br><br><br>

```c
	while (++i < cub->count_sprites)
	{
		k = i;
		while (++k < cub->count_sprites)
		{
			if (cub->sprites[i].dist < cub->sprites[k].dist)
			{
				tmp = cub->sprites[i];
				cub->sprites[i] = cub->sprites[k];
				cub->sprites[i] = tmp;
			}
		}
	}
```
Es ahora cuando empieza la verdadera comparación. Aquí va a establecer 2 contadores para los mismos sprites, con la idea de ir comparando 1 sprite de un contador con todos los sprites de los otros contadores. Si en la comparacion de los 2 contadores (recordemos que son los mimso sprites) el sprite comprado resulta mayor, entonces se le asigna este valor con el que estaba siendo coparado y commieza de nuevo la comparacion con todos los demas.
Es un método de ordenacion por burbuja.
