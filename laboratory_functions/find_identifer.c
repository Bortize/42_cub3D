/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_identifer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 10:14:12 by bgomez-r          #+#    #+#             */
/*   Updated: 2020/12/12 10:14:14 by bgomez-r         ###   ########.fr       */
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

/*    if (**ft_split(&str, ' '))
    {
        if(tab[0] == 'R' || tab[0] == 'S' || tab[0] == 'C' || tab[0] == 'F')
            || tab[0] == "NO" || tab[0] == "SO" || tab[0] == "EA" || tab[0] == "WE");
    }*/

    /*if (count_identifier == 8)
        ft_printf("El mapa es Valido para su lectura");*/
    return (0);
}
