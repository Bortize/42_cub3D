```c
char	*line;
int		i;
```
Se declara un nuevo puntero para almacenar cada linea que vamos a ir leyendo del fichero mapa que nos va a introducir el usuario.
Tambien se declara un contador de tipo i, que me parece que no tiene mucho sentido y que posiblemente elimine en futuras actualizacones.<br>

```c
while (get_next_line(fd, &line))
{
	parse(cub, line);
	free(line);
}
```
Para leer el fichero, se introduce la funcion GNL dentro de un bucle while. Con ello, establecemos la condicions de que mientras queden lienas por leer en el fichero que me pasa el usuario, siga dando vueltas.

por parametro, debo pasarle la dirección del puntero line que se ha creado anteriormente. Se le pasa la dirección porque es asi como debe hacerse para poder trabajar con el puntero en las funciones que contine en su interior.

En la funcion `parse` se analiza que los valores que contiene la línea leída, corresponden a los que indica el subject. Es aquí, donde se controla toda la gestión de errores de los identificadores y parte de la del plano. La otra parte, como comprobar si los muros estan cerrados, se hace con el algorítmo de comprobación por inundación o mas conocido como flood-fill.

Despues de parsear la linea leida, es importante liberarla con `free`, de lo contrario, si que podriamos leer el contido de la nueva linea que le hemos asignado, pero estariamos perdiendo la dereferenciacion a la línea anterior y nos seria imposible liberarla, porque el puntero apunta a otra direccion y por lo tanto tendriamos un leak.

```c
	parse(cub, line);
	free(line);
```
Si prestamos atencion al funcionamiento del GNL en el while, podemos ver que va a entrar dentro del while siempre y cuando el GNL tenga lineas por leer, pero...qué ocurre cuando hemos llegado a la última línea? cuando el GNL haya leido la ultima linea no se cumplira la condicion de que hayan mas lineas por leer, y por lo tanto, no se cumplira la condicion y no entrara en el while, pero espera, nos quedaba entonces una linea por parsear y por liberar. Es aquí por ello que volvemos a poner la funcion `parse` y `free`

```c
if (cub->p.flag_found_player == 0)
	print_error("Not found player in the map \n");
if (cub->p.count_found_player > 1)
	print_error("There can only be 1 player. Check your plan \n");
```
Si no se ha encontrado el identificador del jugador en el plano, o si el identificador es mayor de 1, se gestiona el error desde este punto.<br>

```c
cub->zbuffer = malloc(sizeof(double) * cub->map.width);
```
Se reserva memoria para un buffer que contendra la varible `perp-wall-dist`, que no es otra cosa que la distancia perpendicular desde el punto de impacto del rayo al plano de la cámara.
<br>

```c
if (cub->map.i < 8)
	print_error("Missing identifiers, check your map \n");
```
Si se encontrarón mas de 8 identificadores es que el plano no es correcto y gestionamos el error. Creo que este condicional podria estar antes de reserbar memoría para el buffer, asi nos ahorrariamos esa gestion.
<br>


```c
if (cub->plan.values_ok == 0)
	assigning_plane_values(cub);
```
Si el flag que dice que todos los valores del plano esta ok no se ha activado, pasa por aquí. Creo que este flag tambien se podria quitar, ya que se activa entrado en la funcion `assigning_plane_values` y no vuelve a psar por aquí.

La funcion `assigning_plane_values` valida con el algoritmo flood-fill que el mapa este cerrado y guarda la posición de los sprites cuando los encuentra.
<br>
