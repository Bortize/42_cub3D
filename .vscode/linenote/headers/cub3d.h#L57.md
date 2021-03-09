```c
typedef	struct	s_map
{
	int			i;//
	int			rows_size;//				Guarda el numero de filas que contiene el plano del mapa
	char		*one_line_plan;//			Guarda todas las lineas del plano en unico string para poder trabajar mas facilmente
	size_t		row_len;//					Tamaño de las filas
	char		**plan;//					Matriz donde guardas el mapa
	char		**plan_tmp;//					Matriz donde guardas el mapa
	int			values_ok;//
	char		player_init_coor;//
	double		player_init_position_x;//	Vector de posicion del jugador x (inicial)
	double		player_init_position_y;//	Vector de posicion del jugador y (inical )
	char		*player_positon;//			Matriz de posicion del jugador (para poder meter en sus indices init x e init y) no lo uliltizo
	char		boundary_value;//			Valor que se le da a los muros y que es utilizado en el funcion de validacion por inundacion '1'
	char		fill_value;//				Valor con el que se va a sustituir la baldosa en caso de que sea 0 en el algoritmo por inundacion 'f'
	char		sprite_value;//				Valor del sprite que tendremos en cuenta al uilizar el algoritmo por inundacion '2'
}				t_map;//plan
```
<br><br>

```c
typedef	struct	valid_map
{
	int			i;
	int			rows_size;	 				Guarda el número de filas que contiene el plano del mapa
	char		*one_line_plan;			Guarda todas las líneas (ya validadas) del plano en un único string para poder trabajar mas facilmente
	size_t		row_len;						Guarda la longitud de la linea mas larga que ha leido del plano del mapa para poder hacer un cubo y poder trabajar mas facilmente
	char		**plan;							Guarda el plano del mapa en una matriz
	int			values_ok;
	int			player_position_x;	Guarda la posicion del vector donde se encuentra el jugador (el numero de la fila donde se encuentra 'N')
	int			player_position_y;	Guarda la posicion donde se encuentra el jugador 'N' dentro del vector (el índice del string donde se en cuentra)
	char		boundary_value;			Guarda el valor del muro '1'
	char		fill_value;					Guarda el valor con el que irá rellenando la función boundaryfill en caso de encontrar un pixel válido dentro del mapa.
}								t_map;
```
