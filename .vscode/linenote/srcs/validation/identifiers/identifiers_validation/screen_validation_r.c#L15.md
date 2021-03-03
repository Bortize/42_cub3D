```c
if (ft_strcmp("R", cub->map.tab[0]) == 0)
```
Comprueba si la cadena [0] que ha devuelto el ft_split_plus es igual a la letra 'R'. En caso afirmativo ejecuta el código de su interior.
<br><br><br>


```c
		cub->map.flag_widht++;
		cub->map.i++;
```
Añade +1 al flag que controla la resolucion.<br>
Añade +1 al contador general de identificaores válidos.
<br><br><br>




```c
integer_validation_resolution(cub);
```
Comprueba que la resulución tiene valores validos
<br><br><br>




```c
cub->map.width = ft_atoi(cub->map.tab[1]);
cub->map.height = ft_atoi(cub->map.tab[2]);
```
Convierte los valores del ancho y el alto de tipo char a entero y se los asigna a sus correspondientes variables de la estructura.
<br><br><br>

