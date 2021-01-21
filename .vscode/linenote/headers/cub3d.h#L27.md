typedef struct	config
{
	int			i;
	int			width;				Ancho de la resolucion de la ventana
	int			flag_widht;			flag si encuentra el ancho de la resolucion
	int			height;				Alto de la resolucion de la ventana
	int			flag_height;		flag si encuentra el alto de la resolucion
	char		*no;				Guarda las texturas no
	int			flag_no;			flag
	char		*so;				Guarda las textura so
	int			flag_so;
	char		*ea;
	int			flag_ea;
	char		*we;
	int			flag_we;
	char		*s;
	int			flag_s;
	int			floor[3];			Guarda los colores del suelo
	int			flag_floor;			Flag para reconocer si encontro los colores del suelo en el fichero.cub
	int			ceilling[3];		Guarda los colores del cielo
	int			flag_ceilling;		Flag para reconocer si encontro los colores del cielo en el fichero.cub
	char		**tab;				Lo uso para trabajar con los identificadores la primera vez que lee la liena
	char		**tabcf;			Lo uso para trabajar los identificadores y poder guardar los valroes para finalmente asigarlos a sus respectivas variables de la estructura
	int			flag_map_ready; 	flag activador de que ya se leyeron y asignaron los identificadores a la esctructura
}								map_config;
