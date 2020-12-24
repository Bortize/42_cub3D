carga por parametro el file descriptor y las estructuras para poder utilizarlas dentro de la funcion.

Creo una variable de tipo puntero llamada "line" donde voy guardando cada linea que voy leyendo del ficheor con mi funcion GNL (solo guarda una linea cada vez, no las va a acumulando ya que luego se libera con free)

Creo un bucle con la condicion de que mientras queden lineas por leer, se ejecute lo que hay dentro.

Si la linea leida no es una linea vacía entonces no entra en el codigo y pasa en el bucle a la siguiente linea, porque las lineas vacioas no nos interesa contabilizarlas.

Dentro llama a 2 funciones las cuales entrara en el buscador de intentificadores (find_identifier) siempre y cuando map->i que es un contador de los identificadores que ha ido encontrando y validando, sea menor de 8, que son los que tiene que haber.

Si ha completado de encontrar y validar todos los identificadores, entonces entra en la siguiente funcion que lo que hace es validar el plano del mapa.

En caso de que no haya encontrado 8 identificadores devuelve error.
