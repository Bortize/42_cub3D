int	boundary_fill(int x, int y, t_cub3d *cub)
{
	if ((y < 0 || y > cub->plan.rows_size) && (x < 0 ||
	x > (int)cub->plan.row_len))
		print_error("The plan contains a wall that is not closed");
	if ((cub->plan.plan_tmp[y][x] == 'f') ||
	(cub->plan.plan_tmp[y][x] == '1') ||
	(cub->plan.plan_tmp[y][x] == '2'))
	{
		ft_printf("🚫 The value cannot be changed \n");
	}
	else
	{
		put_pixel(x, y, cub);
		return (boundary_fill(x - 1, y, cub) &&
		boundary_fill(x, y + 1, cub) &&
		boundary_fill(x + 1, y, cub) &&
		boundary_fill(x, y - 1, cub));
	}
	return (1);
}
