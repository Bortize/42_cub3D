/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 16:18:28 by borjagrd          #+#    #+#             */
/*   Updated: 2020/10/19 12:21:53 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_flags(t_struct *flags)
{
	flags->i = 0;
	flags->j = 0;
	flags->len = 0;
	flags->aux = 0;
	flags->count = 0;
	flags->flag_minus = 0;
	flags->flag_zero = 0;
	flags->width = 0;
	flags->flag_width = 0;
	flags->precision = 0;
	flags->flag_precision = 0;
	flags->flag_integer_negative = 0;
}
