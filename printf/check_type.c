/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 08:53:06 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/10/19 11:36:01 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_type(const char *format, t_struct *flags)
{
	if (format[flags->i] == 'd' || format[flags->i] == 'i')
		type_integer(flags);
	if (format[flags->i] == 's')
		type_string(flags);
	if (format[flags->i] == 'c')
		type_char(flags);
	if (format[flags->i] == 'u')
		type_unsigned_int(flags);
	if (format[flags->i] == 'x')
		type_hexade_low(flags);
	if (format[flags->i] == 'X')
		type_hexade_upper(flags);
	if (format[flags->i] == 'p')
		type_pointer(flags);
	if (format[flags->i] == '%')
		type_percent(flags);
}
