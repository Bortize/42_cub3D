/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:46:26 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/26 12:31:07 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/cub3d.h"

void	check_values_allowed(char *str, map_plan *plan)
{
	plan->i = 0;

	while (str[plan->i] != '\0')
	{
		if ((str[plan->i] == '0') || (str[plan->i] == '1') || (str[plan->i] == '2')
		|| (str[plan->i] == 'N') || (str[plan->i] == 'S') || (str[plan->i] == 'E')
		|| (str[plan->i] == 'W') || (str[plan->i] == ' ') || (str[plan->i] == '\t'))
		{
			plan->i++;
		}
		else
		{
			print_error("El plano del mapa contiene valores no permitidos.❌");
		}
	}
}

void	check_characters(char *str, map_plan *plan)
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
