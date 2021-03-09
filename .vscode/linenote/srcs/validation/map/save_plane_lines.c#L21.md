Guarda todos los valores del plano en un mismo string.

Concatena cada línea leída del plano para guardarla en un string. El propósito es poder trabajar facilmente con el plano del mapa para asignarselo a la matriz

El primer ft_strjoin se trae las linea del plano y la concatena con la anterior. La primera vez no se concatenera con nada porque no hay una linea anterior.

El segundo ft_strjoin concatena un caracter random que he escogido "p" para utilizarlo mas adelante como divisor del string en la funcion ft_split para poder guardar cada linea en una matriz. Observese que el caracter esta entre comillas dobles aun siendo un unico caracter. Esto es porque
sino la funcion ft_strjoin no concatenaria la p porque solo concatena string con string, no char con string</br></br></br></br>

```c
cub->plan.one_line_plan = ft_strjoin(cub->plan.one_line_plan, str);
```
Se trae las linea del plano y la concatena con la anterior. La primera vez no se concatenera con nada porque no hay una linea anterior.</br></br></br></br>


```c
cub->plan.one_line_plan = ft_strjoin(cub->plan.one_line_plan, "p");
```

El segundo ft_strjoin concatena un caracter random que he escogido "p" para utilizarlo mas adelante como divisor del string en la funcion ft_split para poder guardar cada linea en una matriz. Observese que el caracter esta entre comillas dobles aun siendo un unico caracter. Esto es porque
sino la funcion ft_strjoin no concatenaria la p porque solo concatena string con string, no char con string</br></br></br></br>
