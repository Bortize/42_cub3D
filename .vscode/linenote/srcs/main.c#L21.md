Esta funcion gestiona de forma abstracta todo el código. Es donde comienza nuestro cub3d y donde podemos hacernos una idea de todo lo que ocurre.

```c
t_cub3d	*cub;
int fd;
```
Para poder realizar correctamente el cub3D, necesitare utilizar varibles que almacenen su valor a lo largo del tiempo de ejecución del programa. A su vez, este valor debe de ser mantenido a lo largo del tiempo o modificado si fuera preciso. La mejor forma de gestinar esta necesidad es utilizando estructuras donde podremos almacenar dichas variables sin que su valor se vea alterado o eliminado al salir de una funcion. Por este motivo crearemos una estructura principal que nos servira incluso para alojar otras estructuras y por consiguiente, conseguir un alcance total en el programa.
Las estructuras se comportan del mismo modo que variables, por eso, para que no perdamos el valor almacenado en cada llamda, debemos crearla como puntero.<br><br/>

Como hemos creado una instancia nueva de nuestra estructura principal llamada *cub que es de tipo puntero, debemos reservar memoria para que funcione correctamente y que no nos sale el error de que estamos tratando de acceder a areas de memoria no asignadas cuando la llamamemos.<br><br>
También declaramos la variable que recibira el descriptor del fichero para que el procesador pueda abrir y procesar nuestras consultas en dicho fichero.
```c
	t_cub3d	*cub;
	int fd;
```

<br>
Lo siguiente que viene es comprobar si el usuario unicametne quiere hacer una captura de pantalla, que seria la parte relacionada con el 'bmp'. Sabemos que esto es asi porque el usuario cuadno llama al programa, tiene que pasarle pos linea de comandos un tercer argumetno llamado "--save" el cual, es el indicador de que desea guardar una unicamnte una captura sin abrir la ventana y por descntado jugar. Un día vago lo tenemos todos ;)<br>

```c
if (argc == 3 && (ft_strncmp(argv[2], "--save", -1) == 0))
	cub->bmp_flag = '1';
```

Con la funcion que viene a continuacion se inicializan todas las variables de las estructuras a cero, requisito indispensable para que nuestro programa no genere valores random y nos de problemas de compilador y movidas chungas cuando nos toque debugear.
<br>

```c
init_structures(cub);
```

El número de argumentos permitidos no puede ser mayor de 3, que es el caso en el que mas puede tener es cuando nos pide que hagamos la captura de pantalla (bmp). Si tuviera mas argumentos, debemos de gestionar el error.
```c
if (argc > 2)
		print_error("Error. Debe introducir un único fichero con extensión '.map' \n");
```
<br>
Ahora viene la chicha, donde se comprueba que los argumentos son 2, lo que significa que el usuario esta cargando los argumentos validos para jugar. Vale, hasta aquí bien, pero, tenemos que comprobar que el mapa que esta intentando cargar sea un mapa valido, tanto sus identificadores como el plano donde se va a mover el jugador.<br>
Aquí validamos esta parte comprobando que los argumentos sean igual a 2 y comprobando si la extension del fichero es valida (que sea .cub) que se comprueba con la funcion "file_validation". Si todo es correcto, se abrira el archivo y se procederá a su lectura.

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
