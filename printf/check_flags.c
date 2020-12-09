/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 09:19:07 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/10/19 11:29:05 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(const char *format, t_struct *flags)
{
	while (format[flags->i])
	{
		if (ft_strchr("%", format[flags->i]))
		{
			flags->i++;
			if (ft_strchr("*.-0123456789", format[flags->i]))
				flags_trigger(format, flags);
			if (ft_strchr("iudscpxX%", format[flags->i]))
				check_type(format, flags);
		}
		else
		{
			write(1, &format[flags->i], 1);
			flags->len++;
		}
		if (format[flags->i] != '\0')
			flags->i++;
	}
}
