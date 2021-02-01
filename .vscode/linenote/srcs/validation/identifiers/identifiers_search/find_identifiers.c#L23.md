Podemos averiguar de que identificador se trata por el numero de valores que componen ese identificador. Por ejemplo, el identificador de la resolucion contendra 3 valores siendo el primero de ellos el identificador y los 2 restantes los valores numéricos que hacen referencia a la resolucion. El de las texturas contendra unicamente 1 solo identificador que es el PAHT a esa textura en concreto. Por último, el identificador del color, contendra 3 valores, siendo el primero del identificador y los 3 restatnes el valor numérico que hace referencia a ese color.

Con estos datos, despues de haber leido la linea y haberle aplicado el split debidamente (el cual nos elimina los carácteres de espacios y tabulaciones) podemos empezar a averiguar de que identificador se trata situando nuestro índice en la ultima posición. Por qué en la última? porque como hemos dicho, nuestro split ha descuartizdo la linea extraida por el GNL en tantas partes como espacios hasta econtrado entre valor y valor y nos lo ha devuelto en un array de vectores. En otras palabras, nos ha devuelto un array de strings.

Lo que hago es, de menos a mas, ir comprobando si la posiciones 2, 3 y 4 son NULL y en base a eso, ya se de que identificador se trata y aplico las funciones acordes a cada identidicador para seguir validando los datos.

------------------------------------------

La segunda parte de esta funcion se centra en los flags de valores encontrados asi como en el contador de los valores encontrados, los cuales son indispensables para averiguar si hay un identificador repetido o si hay mas identificadores de los que se muestra en el subject
