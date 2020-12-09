/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:18:13 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/10/19 12:22:40 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision_flag(const char *format, t_struct *flags)
{
	flags->aux = 0;
	flags->precision = 0;
	flags->flag_precision = 0;
	if (format[flags->i] == '.')
	{
		flags->flag_zero = 0;
		flags->flag_precision = 1;
		flags->i++;
		flags->aux = flags->count;
		if (format[flags->i] == '*')
		{
			if ((flags->aux = va_arg(flags->ap, int)) >= 0)
				flags->precision = flags->aux;
			flags->i++;
		}
		else
		{
			while (ft_isdigit(format[flags->i]))
			{
				flags->precision = flags->precision * 10 +
					format[flags->i] - 48;
				flags->i++;
			}
		}
	}
}
