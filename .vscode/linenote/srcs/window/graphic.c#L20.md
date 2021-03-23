```c
cub->p.posx = cub->plan.player_init_position_x;
cub->p.posy = cub->plan.player_init_position_y;
```
Antes de entrar a trabajar los rayos en el raycasting, es necesario guardar la posicion inicial del jugador aqui fuera, lo primero de todo. Lo pongo aquí ya que si lo hago dentro del loop donde se hacen los calculos del raycasting, cada vez que entra en cada vuelta del loop, tanto cub->p.posx como cub->p.posy toman constantemente el valor de la posición inicial y el jugadro no avanza ya que todo el tiempo esta constantemente devolviendolo a la posición incial.



tendremos que hacer el raycasting del mapa para que el programa pueda procesar, por lo menos , el primer frame antes de que sucesa el primer loop (en caso de que nos pidan una screenshoot) y es por ello que lo situamos aqui, para que por lo menos se haga una primera vez antes de entrar a validar las keys y de entrar a hacer el priemr loop.
<br>

```c
start_mlx(cub);
load_textures(cub);
mlx_do_key_autorepeatoff(cub->mlx.init);
raycast_init(cub);
```
Las funciones que vienen, son donde empieza el groso de la parte grafica de este proyecto. Mas concretametne. La primera de ellas contiene todas las funciones necesarias para conectar con el motor grafico que nos facilita 42, y es de vital importancia que la configuración de esta parte este perfecta, sino, nada funcionara. Sino nos diera esto, hacer este proyecto seria una autentica movida.

La funcion load_textures es donde podremos convertir todas las imagenes que hemos recogido en el parseo (tanto para las texturas como para los sprites) y convertirlas para poder utilizarlas.

mlx_do_key_autorepeatoff cumple la funcion de desactivar el loop en el caso de que no este ocurriendo nada en la pantalla. Mucha gente no tiene activada esta opción, pero es fundamental si no queremos estar enviando constantemente frames si realmente no son necesarios porque nada ha cambiado.

La función raycast_init contiene todo el código donde se calcula la colisión de los rayos con los muros para calcular las distancias y poder pintarlos. Hace lo mismo con los sprites.
Contiene multitud de funciones serán explicadas en profundidad en la propia funcion mas adelante.
<br><br>

```c
if (!cub->bmp_flag)
{
	mlx_hook(cub->mlx.win, KEYPRESS, KEYPRESSMASK, key_press, cub);
	mlx_hook(cub->mlx.win, KEYRELEASE, KEYRELEASEMASK, key_release, cub);
	mlx_hook(cub->mlx.win, WINDOWCLOSE, WINDOWCLOSEMASK, win_close, cub);
	mlx_loop_hook(cub->mlx.init, game, cub);
}
```

En el siguiente punto vamos a utilizar las funciones mlx_hook, que tambien nos son dadas por 42 para poder controlar todos los eventos del tecleado que son necesarios para poder avanzar por el plano. Estas funciones se quedan escuchando si presionamos (key_press) o soltamos (key_release) cualquier tecla para ejecutar la acción correspondiente.

mlx_loop_hook es la función que va a estar calculando constantemente la colision de los rayos cuando las funciones de evento de teclado se hayan activado. Cuando se presiona una tecla, por ejemplo, movimient hacia delante, se activa el keypress de movimiento hacia delante. Este keypress unicamente es un flag, no contiene mas datoas que true o false. Es en la funcion game() donde se detecta que keypress fueron calcualdas y procede a realizar los calculos de la colision de los rayos para pintar los muros en consecuandia por donde quiera que sea que este pasando neustro jugador.

 Es la responsable tambien de abrir la ventana del juego en nuestro escritorio.
Esta función es precisamente la que estoy bloqueando con 'mlx_do_key_autorepeatoff' en caso de que no este sucediendo nada nuevo en mi juego.

El condicional if que nos encontramos antes de todas estas funciones controla que unicamtne entremos si el flag `cub->bmp_flag` esta desactivado. Este flag se activa cuando el usuario introduce un tercer argumento por linea de comando a la hora de ejecutar el progarma '--save' y su funcion es la de precisamente evitar que se ejecuten estas funciones si unicamente queremos una captura de pantalla, porque adeamas no queremos que se abra la ventana ya que el subject lo especifica claramente, y es justo aqui donde sucede esto. Por este motivo, es por el que aparece antes de entrar la funcion raycast_init(cub);, porque en caso de que nos pidan una captura de pantalla, tendremos que calcular aunque sea una vez la colision para poder pintar desde la posición inicial.
<br><br>

```c
mlx_loop(cub->mlx.init);
```
Por último, tenemos esta función, la cual es la responsable de dejar nuestro programa en un bucle infinito escuchando constantemente si accionamos cualquier evento para poder transmitirlo a las funciones de tecla correspondientess.
