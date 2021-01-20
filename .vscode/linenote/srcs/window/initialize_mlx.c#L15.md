
```c
void	initialize_mlx(map_config *map)
{
	t_window graphic;

	graphic.mlx = mlx_init();
	graphic.mlx_win = mlx_new_window(graphic.mlx, map->width, map->height, "cub3D");
	graphic.img = mlx_new_image(graphic.mlx, map->width, map->height);
	graphic.addr = mlx_get_data_addr(graphic.img, &graphic.bpp, &graphic.line_length, &graphic.endian);
	my_mlx_pixel_put(&graphic, 5, 5, 0x0000FF00);
	mlx_put_image_to_window(graphic.mlx, graphic.mlx_win, graphic.img, 0, 0);
	mlx_key_hook(graphic.mlx, key_hook, &graphic);
	mlx_loop(graphic.mlx);
}
```

///////////////////////////////////////////////////

**t_window graphic** --> Estoy creando una nueva clase de objetos de la estructura `t_window` para guardar valores que voy a necesitar a lo largo de mi programa.

***mlx** --> Guarda el identificador que establece la conexion con el motor grafico de la minilibX.

***mlx_win** --> Guarda el Puntero a la ventana donde se pintararn los pixles

///////////////////////////////////////////////////////////////


| `mlx_init();` |
| - | -|
| Funcion para "iniciar la conexion al servidor gráfico". Es lo primero que debe hacerse para poder utilizar las funciones de la librería minilibX. No necesita ningun parametro y devuelve un puntero de tipo void que contiene nuestra instancia de la mlx para posteriores llamadas a las rutinas de la bibliteca. |
`graphic->mlx` --> Guarda el identificador que establece la conexión al servidor gráfico de la mlx
</br><br>


| `mlx_new_window(mlx_ptr, 500, 500, "Cub3D");` |
| - | -|
| Sirve para lanzar una ventana y poder dibujar dentro de ella. Recibe como primer parametor el identificador de la conexion con el motor grafico, tambien un valor para el ancho y alto de la ventana que se creara asi como el título de la ventana que aparecerá en la parte superior. Devuelve un puntero a la ventana que acabamos de crear. |
`mlx_ptr` -->

`500` -->

`500` -->

`"Cub3D"` -->
<br><br><br>

| `mlx_new_image(mlx, map->width, map->height);` |
| - | -|
| Crea una nueva imagen compatible con `MLX`. Es la forma recomendada de almacenar en memoria intermedia la imagen que se está renderizando para ser mostrada. Aceptará un puntero a tu instancia `mlx` y requiere un ancho y un alto. Devolverá un puntero de referencia a la imagen. |
`mlx` -->

`map->width` -->

`map->height` -->
</br><br><br>


| `mlx_get_data_addr(graphic.img, &graphic.bpp, &graphic.line_length, &graphic.endian);` |
| - | -|
| Obtiene la dirección de memoria de la imagen dada. La memoria de las imágenes es extraña. Establece el tamaño de la línea en el puntero dado. Para obtener o establecer el valor del píxel `(5, 100)` en un tamaño de imagen de `(500, 500)`, tendríamos que localizar la posición de la siguiente manera: |
`graphic.img` -->

`&graphic.bpp` -->

`&graphic.line_length` -->

`&graphic.endian` -->
</br></br></br>


| `mlx_pixel_put(&graphic.img, 5, 5, 0x00FF0000);` |
| - | -|
| Pone un píxel en la pantalla. No se recomienda utilizar esta función. Bloqueará la salida de la ventana, forzando un refresco y un recálculo. Por lo tanto, se sugiere renderizar una imagen y empujarla usando la función `mlx_put_image_to_window`. Puede encontrar más información sobre esto en el capítulo de Introducción. |
`&graphic.img` -->

`5` -->

`5` -->

`0x00FF0000` -->
</br></br></br>


| `mlx_put_image_to_window(mlx, mlx_win, graphic.img, 0, 0);` |
| - | -|
| Coloca una imagen en la ventana de la ubicación `(x,y)`. Esta es la forma recomendada de escribir grandes cantidades de datos gráficos de una sola vez. Tenga en cuenta que al cambiar la memoria de las ubicaciones, se mostrará directamente en la ventana. |
`mlx` -->

`mlx_win` -->

`&graphic.img` -->
</br></br></br>

| `mlx_key_hook(graphic.mlx, key_hook, &graphic);` |
| - | -|
| El propósito de esta función es que cada vez que alguién presione una tecla del teclado, ejecute la fución que le hemos pasado en el segundo parámetro antes de imprimir lo que tenga en el bufer en la ventana. La función que le pasas en el segundo parámetro es una función tuya, que has creado tu.|
`graphic.mlx` -->

`key_hook` --> Funcion que crearemos nosotros mismos con la idea de que se ejecute cuadno escuche un evento.

`&graphic` -->
</br></br></br>

| `mlx_loop(mlx);` |
| - | -|
| Inicia la renderización de la ventana. Maneja los eventos del teclado y ratón |
| Inicia un bucle infinito. A cada vuelta del buble se muestra un fotograma, que imaginamos que debe estar guardado en algun bufer de memoria que reserva mlx_new_window. Lo que esta en este bufer lo vuelca a la ventana a cada vuelta del buble. Tu objetivo es llenar este bufer con lo que tú quieras en cada momento. En un primer momento este loop principal empieza vacío (no hace mas que imprimir el bufer en tu ventana una y otra vez) Pero dentro de ese loop podemos meter nuestras propias funciones y hacer que se ejecuten si se cumplen unas condiciones determinadas en la entrada de datos. Eso seran los Hooks
mlx --> Es el identificador al servidor gráfico de la `mlx`
