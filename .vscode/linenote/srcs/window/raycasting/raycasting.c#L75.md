Esta funcion lo que hace es ir avanzando a pasos el lado derecho de 'x' asi como el lado drecho de 'y'

Lo primero que hace es comprobar si el rayo golpeo algun muro. Para ello, utiliza la variable 'hit' la cual comprueba si es igual a cero, para en ese caso, entrar dentro del while e ir avanzadno por las baldosas del plano.

Cuando la distancia que tiene que recorrer el rayo desde su posicion inicial hasta el primer lado de 'x' es menor que la que tendria que recorrer si fuera al primer lado de 'y', entonces:

		Se le suma a side_dist_x, la distancia que tiene que recorrer el rayo de un lado 'x' al siguiente lado 'x'. Al final, lo que pretende aqui es que side_dist_x mida toda la longitud del rayo entiendo.

		Tambien, a la baldosa en la que se encuentra el rayo se le suma la direccion en la que tiene que avanzar el jugador.

		Por último, a side se le asigna un 0. Este valor es un flag que sirve como identificador para saber enque lado de la baldosa se quedo el cuadrado


Para finalizar, comprueba si la posicion en la que se encuentra dentro de la baldosa, es distinto de cero 0. Entonces, claramente nos encotramos con un muro y se activa el flag "hit" que nos servira mas adelante.
