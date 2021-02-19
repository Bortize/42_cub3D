
```c
void	initialize_mlx(t_cub3d *cub)
{
	cub->graphic.player_pos_x = cub->plan.player_init_position_y;
	cub->graphic.player_pos_y = cub->plan.player_init_position_x;
	if (!(cub->graphic.mlx = mlx_init()))
		print_error("Fallo al iniciar MLX");
	load_textures(cub);
	cub->graphic.mlx_win = mlx_new_window(cub->graphic.mlx, cub->map.width, cub->map.height, "cub3D");
	cub->graphic.img = mlx_new_image(cub->graphic.mlx, cub->map.width, cub->map.height);
	cub->graphic.addr = mlx_get_data_addr(cub->graphic.img, &cub->graphic.bpp, &cub->graphic.line_length, &cub->graphic.endian);
	mlx_do_key_autorepeatoff(cub->graphic.mlx);// cancela el auto repeat al presioanr una tecla para que no tenga que estar gastando recurso ineficientemente.
	mlx_hook(cub->graphic.mlx_win, KEYPRESS, 0, key_press, cub);
	mlx_hook(cub->graphic.mlx_win, KEYRELEASE, 0, key_release, cub);
	mlx_loop_hook(cub->graphic.mlx, game, cub);
	//mlx_destroy_image(cub->graphic.mlx, cub->graphic.img);
	raycasting(cub);// Pongo el raycasting aqui tambien ya que cuando no presiono tecla no rendererizo nada. Es para evitar la pantalla en negro del principio.
	mlx_loop(cub->graphic.mlx);// Inicia la randeriazacion de la ventana
}
```

///////////////////////////////////////////////////

Lo primero que hago es asignar la posicion inicial donde se encontro al jugador a la hora de parsear el mapa. Lo hago aquí, fuera de la funcion 'game' ya que si lo hiciera dentro, debido al loop, devolvería constantemente al jugador a la posición inicial y no lo dejaria moverse por el plano.

Ahora llamo a la funcion 'mlx_init' la cual devuelve un puntero que establece la conexión con el motor gráfico. Lo guardare en mi variable "cub->graphic.mlx". Si la conexion falla por cualquier razon no podré iniciar el juego por lo que gestiono el error con un if en caso de que sucediera.

Lo siguiente que hago utilizar las texturas que fueron recogidas en el parseo, para poder tratarlas con las funciones que convierten las texturas en imagenes en el juego. Lo que hago es utilizar la función 'mlx_xpm_file_to_image' para convertir un archivo de extensión .xpm en una nueva instancia de la imagen. Lo segundo utilizar la función 'mlx_get_data_addr' para poder dibujar cada pixel de la ventana en el color que le corresponde.


***mlx** --> Guarda el identificador que establece la conexion con el motor grafico de la minilibX.

***mlx_win** --> Guarda el Puntero a la ventana donde se pintararn los pixles

///////////////////////////////////////////////////////////////


| `mlx_init();`
| - |
Funcion para "iniciar la conexion al servidor gráfico". Es lo primero que debe hacerse para poder utilizar las funciones de la librería minilibX. No necesita ningun parametro y devuelve un puntero de tipo void que contiene nuestra instancia de la mlx para posteriores llamadas a las rutinas de la biblioteca.

`graphic->mlx` --> Guarda el identificador que establece la conexión al servidor gráfico de la mlx
</br><br>


| `mlx_new_window(mlx_ptr, 500, 500, "Cub3D");`
| - |
Sirve para lanzar una ventana y poder dibujar dentro de ella. Recibe como primer parametor el identificador de la conexion con el motor grafico, tambien un valor para el ancho y alto de la ventana que se creara asi como el título de la ventana que aparecerá en la parte superior. Devuelve un puntero a la ventana que acabamos de crear.

`mlx_ptr` -->

`500` -->

`500` -->

`"Cub3D"` -->
<br><br><br>

| `mlx_new_image(mlx, cub->map.width, cub->map.height);` |
| - |
Crea una nueva imagen compatible con `MLX`. Es la forma recomendada de almacenar en memoria intermedia la imagen que se está renderizando para ser mostrada. Aceptará un puntero a tu instancia `mlx` y requiere un ancho y un alto. Devolverá un puntero de referencia a la imagen.

`mlx` -->

`cub->map.width` -->

`cub->map.height` -->
</br><br><br>


| `mlx_get_data_addr(graphic.img, &graphic.bpp, &graphic.line_length, &graphic.endian);`
| - |
| Obtiene la dirección de memoria de la imagen dada. La memoria de las imágenes es extraña. Establece el tamaño de la línea en el puntero dado. Para obtener o establecer el valor del píxel `(5, 100)` en un tamaño de imagen de `(500, 500)`, tendríamos que localizar la posición de la siguiente manera:

`graphic.img` -->

`&graphic.bpp` -->

`&graphic.line_length` -->

`&graphic.endian` -->
</br></br></br>

|`mlx_do_key_autorepeatoff(cub->graphic.mlx);`
| - |
cancela el auto repeat al presionar una tecla para que no tenga que estar gastando recurso ineficientemente. Es fundamental en nuestro caso ya que tenemos nuestro juego programado para que solo haga loop si escucha algun evento de teclado, si se queda quieto entonces no hace nada y no necesitamso autorepeat.</br></br></br>


| `mlx_pixel_put(&graphic.img, 5, 5, 0x00FF0000);` |
| - |
Pone un píxel en la pantalla. No se recomienda utilizar esta función. Bloqueará la salida de la ventana, forzando un refresco y un recálculo. Por lo tanto, se sugiere renderizar una imagen y empujarla usando la función `mlx_put_image_to_window`. Puede encontrar más información sobre esto en el capítulo de Introducción.

`&graphic.img` -->

`5` -->

`5` -->

`0x00FF0000` -->
</br></br></br>


| `mlx_put_image_to_window(mlx, mlx_win, graphic.img, 0, 0);` |
| - |
Coloca una imagen en la ventana de la ubicación `(x,y)`. Esta es la forma recomendada de escribir grandes cantidades de datos gráficos de una sola vez. Tenga en cuenta que al cambiar la memoria de las ubicaciones, se mostrará directamente en la ventana.

`mlx` -->

`mlx_win` -->

`&graphic.img` -->
</br></br></br>

| `mlx_key_hook(graphic.mlx, key_hook, &graphic);` |
| - |
El propósito de esta función es que cada vez que alguién presione una tecla del teclado, ejecute la fución que le hemos pasado en el segundo parámetro antes de imprimir lo que tenga en el bufer en la ventana. La función que le pasas en el segundo parámetro es una función tuya, que has creado tu.

`graphic.mlx` -->

`key_hook` --> Funcion que crearemos nosotros mismos con la idea de que se ejecute cuadno escuche un evento.

`&graphic` -->
</br></br></br>

| `mlx_loop(mlx);` |
| - |
Inicia la renderización de la ventana. Maneja los eventos del teclado y ratón

Inicia un bucle infinito. A cada vuelta del buble se muestra un fotograma, que imaginamos que debe estar guardado en algun bufer de memoria que reserva mlx_new_window. Lo que esta en este bufer lo vuelca a la ventana a cada vuelta del buble. Tu objetivo es llenar este bufer con lo que tú quieras en cada momento. En un primer momento este loop principal empieza vacío (no hace mas que imprimir el bufer en tu ventana una y otra vez) Pero dentro de ese loop podemos meter nuestras propias funciones y hacer que se ejecuten si se cumplen unas condiciones determinadas en la entrada de datos. Eso seran los Hooks
mlx --> Es el identificador al servidor gráfico de la `mlx`
