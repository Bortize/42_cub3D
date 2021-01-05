/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters_plane.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:46:26 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/01/05 00:54:07 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"
/*
** Recorre cada indice del string para ir comprobando si su valor es uno de los
** permitidos por el subject y comprobando si la posicon del jugador es uno de
** ellos. En el caso de que algun char del string no sea valido, gestiona el error
*/
void	check_values_allowed(char *str, map_plan *plan)
{
	plan->i = 0;

	while (str[plan->i] != '\0')
	{
		if ((str[plan->i] == '0') || (str[plan->i] == '1') || (str[plan->i] == '2')
		|| (str[plan->i] == 'N') || (str[plan->i] == 'S') || (str[plan->i] == 'E')
		|| (str[plan->i] == 'W') || (str[plan->i] == ' ') || (str[plan->i] == '\t'))
		{
			player_start_position(str, plan);
			plan->i++;
		}
		else
		{
			print_error("El plano del mapa contiene valores no permitidos.❌");
		}
	}
}
/*
** Busca si en la lina que le pasan hay por lo menos un valor válido paraentrar
** a analizarla en profundidad En caso se contener alguno, entra mas en profundidad
** y despues de comprobarlo, si todos los caractere de la string pasado son correctos,
** se suma +1 fila. Si no es así, gestiona el error.
*/
void	check_characters_plane(char *str, map_plan *plan)
{
	ft_printf("congrats, estas leyendo el plano \n");
	ft_printf("Se va a proceder a analizar la línea  🗺️--> %s \n", str);
	if (ft_strchr(str, '0') || ft_strchr(str, '1') || ft_strchr(str, '2') ||
		ft_strchr(str, 'N') || ft_strchr(str, 'S') || ft_strchr(str, 'E') ||
		ft_strchr(str, 'W') || ft_strchr(str, ' ') || ft_strchr(str, '\t'))
	{
		check_values_allowed(str, plan);
		ft_printf(" La línea del plano es válida ✅\n");
		plan->rows_size++;
		ft_printf("Número de líneas leídas: %i \n", plan->rows_size);
	}
	else
	{
		print_error("El plano contiene valores no validos ");
	}
}
