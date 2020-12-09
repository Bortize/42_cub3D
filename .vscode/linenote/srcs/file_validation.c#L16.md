En esta función valido el mapa para comprobar que realmente tiene exensión en formato .cub

Mi función, a la que he llamado file_validation() recibe un argumento por parametro el cual es el valor de la cadena que recibe el main como segundo parametro. Vamos, le estoy pasando el string del nombre del fichero del mapa.

	char *extension 	-->	almacena la cadena ".cub"
	int str_len 		--> almacena la longitud de argv[1]
	int extension_len 	--> almacena la longitud de extension
	int i 				--> índice para recorrer las cadenas

Para poder comprobar que el nombre del fichero termina en .cub creo otra cadena con el nombre ".cub" y la almaceno en el puntero "char *extension". Con extension lo que hare, sera comparar las 2 cadenas carácter a carácter comenzando por el final

Ahora calculo longitud de las 2 cadenas con ft_strlen() y utilizo el valor para ir recorriendo las cadenas desde el final. Hago esto porque las variables que almacenan la longitud de las cadenas son de tipo entero y no me da problemas al recorrer las cadenas y ver el valor ascii de cada caracter. Si no lo hiciera así, me daría problemas de incompatibilidad de tipo char a int

Como la longitud que hay desde el valor null del final al . son 5, establezco un bucle que mientras que el contador de i sea menor de 5 ejecute lo que tiene dentro

Lo que hace es comparar caracter a caracter las 2 cadenas. Si son iguales avanza una posi cion y compara la siguiente. En caso de que encuentre que no son iguales devuelve -1 con un mensaje de error.

Si llega al final es porque todos los caracteres son iguales por lo que devuelve 0 y un mensaje de que el mapa es correcto