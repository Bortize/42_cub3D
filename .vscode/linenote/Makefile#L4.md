$(NAME):	$(INCLUDE) $(OBJS)

make -C $(INCLUDE) --> estoy compilando el include que es el printf

cp ./printf/libftprintf.a ./ --> me estoy trayendo la libreria generada en el printf a este directorio

mv libftprintf.a $(LIBCUB3D) --> le estoy cambiando de nombre  a libcub3d.a

@$(CC) $(CFLAGS) -L. libftprintf.a --> voy a compilar el main con la nueva libreria

@$(CC) $(CFLAGS) -L. libcub3d.a $(OBJS) --> genero el fichero a.out con la libreria y todos los .o