/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validation_ceilling.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:42:41 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/12 17:03:46 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	if_finish_two(t_cub3d *cub)
{
	if (cub->map.tab[2] == NULL)
	{
		cub->map.flag_ceilling++;
		cub->map.i++;
		cub->map.tabcf = ft_split(cub->map.tab[1], ',');
		validation_identifiers_ceilling(cub);
		return (1);
	}
	return (0);
}

static int	if_finish_three(t_cub3d *cub)
{
	char	*new;

	if (cub->map.tab[3] == NULL)
	{
		cub->map.flag_ceilling++;
		cub->map.i++;
		new = ft_strjoin(cub->map.tab[0], cub->map.tab[1]);
		cub->map.tabcf = ft_split(new, ',');
		validation_identifiers_ceilling(cub);
		free(new);
		return (1);
	}
	return (0);
}

static int	if_finish_four(t_cub3d *cub)
{
	char	*new;
	char	*new2;

	if (cub->map.tab[4] == NULL)
	{
		cub->map.flag_ceilling++;
		cub->map.i++;
		new = ft_strjoin(cub->map.tab[1], cub->map.tab[2]);
		new2 = ft_strjoin(new, cub->map.tab[3]);
		cub->map.tabcf = ft_split(new2, ',');
		free(new);
		free(new2);
		validation_identifiers_ceilling(cub);
		return (1);
	}
	return (0);
}

int			color_validation_ceilling(t_cub3d *cub)
{
	if (ft_strcmp("C", cub->map.tab[0]) == 0)
	{
		if (if_finish_two(cub))
			return (0);
		if (if_finish_three(cub))
			return (0);
		if (if_finish_four(cub))
			return (0);
	}
	return (0);
}
