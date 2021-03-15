
# include "../printf/libft/libft.h"		//	PATH a la libreria de la libft
# include "../printf/ft_printf.h"		//	PATH a la librería de printf
# include "get_next_line.h"				//	PATH a get_next_line
# include "../minilibx_opengl/mlx.h"	//	PATH a la libreria minilibX
# include "keycode_mac.h"				//	PATH al archivo de encabezado de los KeyCodes
# include <ctype.h>						//
# include <unistd.h>					//
# include <stdio.h>						//
# include <stdlib.h>					//
# include <string.h>					//



---
//////////////////////////////////////////
---


typedef struct	config
{
	int			i;
	int			width;				//	Ancho de la resolucion de la ventana
	int			flag_widht;			//	flag si encuentra el ancho de la resolucion
	int			height;				//	Alto de la resolucion de la ventana
	int			flag_height;		//	flag si encuentra el alto de la resolucion
	char		*no;				//	Guarda las texturas norte
	int			flag_no;			//	flag
	char		*so;				//	Guarda las textura sur
	int			flag_so;			//	flag
	char		*ea;				//	Guarda las textura este
	int			flag_ea;			//	flag
	char		*we;				//	Guarda las textura oeste
	int			flag_we;			//	flag
	char		*s;					//
	int			flag_s;				//
	int			floor[3];			//	Guarda los colores del suelo
	int			flag_floor;			//	Flag para reconocer si encontro los colores del suelo en el fichero.cub
	int			ceilling[3];		//	Guarda los colores del cielo
	int			flag_ceilling;		//	Flag para reconocer si encontro los colores del cielo en el fichero.cub
	char		**tab;				//	Lo uso para trabajar con los identificadores la primera vez que lee la liena
	char		**tabcf;			//	Lo uso para trabajar los identificadores y poder guardar los valroes para finalmente asigarlos a sus respectivas variables de la estructura
	int			flag_map_ready; 	//	flag activador de que ya se leyeron y asignaron los identificadores a la esctructura
}								t_identifiers;


---
//////////////////////////////////////////
---




typedef	struct	valid_map
{
	int			i;
	int			rows_size;	 				//	Guarda el número de filas que contiene el plano del mapa
	char		*one_line_plan;				//	Guarda todas las líneas (ya validadas) del plano en un único string para poder trabajar mas facilmente
	size_t	row_len;						//	Guarda la longitud de la linea mas larga que ha leido del plano del mapa para poder hacer un cubo y poder trabajar mas facilmente
	char		**plan;						//	Guarda el plano del mapa en una matriz.
	int			values_ok;
	int			player_position_x;			//	Guarda la posicion del vector donde se encuentra el jugador (el numero de la fila donde se encuentra 'N')
	int			player_position_y;			//	Guarda la posicion donde se encuentra el jugador 'N' dentro del vector (el índice del string donde se en cuentra)
	char		boundary_value;				//	Guarda el valor del muro '1'
	char		fill_value;					//	Guarda el valor con el que irá rellenando la función boundaryfill en caso de encontrar un pixel válido dentro del mapa.
}								t_map;




---
//////////////////////////////////////////
---



typedef struct	s_window
{
	void	*mlx;						//	Puntero al identificador del motor grafico de mlx para que funcione.
	void	*mlx_win;					//	Puntero a la ventana para que se abra y poder pintar cosas detnro.
	void	*img;						//
	void	*img_ptr;					//
	char 	*addr;						//	Guarda la dirección de memoria de la ventana, en la que transformaremos los bytes debidamente para poder pintar los pixels en la ventana.
	int		line_length;				//	Longitud de la linea.
	int		endian;						//	Forma en que los números binarios de bytes múltiples son guardados en la computadora.
	int		bpp;						//	 (bits por píxel) que sera el tamaño en bites que le asignemos a cada pixel.
}								t_window;
