Guarda todos los valores del plano en un mismo string.

Concatena cada línea leída del plano para guardarla en un string. El propósito es poder trabajar facilmente con el plano del mapa para asignarselo a la matriz

El primer ft_strjoin se trae las linea del plano y la concatena con la anterior. La primera vez no se concatenera con nada porque no hay una linea anterior.

El segundo ft_strjoin concatena un caracter random que he escogido "p" para utilizarlo mas adelante como divisor del string en la funcion ft_split para poder guardar cada linea en una matriz. Observese que el caracter esta entre comillas dobles aun siendo un unico caracter. Esto es porque
sino la funcion ft_strjoin no concatenaria la p porque solo concatena string con string, no char con string

///////////////////////////////////////////////////////////////////////////////////
int	save_plane_lines(char *str, t_cub3d *cub)
{
	char *aux;

	aux  = 0;
	cub->plan.one_line_plan = ft_strjoin(aux, str);
	cub->plan.one_line_plan = ft_strjoin(aux, "p");
	free(aux);
	aux = NULL;
	ft_printf("Concatenation %s \n", cub->plan.one_line_plan);
	return (0);
}
