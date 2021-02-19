Esta funcion lo que hace es ir avanzando a pasos el lado derecho de 'x' asi como el lado drecho de 'y'

Lo primero que hace es comprobar si el rayo golpeo algun muro. Para ello, utiliza la variable 'hit' la cual comprueba si es igual a cero, para en ese caso, entrar dentro del while e ir avanzadno por las baldosas del plano.

Cuando la distancia que tiene que recorrer el rayo desde su posicion inicial 'x' hasta el primer lado de 'x' es menor que la que tendria que recorrer si fuera al primer lado de 'y', entonces:

		Se le suma a side_dist_x, la distancia que tiene que recorrer el rayo de un lado 'x' al siguiente lado 'x'. Al final, lo que pretende aqui es que side_dist_x mida toda la longitud del rayo entiendo.

		Tambien, a la baldosa en la que se encuentra el rayo se le suma la direccion en la que tiene que avanzar el jugador. Digamos que aqui va sumando al anterior, los segmenteos en concretoq ue tiene que avanzar mientras que en side_dist_x obtenemos la longitud total desde el punto de partida del jugador.

		Por último, a side se le asigna un 0. Este valor es un flag que sirve como identificador para saber enque lado de la baldosa se quedo el rayo.

Por el contrario, si cuando la distancia que tiene que recorrer el rayo desde su posicion inicial 'y' hasta el primer lado 'y' es mayor que que la de 'x' entonces:

		Se le suma a side_dist_y, la distancia que tiene que recorrer el rayo de un lado 'y' al siguiente lado 'y'

		Tambien, a la baldosa en la que se encuentra el rayo se le suma la direccion en la que tiene que avanzar el jugador.

		Por último, a side se le asigna un 1. Este valor es un flag que sirve como identificador para saber en que lado de la baldosa se quedo el rayo.

Para finalizar, comprueba si la posicion en la que se encuentra dentro de la baldosa, es distinto de cero 0. Entonces, claramente nos encotramos con un muro y se activa el flag "hit" que nos servira mas adelante.
