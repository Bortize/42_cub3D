```c
void	init_raycast(t_cub3d *cub, int col)
{
	cub->rcast.camerax = 2 * col / (double)cub->map.width - 1;
	cub->rcast.raydirx = cub->p.dirx + cub->p.planex * cub->rcast.camerax;
	cub->rcast.raydiry = cub->p.diry + cub->p.planey * cub->rcast.camerax;
	//which box of the map we're in
	cub->rcast.mapx = (int)(cub->p.posx);
	cub->rcast.mapy = (int)(cub->p.posy);
	//length of ray from one x or y-side to next x or y-side
	cub->rcast.deltadistx = fabs(1 / cub->rcast.raydirx);
	cub->rcast.deltadisty = fabs(1 / cub->rcast.raydiry);
}
```
