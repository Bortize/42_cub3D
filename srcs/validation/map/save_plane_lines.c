/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_plane_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:58:05 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/23 20:50:45 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
** Crea una nueva instancia de la estructura y guarda los valroes de la
** posicion en donde se encontro el sprite en el mapa
*/
void	find_sprites(t_cub3d *cub)
{
	int x;// coordenada x del plano
	int y;// coordeanda y del plano
	int i;// iterador del string
	int s;// contador de sprites encontrados

	i = 0;
	x = 0;
	s = 0;
	while ((cub->plan.one_line_plan[i]) != '\0')
	{
		if (cub->plan.one_line_plan[i] == 'p')
		{
			x++;// suma +1 al numero de fila en el que se encuentra
			y = 0;// restablece el contador de y a 0 ya que esta en una nueva fila
		}
		if (cub->plan.one_line_plan[i] == '2')
		{
			t_sprites sprite[s];// Creo una nueva isntancia de de la estructrua por cada sprite encontrado

			sprite[s].x = x + 0.5;// asigno el vector x que he encontrado
			sprite[s].y = y + 0.5;// asigno el vector y que he encontrado
			s++;// avanzo una posicion el contador
		}
		i++;// avanzo en el iterador que recorre el strign
		y++;// avanzo en el iterador que recorre la la linea del mapa.
	}
}

/*
** Concatena todas las lineas que ha ido encontrando el GNL en un solo string
** poniendo un caracter random 'p' entre línea y línea para luego poder sepa-
** rarlas (el caracter p me sirve como identidicador de separdor entre cadenas
** ) y asignar cada linea a su respectivo puntero.
*/
int	save_plane_lines(char *str, t_cub3d *cub)
{
	cub->sprt.pos_sprite = (int *)malloc(sizeof(cub->sprt.count_sprites));// reserva memoria para la matriz de los sprites
	cub->plan.one_line_plan = ft_strjoin(cub->plan.one_line_plan, str);
	cub->plan.one_line_plan = ft_strjoin(cub->plan.one_line_plan, "p");
	find_sprites(cub);
	ft_printf("Concatenation Linea %s \n", cub->plan.one_line_plan);
	return (0);
}
