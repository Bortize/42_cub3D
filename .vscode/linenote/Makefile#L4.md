############################	**Variables**	####################################

| CC			= gcc|
| ------------- |:-------------:| -----:|
| Asigna el tipo de compilador que va a ser usado, siendo en este caso gcc|

| CFLAGS		= -Wall -Wextra -Werror -g #-fsanitize=address -w |
| ------------- | -----:|
| Flags que va a utilizar el compilador donde: |
| -Wall -Wextra -Werror --> son los flags obligatorios en la red 42 para aplicar a la norminette|
|-g --> Necesario para poder debuggear. gcc compila nuestro codigo para que pueda ser debuggeado|
|-fsanitize=address|
| -w |

| MLXFLAG		= -lmlx -framework OpenGL -framework AppKit -lm |
| ------------- | -----:|
| Son los flags que utilizara el compilador y que conciernen a la libreria MLX|
|-lmlx|
|-framework OpenGL|
|-framework AppKit|
|-lm|

| OBJS		= $(SRCS:.c=.o) |
| ------------- | -----:|
| Transforma todos los ficheros de función en objetos|

| INCLUDE		= ./printf |
| ------------- | -----:|
| PATH a la librría de nuestro libft y printf|

| INCLUDE2	= ./minilibx_opengl |
| ------------- | -----:|
| PATH a la librería donde esta la minilibx|

| RM 			= rm -rf |
| ------------- | -----:|
| Variable que aplica los comandos para eliminar ficheros u objetos|



#########################	Rules	############################################

$(NAME):	$(INCLUDE) $(OBJS)

make -C $(INCLUDE) --> estoy compilando el include que es el printf

cp ./printf/libftprintf.a ./ --> me estoy trayendo la libreria generada en el printf a este directorio

mv libftprintf.a $(LIBCUB3D) --> le estoy cambiando de nombre  a libcub3d.a

@$(CC) $(CFLAGS) -L. libftprintf.a --> voy a compilar el main con la nueva libreria

@$(CC) $(CFLAGS) -L. libcub3d.a $(OBJS) --> genero el fichero a.out con la libreria y todos los .o

###############################################################################
