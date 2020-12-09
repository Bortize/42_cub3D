/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 22:58:33 by borjagrd          #+#    #+#             */
/*   Updated: 2020/10/19 11:37:15 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_precision_string(t_struct *flags, char *str)
{
	int aux;

	flags->j = 0;
	aux = flags->precision < flags->count ? flags->precision : flags->count;
	if ((flags->flag_precision == 1) && (flags->precision == 0) && (str == 0))
		flags->j = 0;
	if ((flags->flag_precision == 1) && (flags->precision == 0))
		flags->j = 0;
	else
	{
		while (flags->j < aux)
		{
			write(1, &str[flags->j], 1);
			flags->len++;
			flags->j++;
		}
	}
}
