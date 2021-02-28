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
<br/><br/><br/>

```c
	sprite.transform_x = sprite.inv_det * (cub->graphic.player_dir_y * sprite.x - cub->graphic.player_dir_x * sprite.y);
	sprite.transform_y = sprite.inv_det * (cub->graphic.map_y * sprite.x + cub->graphic.map_x * sprite.y);
```
Calcula realmente la profundidad dentro de la pantalla
<br/><br/><br/>
