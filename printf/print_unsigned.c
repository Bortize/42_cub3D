/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:27:18 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/10/19 12:23:28 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned(t_struct *flags, unsigned int unsign)
{
	char	*format;

	flags->j = 0;
	if (flags->flag_precision && flags->precision == 0 && unsign == 0)
		flags->count = 0;
	else
	{
		format = itoa_unsigned(unsign);
		while (format[flags->j] != '\0')
		{
			flags->len += write(1, &format[flags->j], 1);
			flags->j++;
		}
		free(format);
		format = NULL;
	}
}
