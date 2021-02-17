cub->no_text.img_text = mlx_xpm_file_to_image(cub->graphic.mlx, cub->map.no, &cub->no_text.width_text, &cub->no_text.height_text);

cub->graphic.mlx			->		Puntero a la mxl
cub->map.no					->		Variable donde se encuentra alojado el PATH de la textura
&cub->no_text.width_text	->		El ancho de la textura que hay que reprentar
&cub->no_text.height_text	->		El alto de la textura que hay que representar


cub->so_text.addr = (int *)mlx_get_data_addr(cub->so_text.img_text, &cub->so_text.bpp, &cub->so_text.size_line, &cub->so_text.endian);

cub->no_text.img_text		->		La instancia de la imagen que fue creada en la función anterior
&cub->no_text.bpp			->		Un puntero en donde se escribe los bites por pixel (bpp)
&cub->no_text.size_line		->		Un puntero en donde se escribe la línea
&cub->no_text.endian		->		Un puntero en donde se escribe el endian.
