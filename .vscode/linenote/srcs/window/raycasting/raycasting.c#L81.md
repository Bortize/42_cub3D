```c
static	int		ray_direction(t_cub3d *cub)
{
	int direction;

	direction = 0;
	if (cub->graphic.side_dist_x > cub->graphic.side_dist_y)
	{
		direction = cub->graphic.ray_dir_y < 0 ? NORTH : SOUTH;
		return (direction);
	}
	else
	{
		direction = cub->graphic.ray_dir_y < 0 ? WEST : EAST;
		return (direction);
	}
}
```



Recordemos que el vector vertical del plano es el 'y' y el horizontal es el 'x'. Sabiendo esto, podemos averiguar que si el vector es negativo, la dirección en la que se esta lanzando el rayo es hacia el norte, pero CUIDADO, Lodev lo hace al contrario, es por eso que si es negativo, para lodev esta mirando al Norte y si es positivo esta mriando al sur.

```c
direction = 0 + (cub->graphic.ray_dir_y > 0);
```
Atención porque esto que vamos a ver a continuación puede resultar nuevo. Y es que en esta linea de aquí vamos a utilizar los resultados de las operaciones lógicas para asignar las coordenads de las estructuras.

Cómo?qué? Tranquilo, te cuento:

Cuando realizamos una operación lógica de tipo TRUE, FALSE lo que nos devuelve es 1 o 0 dependiendo de si se cumple o no (1 = TRUE)(0 = FALSE). Pues bien, lo que yo no sabia hasta la fecha y que descubrí gracias a mi compañero y ahora amigo @rnavarre es que podemos utilizar los resultados de la operacion para asiganar las coordenadas de dirección.

Teniendo en cuenta que el jugador siempre empieza en la posición cero, el eje de avanze segun hemos programado nuestro juego es el siguinte.


Sabiendo esto, Si la distancia que el rayo tiene que recorrer desde su posición inicial de x es mayor que la que tiene que recorrer desde su posicion inicial de y significa que estamos enfocando al jugador en mirando al norte o al sur.
Para ver esto con mayor faciliad, es tand sencillo como dibujar un angulo de 90grados y trazar un vector formando un angulo de 45 grados. El vector seria el rayo, y si a ese mismo vector lo desplazases un poco a la izq y trazases 2 lienas desde el eje x y el y, verias como el eje y tiene un valor superior al del eje x. Esto mismo es lo que hacemos para comprobar si esrta mirando al sur o norte.

Una vez que ya hemos averiguado que mira al Norte o al Sur, debemos averiguar a cual de estos 2 mira concretamente.

				(--)
					N (ray_dir_y)
					|
					|
			O ----- 0 ------ E (ray_dir_x)
					|
					|
					S
				(++)

Partiendo del punto cero que sería el jugador, y fijándonos en los valores de signo, si el rayo tiene un valor superior a cero es que esta mirando al Sur, ya que como podemos ver en la imagen, es el que tiene valor positivo (++), por el contrario, si su valor fuera negativo (--) nos estaria indicando que mira al Norte.

Para asignar a la variable direction el valor correcto, lo que hacemos para norte o sur es empezar con el valor 0 y apoyandonos en lo que devuelve la operacion lógica (0 si es FALSE) y (1 si es TRUE) se lo sumaos a cero.

Por defecto 0 es norte, por lo que si ray_dir_y no es mayor de cero no se cumple la condicion y devuelve FAlSE que es cero, si a cero le sumo cero es cero por lo que a direction se le asigna cero que comprende el valor de NORTE.
Por el contrario, si ray_dir_y fuera mayor de cero, la operación logica devovleria TRUE que es el equivalante a 1. Si a cero le sumamos 1 el resultado es 1 y hemos dicho que 1 era SUR por lo que direction recibiria el valor de sur. Hasta aquí todo correcto verdad?


Aplicamos el mismo concepto para calcular la direccion del rayo para el ESTE o el OESTE, pero esta vez en vez de ser 0, tomamos 2 como valor de referencia.
Por lo tanto, si la condicion es falsa sera este y si es verdadera sera oeste.


El razon de que este utilizando el mismo ray_dir_y para calcular los valores de este y oeste es porque los ejes cambian con la vista del plano de la camara.
