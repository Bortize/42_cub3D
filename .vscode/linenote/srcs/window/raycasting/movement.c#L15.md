Recibe por parámetro los valores de la nueva posicion x e y a la que tienen que avanzar, pero ahun no ha dado el paso. Es justo en esta funcion donde lo hace.

Primero toma el eje 'x' y comprueba si hacia donde tiene que avanzar es igual a '0' que seria que es una zona transitable. En caso de ser asi, le asigna a player_pos_x la nueva posicion a la que ha avanzado.

Después toma el eje 'y' y comprueba lo mismo, si al lugar donde va a avanzar es '0' entonces es que puede avanzar sin problemas y le asigna el nuevo valor a player_pos_y
