$(NAME):	$(INCLUDE) $(OBJS)
				# Llama al Makefile que esta en la ruta ./printf
				make -C $(INCLUDE)
				# Llama al Makefile que esta en la ruta ./minilibx_opengl
				make -C $(INCLUDE2)
				# Compila usando los flags, las librerías y todos los archivos objeto para finalmente generar el programa
				$(CC) $(CFLAGS) $(MLXFLAG) -L${INCLUDE} -L${INCLUDE2} -lftprintf -lmlx $(OBJS) -o cub3D
