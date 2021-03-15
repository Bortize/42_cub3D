```c
typedef struct	s_texture
{
	void	*img_tex;// Puntero a la imagen que se genera en mlx_xpm_file_to_image
	int		*addr;// Dirección a la imagen que se genera.
	int		bpp;// Bites por pixel
	int		endian;// Manera en la que se representan los bites dependiendo del sistema
	int		size_line;
	int		width;// Alto de la textura
	int		height;// Ancho de la textura
}				t_texture;
```
