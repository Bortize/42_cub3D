El main, va a recibir por paramatro los argumentos que tendra que passarle el usuario a la hora de ejecutar nuestro programa, que seran, el archivo del mapa que deberemos cargar "./cub3D map.cub" y en caso de que lo pidan, el comando para hacer la captura de pantalla "./cub3D map.cub --save"

```c
t_cub3d	*cub;
int		fd;
```
<br>
A lo largo de nuestro programa, deberemos asignar y utilizar el valor de algunas de nuestras variables en diferentes funciones y partes. Para ello, podemos usar estructuras, que nos permiten precisamente eso. El principal problema que se presenta en el cub3D es llegado a la parte grafica, cuadno debemos de hacer ueso de la funciones de la "mlx" donde unicamente podermos pasar una estructura por parametro, y si hemos ido guardando el resultado de diferentes variables en diferentes estrtucturas, se nos presnta el problema de que no podamos usar todas las variables que quisieramos. Para resolver este problema, creamos una estructura principal que contendra todas las demas estructuras. Con ello, nos ahorramos el problema que acabmos de mencionar. Simplemente debemos crear las instancias de todas las demas estructuras que vayamos creando dentro de ella y listo.
<br>
La variable "fd" contiene el identificador del fichero que acaba de ser abierto.

```c
if (argc < 2 || argc > 3)
		print_error("You're stupid, you're not even worth to put a file \n");
if (!(cub = malloc(sizeof(t_cub3d))))
		print_error("The asignation to cub failed \n");
```
Si los argumentos que le introduce el usuario por linea de comandos son menores de 2 (esto es, que solo introdujo el nombre del programa y el mapa) o mayores de 3 (que introdujo el nombre del programa, el mapa y --save) entonces gestionamos el error.
Es importante asignar memoria para la estructura principal. Para ello, deberemos de hacer un malloc escogiendo como tamaño "sizeof" el tipo de dato de la estructura "t_cub3D". En caso de que por cualquier razon la asignacion falle, gestionamos el error.
<br>

```c
init_structures(cub);
```
La idea de esta función, es inicializar todas las variables que stan alojadas dentro de las estructuras. Es algo muy importante para que encontremos errores random, ademas de que nos evitará algunos avisos a la hora de compilar (si tenemos los flags -Wall -Wextra -Werror puestos)
<br>

```c
if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", -1))
			print_error("Invalid argument.\n");
		cub->bmp_flag = 1;
	}
```
El siguiente fragmento de codigo va a comprobar, siempre y cuando el usuario introduzca 3 parametros, osea, que haga una captura de pantalla, que realmente el tercer parametro que introdujo corresponde con la palabra "--save". Para ello, utiliza la funcion ft_strncmp() que devuelve '0' en caso de que sean igual. Si te fijas, no estamos comparandolo con nada, sino que estamos utilizando un resultado boleano para envaluar la condicion. Como dijimos, si devuelve disteindo de cero es que no son iguales, y en ese caso, no lo comparamos con dada porque decimos que si es 'TRUE' osea 1, y por lo tanto no cero, significa que no es igual el parametro que introdujo el usuario y por lo tanto hay que gestionar el error.
<br>
Se activa el flag cub->bmp_flag = 1; para poder tratar los pixels mas adelante en el guardado de la screenshoot mas adelante.
<br>

```c
	if ((argc == 2 || argc == 3) && file_validation(argv[1]) == 1)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			print_error(strerror(errno));
		file_reading(fd, cub);
	}
```
Para entrar a hacer el parseo, hay que comprobar si argc es igual a 2 o a 3 y la validación de la extension del mapa es la correcta.
Para abrir el fichero y poder leerlo, necesitamos hacer uso de la funcion open() que nos genera un "fd" con el que podremos hacer referencia a ese fichero y acceder a él. El file descriptoro no puede ser menor de 1, si esto sucediera, significaria que ha sucedido un error, y como tal, debemos  gestionarlo.
