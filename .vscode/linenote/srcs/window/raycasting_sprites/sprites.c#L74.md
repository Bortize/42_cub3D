```c
static void		draw_sprite(t_cub3d *cub, t_sprite spr)
```
Creo una instancia de la structura t_sprite en el mismo momento que se lo paso por parámetro. 'spr' por lo tanto, contiene todas las varibles que hacen referenia a un sprite.
<br><br><br>




```c
	x = spr.draw_start_x - 1;
	tex = cub->sprite;
```
Asigna a 'x' la posicion donde tiene que empezar a dibujar.<br>
Asigna a tex el valor de sprite. Lo va a utilizar como auxiliar creo porque tanto 'tex' como 'sprite' son del mimso tipo 't_texture.
<br><br><br>





```c
while (++x < spr.draw_end_x)
```
Mientras que el contador 'x' que recoredemos se le habia asignado al posición inicial de donde teneia que empezar a pintar, sea menor de la posicion final de donde tiene que empezar a pintar, la iteración del bucle continua.
<br><br><br>





```c
spr.texture_x = (x - (-spr.width / 2 + spr.screen_x)) * tex.width / spr.width;
```

<br><br><br>




```c
if (spr.transform_y > 0 && x > 0 && x < cub->map.width && spr.transform_y < cub->zbuffer[x])
```
Las condiciones en el if son:

spr.transform_y > 0 	-->	Esta delante del plano de la cámara para que no se vean cosas detrás.

x > 0		-->	Esta en la pantalla "izquierda"

x < cub->map.width	-->	Esta en la pantalla "derecha"

spr.transform_y < cub->zbuffer[x]		-->	ZBuffer, con distancia perpendicular
<br><br><br>





```c

```

<br><br><br>
