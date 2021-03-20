Aqui se refresca la ventana y se pone a negro de nuevo, eliminando cualquier imagen que haya pondido pintar anteriormente. Pero en mi caso, hago un truco para pintar el suelo y quitarmelo ya de encima.

Como esta funcion pinta toda la venta, aprovecho para pintar toda la ventana del color del suelo. Es por asi decirlo, como la primera capa de pintura. Y luego, los muros y el cielo, los pintare sobre el color. De esta maenra, al final me quedara el suelo pintado, ya que es lo unico en donde no volveré a pintar nada por encima.

```c
int x;
int y;
```
Declaramos dos variable a modo de contador para recorrer el ancho y el alto de la ventana que vamos a pintar.<br><br>

```c
while (x < cub->map.width)
{
	while (y < cub->map.height)
	{
		my_mlx_pixel_put(cub, x, y, cub->map.floor_conv);
		y++;
	}
	y = 0;
	x++;
}
```
Este bucle va a ir almacenando todos los pixels que hay que pintar en una imagen que luego mandara a la ventana. En vez de mandar pixel a pixel, lo cual seria muy costoso, manda frame a frame, por lo que el juego es mas fluido, de lo contrario, se ralentizaria muchisimo.

La manera que tiene de pintarlos es verticalmente, y no horizontalmente como se pudiera creer.
