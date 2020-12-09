/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:29:59 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/10/19 11:40:22 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_zero_percent(t_struct *flags)
{
	flags->j = 0;
	if (!(flags->flag_minus))
	{
		if ((flags->flag_width) && (flags->width > flags->count))
		{
			while (flags->j < (flags->width - flags->count - 1))
			{
				ft_putchar('0');
				flags->len++;
				flags->j++;
			}
		}
	}
}
