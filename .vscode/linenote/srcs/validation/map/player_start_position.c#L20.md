Comprueba si el iterador de la linea es alguna de las posiciones del jugador (N,S,E,W). En el caso de que así sea, hace lo siguiente:

	Guarda en un puntero, el punto cardinal donde fue encontrado el jugador. Se utilizara en la función 'where_player_look' para calcular donde mira el jugador a la hora de iniciar el juego.

	Ajusta los valores iniciales de la direccion del jugador con la funcion 'where_player_look'

	Guarda la posición de la fila (x) y la columna (y) en las respectivas variables de la estructura (cub) para poder trabajar mas adelante.

	Se le suma 0.5 para corregir el desfase de la posicion del jugador ya que tiene que empezar en el centro de la baldosa, no puede empezar dentro de un muro. Es por ello que el tipo se castea a double, para que pueda situarse dentro de la baldosa.

	Después de recoger la posicion del jugador correctamente, se le asigna a la posición donde se encotro el valor de '0' para que vuelva a ser una zona transitable.

int	player_start_position(char *str, t_cub3d *cub)


