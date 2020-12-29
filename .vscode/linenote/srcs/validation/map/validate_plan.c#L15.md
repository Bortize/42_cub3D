Comprueba que los valores de la linea que recibe por parámetro sean válidos para representar el plano.

Si la linea leida es mayor que la que tiene guardada, entonces le asigna el valor de la nueva a la variable donde la guarda, que es una variable de la estructura 'plan'. En caso contraio, se queda con la que estaba. Esto lo hago con el proposito de calcular cuál es la línea que tiene la mayor longitud para luego reservar memoria con (sizeof) porque voy a trabajar haciendo una matriz de un cuadrado como en el ejemplo que pongo  a continuación.


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
