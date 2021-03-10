/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:27:48 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/10 01:38:21 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
** Check that all the numbers that make up the resolution values and the s
** ground colors are whole numbers and do not contain any letters in between
*/
int	 integer_validation(t_cub3d *cub)
{
	int i;
	int j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (ft_isdigit(cub->map.tabcf[i][j]) == 1)
				return (0);
			else
				print_error("Algunos colores contienen valores no númericos");
			j++;
		}
		i++;
	}
	return (0);
}
/*
** Check that all the numbers that compose the resolution values and the sky
** and ground colors are integers and do not contain letters in between. It
** is different from colours as it has one less vector.
*/
int	integer_validation_resolution(t_cub3d *cub)
{
	int	i;
	int	j;

	i = 1;
	while (i <= 2)
	{
		j = 0;
		while (cub->map.tab[i][j])
		{
			if (ft_isdigit(cub->map.tab[i][j]) == 0)
				print_error("Some resolution data contains non-numeric values."
					" Fix it and run the program again");
			j++;
		}
		i++;
	}
	return (0);
}
