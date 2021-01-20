```c
void	my_mlx_pixel_put(t_window *graphic, int x, int y, int color)
{
	char	*dst;

	dst = graphic->addr + (y * graphic->line_length + x * (graphic->bpp / 8));
	*(unsigned int*)dst = color;
}
```

Esta función calcula siempre el desplazamiento de la meoría utilizando la longitud de linea establecida por: mlx_get_data_addr
