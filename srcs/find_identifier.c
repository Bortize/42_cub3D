/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_identifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortize <bortize@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:02:55 by bortize           #+#    #+#             */
/*   Updated: 2020/12/11 23:15:13 by bortize          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int find_identifier(char *str, map_config *map)
{
    int i;
    char identifier;
    static int count_identifier;

    i = 0;
    count_identifier = 0;
    while (str[i])
    {
        if (ft_strchr("RSCF", str[i]))
            identifier = str[i];
            check_identifier(identifier, map);
            count_identifier++;
        if (ft_strchr("NOSOEAWE", str[i]))
            identifier = str[i];
            check_identifier(identifier, map);
            count_identifier++;
        i++;
    }
    if (count_identifier == 8)
        ft_printf("El mapa es Valido para su lectura");
    return (0);
}