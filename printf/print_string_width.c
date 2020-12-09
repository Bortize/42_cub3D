/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 21:56:40 by borjagrd          #+#    #+#             */
/*   Updated: 2020/10/19 12:23:17 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string_width(t_struct *flags)
{
	int total;

	flags->j = 0;
	if (flags->flag_precision && flags->count > flags->precision)
		total = flags->width - flags->precision;
	else
		total = flags->width - flags->count;
	if (flags->width < total)
		flags->j = 0;
	else
		while (flags->j < total)
		{
			write(1, " ", 1);
			flags->len++;
			flags->j++;
		}
	if (flags->count == 0)
	{
		while (flags->j < flags->width)
		{
			write(1, " ", 1);
			flags->len++;
			flags->j++;
		}
	}
}
