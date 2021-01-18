void	initialize_mlx(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Cub3D");
	mlx_loop(mlx_ptr);
}

mlx_init() --> Funcion para "iniciar la conexion con el sistema gráfico correcto y la ventana". Es lo primero que debe hacerse para poder utilizar las funciones de la librería minilibX. No necesita ningun parametro y devuelve un puntero de tipo void que contiene nuestra instancia de la mlx para posteriores llamadas a las rutinas de la bibliteca.

mlx_new_window(mlx_ptr, 500, 500, "Cub3D") --> Sirve para lanzar una ventana y poder dibujar dentro de ella. Recibe como primer parametor el identificador de la conexion con el motor grafico, tambien un valor para el ancho y alto de la ventana que se creara asi como el título de la ventana que aparecerá en la parte superior.
Devuelve un puntero a la ventana que acabamos de crear.

mlx_loop(mlx_ptr) --> Inicia la renderización de la ventana. Maneja los eventos del teclado y ratón
