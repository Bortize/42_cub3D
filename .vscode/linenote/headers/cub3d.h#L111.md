```c
typedef struct	s_raycast
{
	int		x;// Contador del disparador de rayos
	int		y;//
	double	camerax;// coordenada-x in camera space
	double	raydirx;// Direccion del rayo
	double	raydiry;// Direccion del rayo
	int		mapx;// Cuadrado actual del mapa en el que esta el rayo
	int		mapy;// Cuadrado actual del mapa en el que esta el rayo
	double	sidedistx;// longitud del rayo desde la posición actual hasta el siguiente lado x
	double	sidedisty;// longitud del rayo desde la posición actual hasta el siguiente lado y
	double	deltadistx;// Longitud del rayo de un lado 'x' al siguiente lado 'x'
	double	deltadisty;// Longitud del rayo de un lado 'y' al siguiente lado 'y'
	double	perpwalldist;// Distancia perpendicular desde el muro al plano de la camara.
	int		stepx;// El lado hacia el que avanzara el rayo. Sera x?
	int		stepy;// El lado hacia el que avanzara el rayo. Sera y?
	int		hit;// Flag que comprueba si el muro fue golpeado por el rayo
	int		side;// Flag que compreba en que lado del muro golpeo el rayo (NS,EO)
	double	wallx;// Donde ha sido golpeado el muro exactamente
	int		texnum;
}				t_raycast;
```
