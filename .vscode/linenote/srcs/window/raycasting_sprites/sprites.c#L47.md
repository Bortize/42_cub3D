```c
sprite.x = sprite.x - cub->graphic.player_pos_x;
sprite.y = sprite.y - cub->graphic.player_pos_y;
```
Traduce la posición de los sprites a la relativa de la cámara.
<br/><br/><br/>

```c
sprite.inv_det = 1.0 / (cub->graphic.map_x * cub->graphic.player_dir_y - cub->graphic.player_dir_x * cub->graphic.map_y);
```
Transforma el sprite con la matriz inversa de la cámara
```
sprite.inv_det = 1.0 / (cub->graphic.map_x * cub->graphic.player_dir_y - cub->graphic.player_dir_x * cub->graphic.map_y);

[planeX   dirX ] -1                                       [ dirY      -dirX ]
[              ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
[planeY   dirY ]                                          [ -planeY  planeX ]
```
Necesaria para una correcta multiplicacion de las matrices
<br/><br/><br/>

```c
	sprite.transform_x = sprite.inv_det * (cub->graphic.player_dir_y * sprite.x - cub->graphic.player_dir_x * sprite.y);
	sprite.transform_y = sprite.inv_det * (cub->graphic.map_y * sprite.x + cub->graphic.map_x * sprite.y);
```
Calcula realmente la profundidad dentro de la pantalla, lo que 'z' es en 3D
<br/><br/><br/>

```c
sprite.height = abs((int)(cub->map.height / (sprite.transform_y)));
```
Calcula la altura del sprite en la pantalla.
Usar 'transform_y" en lugar de la distancia real evita el ojo de pez
<br/><br/><br/>

```c
	sprite.draw_start_y = -sprite.height / 2 + cub->map.height / 2;
	if (sprite.draw_start_y < 0)
		sprite.draw_start_y = 0;
	sprite.draw_end_y = sprite.height / 2 + cub->map.height / 2;
	if (sprite.draw_end_y >= cub->map.height)
		sprite.draw_end_y = cub->map.height - 1;
```
Calcula el pixel mas alto y mas bajo para rellenar la franja atual
<br/><br/><br/>

```c
	sprite.width = abs((int)(cub->map.height / (sprite.transform_y)));
	sprite.draw_start_x = -sprite.width / 2 + sprite.screen_x;
	if (sprite.draw_start_x < 0)
		sprite.draw_start_x = 0;
	sprite.draw_end_x = sprite.width / 2 + sprite.screen_x;
	if (sprite.draw_end_x >= cub->map.width)
		sprite.draw_end_x = cub->map.width - 1;
```
Calcula el ancho el sprite
<br/><br/><br/>
