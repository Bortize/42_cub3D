```c
void	find_sprites(t_cub3d *cub)
{
	int x;// coordenada x del plano
	int y;// coordeanda y del plano
	int i;// iterador del string
	int s;// contador de sprites encontrados
	t_sprites sprite[cub->count_sprites];// creo tantas instancias como sprites he encontrado

	i = 0;
	x = 0;
	s = 0;
	while ((cub->plan.one_line_plan[i]) != '\0')
	{
		if (cub->plan.one_line_plan[i] == 'p')
		{
			x++;// suma +1 al numero de fila en el que se encuentra
			y = 0;// restablece el contador de y a 0 ya que esta en una nueva fila
		}
		if (cub->plan.one_line_plan[i] == '2')
		{
			sprite[s].x = x + 0.5;// asigno el vector x que he encontrado
			sprite[s].y = y + 0.5;// asigno el vector y que he encontrado
			s++;// avanzo una posicion el contador
		}
		i++;// avanzo en el iterador que recorre el strign
		y++;// avanzo en el iterador que recorre la la linea del mapa.
	}
}
```



Esta funcion loq ue hara sera leer todo el string buscnado los sprites.

Despues de haber recogido todo el plano del juego en una única string, lo que vamos a hacer en esta funcion es localizar, a lo largo de la linea, todas las veces que aparece uns sprite el cual esta referenciado con el número (2)

Cabe destacar que utilizamos la letra ´p´a modo de separador entre linea y linea, asi que nos apoyaremos en este caracter para saber en que fila nos encontramos de la matriz.

Cuando encuentre un 'p' sabra que esta en la siguiente linea por lo que le sumara una posicion al vector de 'x' que es el de las filas y restaurara el contador de 'y' a cero, el cual es el iterador de cada linea, por eso, cuando salta a un nuevo vector restaura el contador a cero.

Cuando encuentre un sprite, se lo asignara a la instancia de la estructura que corresponda al numeor del sprite. Recordemos que al comienzo de la funcion, hemos creado tanstas instancias como sprites hemos encontrado. Ahora solo tenemos que asiganar los valors de donde fueron encontrados a cada instancia 's' que sera el numero del sprite.

```c
t_sprites sprite[cub->count_sprites];
```
Como ya habiamos contabilizado el número de sprites que tiene nuestro mapa (lo hicimos en la funcion check_values_allowed con el flag cub->count_sprites), ahora necesitamos crear tantas instancias de la estructura t_sprites como sprites hemos encontrado en el plano. Para ello, creamos un sprite y le añadimos al índice el número de sprites encontrados y listo.

```c
while ((cub->plan.one_line_plan[i]) != '\0')
```
Mientras que el iterador que recorre el string no haya llegado al final, el bucle se sigue ejeucutando


```c
if (cub->plan.one_line_plan[i] == 'p')
		{
			x++;
			y = 0;
		}
```
En el momento que se encuenra una 'p' signifca que acaba de saltar a la siguiente fila en lo que sería la matriz, por ello, se suma +1 a 'x' y se reestablece el contador de 'y' a cero, ya que este es el iterador de cada fila individualmetne, y cuadno salta a la siguiente fila vuelve a empezar en la posicion 0.

```c
if (cub->plan.one_line_plan[i] == '2')
		{
			sprite[s].x = x + 0.5;
			sprite[s].y = y + 0.5;
			s++;
		}
```
Si el iterador encuentra un sprite, añade la posición de la fila y la columna al numero de instancia de la estructura en la que se encuentra.
una vez hecho esto, avanza el contador de 's' +1 posicion para avanzar a la siguiente instancia de la estructura, asi cuando encuentre otro sprite, le asignara su posicion a la nueva instancia.

```c
i++;
y++;
```
cuado termina de comprobar los 2 condicionales, avanza a la siguiente posición en el iterador de 'i' el cual recorre el string completo donde esta todo el plano y también avanza el contador de 'y' el cual recorre unicamtne cada linea separa por 'p'
