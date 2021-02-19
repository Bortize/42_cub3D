

Multiplica la velocidad de movimiento por el valor del avance que ha sido presionado. Si se ha presionado 'W' multiplica 0.099 por ++ y si se presiona 'S' multiplica 0.099 por --

El resultado es asignado a la variable speed la cual recoge la velocidad del jugador.


Si a la posición actual del jugador le sumamos el resultado de multiplicar la direccion del jugador por la velocidad nos da las coordenadas de la posicion a la que va a avavanzar. Esto nos sirve para comprobar antes de que avance a la siguiente posicion si hay un muro o no, y asi poder evitar quedarnos atrapados dentro de una pared.

Como todo en la programacion, hay que descomponer los procedimientos uno a uno. Para entender esto mejor, imagina cuando quieres hacer que tu jugador avance de forma diagonal. Para hacer que suceda esto, debes de presionar las teclas 'W' y 'D' al mismo tiempo, pero pra poder comprobar el avance y por lo tanto la colision, debereos primero comprobar un eje y despues el otro. Es por ello que priemro coprobamos el desplazamiento de x y luego el de y

La funcion set_plan_position recibe los valros que hemos calculado (pos_x)(pos_y) para ahora asi avanzar en el caso de la baldosa donde quiera avanzar sea '0' esto es, que no sea un sprite ni un muro.
