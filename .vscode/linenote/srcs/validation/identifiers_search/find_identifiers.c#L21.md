El proposito de esta funcion es eliminar los espacios y las tabulaciones de cada linea que ha obtenido con la finalidad de poder trartar los valores que contiene de forma independiente y asi poder validarlo y enviarlos a cada variable de la estructura donde se guardaran para su posteriro uso.

he creado una funcion llamada "ft_split_plus" que hace la misma finalidad que split, pero ademas añade que elimine del string tambien las tabulaciones. El resultado se lo asigna a map->tab y si se cumple la condicion if entra dentro a clasificar las matrices que se hayan podido generar dependiendo de los espacios que tuviera la linea. Se pueden dar diferentes casos, veremos algunos ejemplos con el color

caso 1.
-------
C 255,200,160

map->tab[0] = 'C'
map->tab[1] = 255
map->tab[2] = 200
map->tab[3] = 160

caso 2.
-------
C 255,200        ,160

map->tab[0] = 'C'
map->tab[1] = 255,200
map->tab[2] = ,160

caso 3.
-------
C 255   ,200,160

map->tab[0] = 'C'
map->tab[1] =  255
map->tab[2] = ,200,160

caso 4.
-------
C 255,   200      ,160

map->tab[0] = 'C'
map->tab[1] = 255,
map->tab[2] = 200
map->tab[3] = ,200


Dependiendo de como haya aparecido la linea con mas o menos espacios, la funcion la alojara en una matriz de mas o menos dimension. Es por ello, que me fijo en la posicion del último valor para comprobar si es NULL, de esta menera, mi funcion tiene una forma de saber como ha sido seccionada la linea para poder trabajar con ella madnandola a la funcion pertinente para tratarla.

Si map->tab[2] == NULL quiere decir que la tercerea posicion en un valor nulo, por lo que le esta diciendo a mi funcion que la linea fue partida en 2. Aqui se que todos los valores se encuentran apelotandos en el indice [1] y es donde mas trabajo tendre ya que tendre que irlos separando (excepto que se trate de los valores de las rutas de las texturas)

el caso de map->tab[4] seria el mas fácil y puedo pasar directamente a la valoracion de los numeros porque que el valor null se encuentre en el índice [4] significa que ese string se dividió correctamente cada uno en su correspondiente vector.
