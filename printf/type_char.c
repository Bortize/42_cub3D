/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 12:37:47 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/10/19 12:23:32 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_char(t_struct *flags)
{
	char c;

	flags->j = 0;
	c = (char)va_arg(flags->ap, int);
	if (flags->flag_width && flags->flag_minus == 0)
		while (flags->j < (flags->width - 1))
		{
			write(1, " ", 1);
			flags->len++;
			flags->j++;
		}
	write(1, &c, 1);
	flags->len++;
	if (flags->flag_minus)
		while (flags->j < flags->width - 1)
		{
			write(1, " ", 1);
			flags->len++;
			flags->j++;
		}
}
