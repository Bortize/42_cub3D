/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:00:59 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/10/19 12:23:47 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_percent(t_struct *flags)
{
	flags->count = 0;
	if (flags->flag_minus == 0 && flags->flag_zero == 0 &&
	flags->flag_width == 1)
	{
		flags->j = 0;
		while (flags->j < (flags->width - flags->count - 1))
		{
			write(1, " ", 1);
			flags->len++;
			flags->j++;
		}
	}
	if (flags->flag_zero)
		flag_zero_percent(flags);
	if (flags->flag_precision)
		flag_precision_integer(flags);
	ft_putchar('%');
	flags->len++;
	flags->count++;
	if (flags->flag_minus)
		flag_minus_percent(flags);
}
