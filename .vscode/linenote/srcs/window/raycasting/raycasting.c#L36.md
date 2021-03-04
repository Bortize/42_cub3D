Esta funcion realiza todos los calculos iniciales necesarios para calcular el lanzamiento de rayos.

cub->graphic.camera_x = 2 * x / (double)cub->map.width - 1;|
|-|


`Lo primero que hace es calcular camera_x, que es la coordenadad x en el plano de la cámara que representa la actual coordenda x de la pantalla. Recordemos que 'x' es el pixel en el que se encuentra el rayo y habra tantos pixels como ancho tenga la ventana porque recordenos que el raycast dibuja en franjas verticales de pixels, no pixel a pixel como lo hace el raytracing`
<br><br><br>

cub->graphic.ray_dir_x = cub->graphic.player_dir_x + cub->graphic.player_plane_x * cub->graphic.camera_x;|
|-|

`Multiplica el plano de la camara del jugador por la actual coordenada 'x' en la pantalla, a esto le suma la direccion en la que avanza 'x' y le asigna el valor a ray_dir_x `
<br><br><br>

cub->graphic.map_x = (int)(cub->graphic.player_pos_x);|
|-|

`balsoda en la que se encuentra el jugador`
<br><br><br>

cub->graphic.delta_dist_x = fabs(1 / cub->graphic.ray_dir_x);|
|-|

`Distancia desde el punto de origen del jugador hasta el primero lado x
<br><br><br>


if (cub->graphic.ray_dir_x < 0.)
	{
		cub->graphic.step_x = -1;
		cub->graphic.side_dist_x = (cub->graphic.player_pos_x - cub->graphic.map_x) * cub->graphic.delta_dist_x;
	}`|
else
	{
		cub->graphic.step_x = 1;
		cub->graphic.side_dist_x = (cub->graphic.map_x + 1.0 - cub->graphic.player_pos_x) * cub->graphic.delta_dist_x;
	}|
|-|

E1l rayo no deja de ser un vector, y para calcular si el rayo colisiona con un muro, tenemos que ir comprobandolo de poco en poco. Antes de nada, tenemos que comprobar hacia que lado se esta lanzando el rayo, por lo que si es menor que cero sabemos que la direccion en la que tiene que avanzar es negativa. si es así, se le resta a la posicion del jugador el valor de la baldosa en la que se encuentra y se multiplica por la distancia que el rayo tiene que recorrer desde un lado x al siguiente lado x.

En cambio, si el rayo avanza de forma positiva se le suma +1 a la baldosa en la que se encuentra el jugador. La explicación de esto es porque cuando calcula la baldosa en la que se encuentra nos da el valor del lado lado la valdosa, porque al ser numero entero no puede posicionar al jugador en el centro
		 __ __
	  ->|__|__|
		|__|__|

En la representacion de arriba, te muestro que cuadno debuelve la baldosa en la que se encuenttra, devuelve el valor de la posicon donde se encuentra el comienzo de la baldosa y por ello que se le suma +1, para poder restarle a continuacion el valor de la poscion del jugador dentro de la balsosa y al resultado lo multiplico por la distancia desde el punto de origen del jugador hasta

<br><br><br>


`if (cub->graphic.ray_dir_y < 0)
	{
		cub->graphic.step_y = -1;
		cub->graphic.side_dist_y = (cub->graphic.player_pos_y - cub->graphic.map_y) * cub->graphic.delta_dist_y;
	}
	else
	{
		cub->graphic.step_y = 1;
		cub->graphic.side_dist_y = (cub->graphic.map_y + 1.0 - cub->graphic.player_pos_y) * cub->graphic.delta_dist_y;
	}`|
|-|


``|
|-|
