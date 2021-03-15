```c
void	assigning_plane_values(t_cub3d *cub)
{
	cub->plan.plan = (char **)calloc(cub->plan.rows_size, sizeof(char *));
	cub->plan.values_ok = 1;// activa el flag para que luego sepa que ya paso por aqui y no vuelva a entrar
	cub->plan.plan = ft_split(cub->plan.one_line_plan, 'p');
	cub->plan.plan_tmp = ft_split(cub->plan.one_line_plan, 'p');
	if (!(boundary_fill(cub->plan.player_init_position_x, cub->plan.player_init_position_y, cub)));
		print_error("Map not valid \n");
	find_sprites(cub);
	free(cub->plan.one_line_plan);
	free(cub->plan.plan_tmp);
	cub->plan.one_line_plan = NULL;
}
```





Reserva memoria para la matriz que va a contener las lineas del plano una vez validadas.

Para reservar memoría, multiplica el tamaño de las filas leidas por (char *) que es lo que vale un vector. Por lo tanto, ahora cub->plan.plan contiene el valor de un array de vectores vacios.

cub->plan.plan = [ [],[],[],[],[],[],[],[],[] ];


Los datos para calcular su tamaño (sizeof) son obtenidos de la función (validate_plan)donde se calcula la longitud de la linea que mas caracteres tiene para reservar un cuadrado de vectores (matriz)

Mientras que el iterador no haya llegado al final de los vectores, seguirá recorriendolos.
