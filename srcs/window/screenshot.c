/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgomez-r <bgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:35:42 by bgomez-r          #+#    #+#             */
/*   Updated: 2021/03/11 14:12:14 by bgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void		int_char(unsigned char *src, int nb)
{
	src[0] = (unsigned char)(nb);
	src[1] = (unsigned char)(nb >> 8);
	src[2] = (unsigned char)(nb >> 16);
	src[3] = (unsigned char)(nb >> 24);
}

static	void		bmp_header(t_cub3d *cub, int fd, unsigned char *bmp)
{
	int				size;

	size = cub->map.width * cub->map.height + 54;
	bmp[0] = (unsigned char)'B';
	bmp[1] = (unsigned char)'M';
	int_char(bmp + 2, size);
	bmp[10] = (unsigned char)54;
	bmp[14] = (unsigned char)40;
	int_char(bmp + 18, cub->map.width);
	int_char(bmp + 22, cub->map.height);
	bmp[26] = (unsigned char)1;
	bmp[28] = (unsigned char)32;
	write(fd, bmp, 54);
}

static void			bmp_pixels(t_cub3d *cub, int fd)
{
	int		y;
	int		x;
	int		*color;

	y = cub->map.height - 1;
	while (y >= 0)
	{
		x = -1;
		while (++x < cub->map.width)
		{
			color = &cub->mlx.addr[(cub->mlx.line_len * y) + x * 4];
			write(fd, color, 4);
		}
		y--;
	}
}

int					screenshot(t_cub3d *cub)
{
	static unsigned char	bmp[54];
	int						fd;

	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0666)) < 0)
		return (0);
	bmp_header(cub, fd, bmp);
	bmp_pixels(cub, fd);
	close(fd);
	return (1);
}
