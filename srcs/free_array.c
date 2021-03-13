/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:54:47 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/13 14:58:40 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** This function fully frees an allocated bidimensional array
*/

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != '\0')
	{
		free(array[i]);
		i++;
	}
	free(array);
}
