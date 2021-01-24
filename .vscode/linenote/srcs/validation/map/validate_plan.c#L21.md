Comprueba que los valores de la linea que recibe por parámetro sean válidos para representar el plano.

Lo primero que nos encontramos nada mas entrar en la fucion es un condicional (if) el cual, el compilador solo entrar a ejecutar lo de dentro si el flag "cub->plan.values_ok" esta desactivado, osea, no es igual 1.
Este flag se activa dentro de esta función y es que esta funcion entre otras cosas, sirve para resevar memoría para la matriz que albergara el plano del mapa. Obviamente pongo este flag aquí porque una vez que entre, ya no necesitaé volver a entrar por lo que el flag cieera

Si la línea leida es mayor que la que tiene guardada, entonces le asigna el valor de la nueva a la variable donde la guarda, que es una variable de la estructura 'plan'. En caso contraio, se queda con la que estaba. Esto lo hago con el propósito de calcular cuál es la línea que tiene la mayor longitud para luego reservar memoria con (sizeof) porque voy a trabajar haciendo una matriz de un cuadrado como en el ejemplo que pongo  a continuación.


11111111111111111
10000000000000001
10200000200000201
10000000000000001
10002000200020001111111	<-- Guardo la linea mas grande y luego reservo memoria para hacer un cuadrado
10000000000000000000001		aunque haya espacios que no vaya a utilziar como son los de arriba a la de
10202020N02020200000001		izq y abajo a la dcha
10000000000000000000001
10002000200200001
10000000000000001
10200000200002001
10000000000000001
11111011111111111


En caso de que no se haya rervado memoria para la matriz
