```c
if (moving(cub) || rotating(cub))
{
	refresh_screen(cub);
	movement(cub);
	rotation(cub);
	raycast_init(cub);
}
```
Aqui se comprueba si algunos de los flags de movimiento fueron activados para, en el caso de que sea verdad, entre a refrescar la pantalla, hacer los nuevos calculos del movimiento y la rotacion, y finalmente hacer los nuevos calculos para el lanzamiento de rayos.
<br>

```c
sleep(0);
return (1);
```
El `sleep(0)` fue colocado a modo de prueba para hacer test, y se quedo ahi. Este sleep no debe ponerse, ya que es una funcion prohibida y no debe ir en el codigo.
