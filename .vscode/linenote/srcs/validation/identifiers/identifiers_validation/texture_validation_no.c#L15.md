```c
if (cub->map.flag_no == 0)
```
Primero de todo comprueba que el flag no este activado, ya que esto supondría que el identificador ya fue leído y activado anteriormente por lo que estaría repetido.
<br><br><br>


```c
path_validation(cub->map.tab[1]);
```
Valida la extion del path de la textura.
<br><br><br>



```c
cub->map.flag_no++;
cub->map.i++;
cub->map.no = cub->map.tab[1];
```
Activa el flag para controlar que ya ha sido leido.<br>
Añade +1 al contador de flags que han sido leidos.<br>
Asigna el string de path a la variable que se encuentra en la estructura para que pueda ser usada mas adelante.
<br><br><br>


