Comprueba que todos los valores devueltos en las cadenas generas en el ft_split_plus sean valrores numericos.

Para ello, recorremos **tab que es el array de strings que devuelve ft_split_plus. Para recorrerlos, nos basamos en 2 índices [i][j] donde i sera el numero de cadenas que se han devuelto y j sera el iterador por el que iremos avanzando en cada cadena.

Comenzamos con i = 1 ya que la cadnea devuelta en el [0] seria la letra que correspnde a 'R' y esta no nos intersa.

Para que quede explicado de una menra mas clara, pondré un ejemplo. Imagina que tenemos la siguiente resolucion: R 1080 720

Despues de haber tratado esta linea con la funcion ft_split_plus, nos devovlera una matriz de cadenas donde la cadena correspondiente a la posicon [0] contendra la letra del identificadro. La posicion [1] El valor numerico del ancho y la posicion [1] el valor numerico del alto.

Entonces:
```c
cub->map.tab[0][0] = 'R'

cub->map.tab[1][0] = 1
cub->map.tab[1][1] = 0
cub->map.tab[1][2] = 8
cub->map.tab[1][3] = 0

cub->map.tab[2][0] = 7
cub->map.tab[2][1] = 2
cub->map.tab[2][2] = 0
```
