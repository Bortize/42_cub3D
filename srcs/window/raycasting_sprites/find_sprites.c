/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 20:35:24 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/02 20:35:44 by bgomez-r         ###   ########.fr       */
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
	//cub->sprites = malloc(sizeof(t_sprite) * cub->sprt.count_sprites);
	//cub->sprites[cub->sprt.count_sprites];
	cub->sprites = malloc(sizeof(t_sprite) * cub->sprt.count_sprites);
	while ((cub->plan.one_line_plan[i]) != '\0')
	{
		if (cub->plan.one_line_plan[i] == 'p')
		{
			x++;// suma +1 al numero de fila en el que se encuentra
			y = 0;// restablece el contador de y a 0 ya que esta en una nueva fila
		}
		if (cub->plan.one_line_plan[i] == '2')
		{
			cub->sprites[s].y = y + 0.5;// asigno el vector y que he encontrado
			cub->sprites[s].x = x + 0.5;// asigno el vector x que he encontrado
			printf("El sprite %i se encontro en %f %f \n", s, cub->sprites[s].x, cub->sprites[s].y);
			s++;// avanzo una posicion el contador
		}
		i++;// Avanzo en el iterador que recorre el strign
		y++;// Avanzo en el iterador que recorre la la linea del mapa.
	}
}
