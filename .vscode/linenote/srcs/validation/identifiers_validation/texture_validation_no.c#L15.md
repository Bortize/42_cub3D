Llamo a la funcion "path_validation" que comprueba que la extension de la textura alojada en el PATH sea valida.

A continuacion compruebo que el flag "map->flag_no" este apagado, esto es que su valor sea cero. Hago esto para controlar los identificadores repetidos. Si fuera '1' significaria que ese identificador ya se ha recogido y la siguiente vez que entre aquí devolvería error de duplicacón.

Si el flag esta apagado entonces si entro dentro y lo primero que hago obviamente es levantar el flag sumandole +1

Tambien le sumo +1 a (map->i) Hago esto porque seá con este contador con el que lleve la cuenta de los identificadores que he ido recogiendo y con el que puedo controlar saber si me han pasado todos o no.

Por último, asigno el valor de la ruta a la variable de la estructura. Aquí termina el trabajo. ya esta validada y asignada a su lugar correcto.
