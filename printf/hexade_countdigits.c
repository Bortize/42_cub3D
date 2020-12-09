/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexade_countdigits.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 11:41:58 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/10/19 12:21:38 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hexade_countdigits(t_struct *flags, unsigned int hexade)
{
	flags->count = 0;
	while (hexade >= 16)
	{
		hexade = hexade / 16;
		flags->count++;
	}
	flags->count++;
}
