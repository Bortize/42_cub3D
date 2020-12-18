/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:27:48 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/18 09:45:47 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/*	Call-Function --> 	assignment_identifiers_colours
**						assignment_identifiers_colours
**	Comprueba que todos los numeros que componen los valores de la resolucion
**	y de los colores del cielo y el suelo sean numeros enteros y que no conte-
**	gan letras de por medio
*/
int	 integer_validation(map_config *map)
{
	int i;
	int j;

	i = 0;
	while(i < 3)
	{
		j = 0;
		while(j < 3)
		{
			if (ft_isdigit(map->tabcf[i][j]))
				ft_printf("el numero %i es un entero \n", map->tabcf[i][j]);
			else
			{
				print_error("Algunos colores contienen valores no númericos. Arreglelo y vuelva a ejecutar el programa");
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*	Call-Function --> 	assignment_identifiers_resolution
**						assignment_identifiers_colours
**	Comprueba que todos los numeros que componen los valores de la resolucion
**	y de los colores del cielo y el suelo sean numeros enteros y que no conte-
**	gan letras de por medio. Es diferente a colours ya que tiene un vector
**	menos
*/
int	integer_validation_resolution(map_config *map)
{
	int i;
	int j;

	i = 1;
	while(i <= 2)
	{
		j = 0;
		while(map->tab[i][j])
		{
			if (ft_isdigit(map->tab[i][j]))
				ft_printf("el numero %i es un entero \n", map->tab[i][j]);
			else
			{
				print_error("Algunos datos de la resolución contienen valores"
					" no númericos. Arreglelo y vuelva a ejecutar el programa.");
			}
			j++;
		}
		i++;
	}
	return (0);
}
