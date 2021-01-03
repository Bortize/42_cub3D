void	initialize_mlx(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Cub3D");
	mlx_loop(mlx_ptr);
}

mlx_init() --> Funcion para "iniciar la conexion entre el software y la pantalla". Es lo primero que debe hacerse para poder utilizar las funciones de la librería minilibX. No necesita ningun parametro y devuelve un puntero de tipo Void para posteriores llamdas a las rutinas de la bibliteca.

mlx_new_window(mlx_ptr, 500, 500, "Cub3D") --> Sirve para dibujar dentro de la ventana.

mlx_loop(mlx_ptr) --> Maneja los eventos del taclado y ratón
