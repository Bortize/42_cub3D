/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 23:36:54 by borjagrd          #+#    #+#             */
/*   Updated: 2020/10/19 12:23:23 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(t_struct *flags, char *str)
{
	if (flags->flag_precision == 0)
	{
		flags->j = 0;
		{
			while (str[flags->j] != '\0')
			{
				flags->len += write(1, &str[flags->j], 1);
				flags->j++;
			}
		}
	}
}
