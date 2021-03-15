void	increase_draw_texture(t_cub3d *cub, t_raycalc ray, int col)
{
	t_texture	*text;

	text = &cub->tex.walls[cub->rcast.side];
	// How much to increase the texture coordinate per screen pixel
	ray.step = 1.0 * text->height / cub->win.lineheight;
	// Starting texture coordinate
	ray.pos = (cub->win.drawstart - cub->map.height / 2 + cub->win.lineheight / 2) * ray.step;
	cub->rcast.y = cub->win.drawstart;
	while (cub->rcast.y < cub->win.drawend)
	{
		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		ray.y = (int)ray.pos & (text->height - 1);
		ray.pos += ray.step;
		int	color;
		color = text->addr[text->width * ray.y + ray.x];
		if(cub->rcast.side % 2)
			color = (color >> 1) & 8355711;
		my_mlx_pixel_put(cub, col, cub->rcast.y, color);
		cub->rcast.y++;
	}
}
