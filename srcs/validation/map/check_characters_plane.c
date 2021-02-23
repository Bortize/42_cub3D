/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters_plane.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:46:26 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/02/23 16:59:08 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
** Recorre cada indice del string para ir comprobando si su valor es uno de los
** permitidos por el subject (queremos detectar si el mapa contiene algun iden-
** tificaodr no permitido y comprobando si la posición del jugador es uno de
** ellos. En el caso de que algun char del string no sea valido, gestiona el
** error.
*/
void	check_values_allowed(char *str, t_cub3d *cub)
{
	cub->plan.i = 0;

	while (str[cub->plan.i] != '\0')
	{
		if ((str[cub->plan.i] == '0') || (str[cub->plan.i] == '1') || (str[cub->plan.i] == '2')
		|| (str[cub->plan.i] == 'N') || (str[cub->plan.i] == 'S') || (str[cub->plan.i] == 'E')
		|| (str[cub->plan.i] == 'W') || (str[cub->plan.i] == ' ') || (str[cub->plan.i] == '\t'))
		{
			if (str[cub->plan.i] == '2')
				cub->sprt.count_sprites++;// Guarda el numero de sprites que aparecen en el mapa
			player_start_position(str, cub);
			cub->plan.i++;
		}
		else
		{
			print_error("El plano del mapa contiene valores no permitidos.❌");
		}
	}
}
/*
** Busca si en la lina que le pasan hay por lo menos un valor válido para entrar
** a analizarla en profundidad. En caso de contener alguno, entra mas en profundidad
** y despues de comprobarlo, si todos los caracteres pasados de la string son correctos,
** se suma +1 fila. Si no es así, gestiona el error.
*/
void	check_characters_plane(char *str, t_cub3d *cub)
{
	ft_printf("congrats, estas leyendo el plano \n");
	ft_printf("Se va a proceder a analizar la línea  🗺️--> %s \n", str);
	if (ft_strchr(str, '0') || ft_strchr(str, '1') || ft_strchr(str, '2') ||
		ft_strchr(str, 'N') || ft_strchr(str, 'S') || ft_strchr(str, 'E') ||
		ft_strchr(str, 'W') || ft_strchr(str, ' ') || ft_strchr(str, '\t'))
	{
		check_values_allowed(str, cub);
		ft_printf(" La línea del plano es válida ✅\n");
		cub->plan.rows_size++;
		ft_printf("Número de líneas leídas: %i \n", cub->plan.rows_size);
	}
	else
	{
		print_error("El plano contiene valores NO VALIDOS 🧑‍🎤");
	}
}
