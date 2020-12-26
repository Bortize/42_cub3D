/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:46:26 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/24 20:03:11 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_characters(char *str, map_config *map, map_config *plan)
{
	ft_printf("congrats, estas leyendo el plano \n");
	ft_printf("Linea leía --> 🗺️ %s \n", str);
	if (ft_strchr(str, '0') || ft_strchr(str, '1') || ft_strchr(str, '2') ||
		ft_strchr(str, 'N') || ft_strchr(str, 'S') || ft_strchr(str, 'E') ||
		ft_strchr(str, 'W') || ft_strchr(str, ' ') || ft_strchr(str, '\t'))
	{
		ft_printf(" Ha leido la linea del mapa \n");
		plan->plan_row_size++;
	}
	else
	{
		print_error("El plano contiene valores no validos ");
	}
	return (0);
}
