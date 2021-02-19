Esta función comprueba en 'if_moving' o 'if_rotating' si alguna variable del movimiento o la rotacion ha sido alterada con algun evento del teclado. En el caso de cumplir la condición, ejecuta las funciones de su interior.

////////////////////////////////

rotation -> Contiene el algoritmo que maneja la rotación del jugador

movement -> Contiene el algorítmo que maneja el movimiento del jugador

raycasting -> Contiene todos los calculos para el lanzamiento y colision de rayos para calcular la altura de los muros.


sleep(0) -> Deja el proceso libre mientras no se active ningun evento. Es útil para liberar carga de trabajo a la CPU
