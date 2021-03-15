Lo primero que hace es comprobar si la posicicion [0] del string que ha devuelto 'ft_split_plus' corresponde al identificador del cielo. En caso de que asi sea, entra al codigo.

Aquí estamos condicionados por lo que ha devuelto el anterior split_plus, porque en función de la cantidad de string que haya devuelto, que recordemos dependia de la cantidad de espacios y tabulaciones encontrara, deberemos de tratarlo de una manera o de otra.

Por ejemplo, imagina que se nos ha devuelto un array de 4 strings donde ahora deberemos de separar y eliminar las comas para guardar los valores de los colores en sus respectivas variables de la estructura.
Para poder eliminar las comas, se debe empalmar todas los strings que ha devuelto el ft_split_plus. Realizaremos este cometido con la función ft_strjoin, que se encarga de unir los strings devueltos.

Hay que tener presente que a cuantas mas cadenas haya devuelto el split_plus, mas veces tendremos que unir las cadenas con strjoin.

Una vez que se ha unido todas las cadenas devueltas, ahora se procede a iliminar todas las comas que aparecen para obtener los valores limpios.
