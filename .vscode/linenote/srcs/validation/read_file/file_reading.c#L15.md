Esta función esta declarada dentro del mismo archivo. Declarando la funcio como satic, nos ahorramos el tener que estar creando un archivo para una función específica y añadiendo su prototipo al .h y al Makefile. Simplemente se añase en el mismo archivo y listo.

Ademas, si añadimos `inline` lo que ocurre es que cuando el codigo llega a la linea dónde aparece la función, actua como si el código estuviera de seguido, por lo que se ahorra tener que hacer una llamda. No es bueno abusar de esto tampoco.<br>

Como el subject especifica que no debe aparecer el plano antes de que los identificadores, esta funcion hace precisamente eso. Comprueba que primero se hayan leído los y validado los identificadore para luego leer y validar el plano.

```c
if (cub->map.i < 8)
	find_identifiers(line, cub);
```
Mientras que los identificadores sean menores de 8, va a entrar aqui siempre, ya que no puede aparecer el mapa antes
<br>

```c
else if (cub->map.i == 8)
{
	validate_plan(line, cub);
	if (line[0] != '\0')
		save_plane_lines(line, cub);
}
```
Cuando se haya comprobado que han aparecido los 8 identificadores que especifica el plano, entoces se procede a leer el plano.
<br>
