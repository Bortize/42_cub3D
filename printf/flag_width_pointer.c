/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_width_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:20:53 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/10/19 11:38:06 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_width_pointer(t_struct *flags, int pointer)
{
	flags->j = 0;
	if ((flags->flag_minus == 0) && (flags->flag_zero == 0))
	{
		if (flags->flag_precision)
		{
			if (pointer == 0 && flags->precision == 0)
				flags->count = 0;
			flags->aux = flags->precision > flags->count ?
			flags->precision : flags->count;
			if ((flags->flag_integer_negative) &&
			(flags->precision > flags->count))
				flags->aux += 1;
			if (flags->width > flags->aux)
				print_pointer_width(flags);
		}
		else
			while (flags->j < (flags->width - flags->count - 2))
			{
				write(1, " ", 1);
				flags->len++;
				flags->j++;
			}
	}
}
