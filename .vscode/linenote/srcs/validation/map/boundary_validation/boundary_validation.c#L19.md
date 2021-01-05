boundary_fill(int x, int y, int fill_value, int boundary_value)

x --> numero de vector (fila de la matriz) donde se encuentra el jugador

y --> posicion en el string donde se encuentra el jugador

fill_balue --> valor con el que se va a rellenar si hay suelo 'f'

boundary_value --> valor que tiene los limites del plano '1'

/////////////////////////////////////////////////////////////////

Aquí vamos a comprobar el valor del punto donde se encuentra el algoritmo en el mapa. Si no es igual a 1 (valor del muro) a f (valor de relleno, lo que supone que ya paso por ahi y lo cambio) y 2 (valor de los sprites) entonces va a sustituir el valor de donde se encuentra por 'f' con la funcion put_pixel();

Del mismo modo, va a llamar a la funcion para los 4 posiciones vecinas de manera recursiva, asi hasta el punto en el que no pueda pintar mas, entonces irá retrocediendo hasta el punto en el que llego.
