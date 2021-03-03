Esta funcion gestiona de forma abstracta todo el código.

```c
t_cub3d	cub;
int fd;
```
Para poder realizar correctamente el cub3D, necesitare utilizar varibles que almacenen su valor a lo largo del tiempo de ejecución del programa. A su vez, este valor debe de ser mantenido a lo largo del tiempo o modificado si fuera preciso. La mejor forma de gestinar esta necesidad es utilizando estructuras donde podremos almacenar dichas variables sin que su valor se vea alterado o eliminado al salir de una funcion. Por este motivo crearemos una estructura principal que nos servira incluso para alojar otras estructuras y por consiguiente, conseguir un alcance total en el programa.<br>
Declaramos la variable que recibira el descriptor del fichero para que el procesador pueda abrir procesasr nuestras consultas en el fichero.
<br><br><br />

```c
if (argc == 3)
		ft_printf("Tienes que guardar la caputra de la pantalla");
```
Comprueba si el numero de argumentos es igual a 3. En tal caso procede a hacer la captura de pantalla.
<br><br><br />

```c
init_structures(&cub);
```
Inicia los valores de las variables que va a utilziar a cero
<br><br><br />

```c
	else if (argc == 2 && file_validation(argv[1]) == 1)
	{
		ft_printf("Mapa introducido --> %s \n\n", argv[1]);
		fd = open(argv[1], O_RDONLY);
		file_reading(fd, &cub);
	}
```
Si lor argumentos que recibe son los correctos, osea 2, ya que el nombre del programam cuenta como un valor mas el ficheros del mapa y ademas el fichero tiene la extension valida (esto es que termine por .cub) entonces se ejecuta lo que hay dentro del if

Una vez entra dentro, llama a la funcion open para que me genere un "file descriptor" y de esta manera poder leer el fichero de texto con la funcion "file_readign" para encontrar y validar los identificadores que contiene el fichero.
<br><br><br />

```c
else if (argc < 2)
		print_error("Eres un estupido, no vales ni para meter un fichero");
```
Si el número de argumentos que se le pasando por linea de comandos es menor de 2, gestiona el error
<br><br><br />

```c
initialize_mlx(&cub);
```
Inicializa la mlx con todos los calculos del lanzamiento de rayos para calcular distancias y poder pintar el cielo, suelo, muros, sprites con sus respectivas texturas.

```c
system("leaks -fullContent cub3D");
```
Por último, añado una función para que me muestre la gestión de los leaks.
