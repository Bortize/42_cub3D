```c
sort_sprites(cub);
```
Ordena los sprites por distancia, de mas lejanos a mas cercanos.
<br><br><br>


```c
while (++i < cub->sprt.count_sprites)
		draw_sprite(cub, init_sprite(cub, cub->sprites[i]));
```
El bucle no se detendrá mientras el iterador sea menos que el numero de sprites que contiene el plano.
Notese que a la función 'init_sprite' se le pasa como parámetro el array de sprites, pero unicamtne se le pasa 1 sprite cada vez, el que indica su índice. Por eso, el prototipo de la funcion es de 't_sprite sprite', porque solo recibe un sprite.
<br><br><br>
