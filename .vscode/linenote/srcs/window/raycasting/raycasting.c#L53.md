Antes de empezar a utilizar el algoritmo de DDA (análisis diferencial digiital) tenemos que calcular la distancia que tiene que recorrer el rayo desde su posicion inicial hasta el primer lado 'x' y la direccion de los pasos stepX y stepY, esto es,la direccion en la que le jugador tiene que avanzar.

------------------------------------------------
if (cub->graphic.ray_dir_x < 0)
	{
		cub->graphic.step_x = -1;
		cub->graphic.side_dist_x = (cub->graphic.player_pos_x - cub->graphic.map_x) * cub->graphic.delta_dist_x;
	}
	else
	{
		cub->graphic.step_x = 1;
		cub->graphic.side_dist_x = (cub->graphic.map_x + 1.0 - cub->graphic.player_pos_x) * cub->graphic.delta_dist_x;
	}
------------------------------------------------
Tanto en el eje vertical como en el horizontal, el rayo avanza de 1 en 1 posicion. Cuando la dirección sea hacia la derecha o arriba seran valores positivos y cuando la dirección sea izq  o abajo seran valores negativos.

La posicion del jugador desde la que se lanza el rayo no altera el orden de las valores del plano, quiero decir, el jugador se mueve entorno al plano y no al revés por lo que los valores no se ven alterados.
Como la direccion del rayo es menor que cero, el rayo avanza de un lado x o y al siguiente lado x o y al igual que lo haría si lo hiciera de forma positiva pero avanzando en negativo.

Al vector de posicion del jugador se le resta el cuadrado actual en el que se encuentra el rayo para obtener el segmento que hemos avanzado. Al resultado selo multiplicamos por la distancia que el rayo tiene que recorrer de un lado x al siguiente lado x para obtener el TOTAL del avance desde la posicion inicial o como dice LODE, la distacia real euclidiana. Como se encuentra en un avance con valores negativos, por eso le resta la poscion de la baldosa a donde se detuvo el rayo, si fuera en valores positivos podrias observar como se le resta primero donde choco el rayo a vector donde se encuentra el jugador.






	if (cub->graphic.ray_dir_y < 0)
	{
		cub->graphic.step_y = -1;
		cub->graphic.side_dist_y = (cub->graphic.player_pos_y - cub->graphic.map_y) * cub->graphic.delta_dist_y;
	}
	else
	{
		cub->graphic.step_y = 1;
		cub->graphic.side_dist_y = (cub->graphic.map_y + 1.0 - cub->graphic.player_pos_y) * cub->graphic.delta_dist_y;
	}
}
