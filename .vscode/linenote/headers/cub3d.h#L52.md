typedef	struct	valid_map
{
	int			i;
	int			rows_size;	 	Guarda el número de filas que contiene el plano del mapa
	char		*one_line_plan;	Guarda todas las líneas del plano en un único string para poder trabajar mas facilmente
	size_t		row_len;		Guarda la longitud de la linea mas larga que ha leido del plano del mapa para poder hacer un cubo y poder trabajar mas facilmente
	char		**plan;			Guarda el plano del mapa en una matriz
	int			values_ok;
}								map_plan;
