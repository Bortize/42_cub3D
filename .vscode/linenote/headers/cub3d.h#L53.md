typedef	struct	valid_map
{
	int			i;
	int			rows_size;	 				Guarda el número de filas que contiene el plano del mapa
	char		*one_line_plan;			Guarda todas las líneas (ya validadas) del plano en un único string para poder trabajar mas facilmente
	size_t	row_len;						Guarda la longitud de la linea mas larga que ha leido del plano del mapa para poder hacer un cubo y poder trabajar mas facilmente
	char		**plan;							Guarda el plano del mapa en una matriz
	int			values_ok;
	int			player_position_x;	Guarda la posicion del vector donde se encuentra el jugador (el numero de la fila donde se encuentra 'N')
	int			player_position_y;	Guarda la posicion donde se encuentra el jugador 'N' dentro del vector (el índice del string donde se en cuentra)
	char		boundary_value;			Guarda el valor del muro '1'
	char		fill_value;					Guarda el valor con el que irá rellenando la función boundaryfill en caso de encontrar un pixel válido dentro del mapa.
}								t_map;
