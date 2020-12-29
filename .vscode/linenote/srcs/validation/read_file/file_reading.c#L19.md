//////////////////////////////////////////////////////////////
PROPÓSITO
//////////////////////////////////////////////////////////////

Leer el mapa dividiendolo en 2 partes que seran identificadas mediante el uso de flags.

En la primera parte buscara encontrar todos los identificadores y validarlos. Una vez encontrados, utilizaremos la condicion de que si el numero de identificadores es igual a 8 que ya no entre en esta funcion y entonces pasara a entrar en la sugnda parte que hasta entonces no lo estaba haciendo porque el flag no le dejaba.

Esta segunda parte se encargara de validar las lineas del plano para poder asignarselas a las variables de la estructura.




//////////////////////////////////////////////////////////////
EXPLICACIÓN
//////////////////////////////////////////////////////////////

Carga por parametro el file descriptor y las estructuras para poder utilizarlas dentro de la funcion

Creo una variable de tipo puntero llamada "line" donde voy guardando cada linea que voy leyendo del ficheor con mi funcion GNL (solo guarda una linea cada vez, no las va a acumulando ya que luego se libera con free)

Creo un bucle con la condicion de que mientras queden lineas por leer, se ejecute lo que hay dentro.

Si la linea leida no es una linea vacía entonces no entra en el codigo y pasa en el bucle a la siguiente linea, porque las lineas vacioas no nos interesa contabilizarlas.

Dentro llama a 2 funciones las cuales entrara en el buscador de intentificadores (find_identifier) siempre y cuando map->i que es un contador de los identificadores que ha ido encontrando y validando, sea menor de 8, que son los que tiene que haber.

Si ha completado de encontrar y validar todos los identificadores, entonces entra en la siguiente funcion que lo que hace es validar (de una manera muy abstracta la primera vez) el plano del mapa.
Pero mas adelante, cada linea necesitara una validacion mas exhaustiva.

Cuando el contador de los identificadores haya llegado a 8, entonces levantamos un flag a modo de indicador que nos servira mas adelante para utilizarlo en otras funciones.

Si ha terminado el bucle porque ya no hay mas lineas que leer por el GNL lo primero que hago es comprobar si el contador de identificadores es menor de 8, esto significaria que el mapa no es correcto por lo que tendría que gestionar el error.

A continuacion, voy a reservar memoria para una matriz, con el proposito de albergar el plano del mapa que ha leido en la funcion "validate_plan" pero unicamente si el flag "values_ok" esta apagado. este flag se activara en la propia funcion que contiene la condicion. El proposito del flag es no volver a pasar por esta funcion las siguientes veces que tenga que pasar por aqui, que aun no se si tendre que volver a pasar.

Por último, voy a asignar las lineas a la matriz.
