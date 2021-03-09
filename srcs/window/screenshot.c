/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:35:42 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/09 15:18:10 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	screenshot(t_cub3d *cub)
{
	static unsigned char	bmp[54];
	int						fd;

	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0666)) < 0)
		return (0);
}



static	void		bmp_header(t_game *game, int fd, t_uchar *bmp)
{
	int				size;

	size = game->width * game->height + 54;
	bmp[0] = (t_uchar)'B';
	bmp[1] = (t_uchar)'M';
	int_char(bmp + 2, size);
	bmp[10] = (t_uchar)54;
	bmp[14] = (t_uchar)40;
	int_char(bmp + 18, game->width);
	int_char(bmp + 22, game->height);
	bmp[26] = (t_uchar)1;
	bmp[28] = (t_uchar)24;
	write(fd, bmp, 54);
}

static void			bmp_pixels(t_game *game, int fd)
{
	int		y;
	int		x;
	int		color;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			color = game->img.data[game->width * (game->height - 1 - y) + x];
			write(fd, &color, 3);
		}
	}
}
