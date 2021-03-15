```c
t_window *g;
```
Creo un puntero del tipo t_window que me servira para apuntar a la instancia de graphic

```c
g = &cub->graphic;
```
Al puntero 'g' le asigno la dirección de memoría de la instancia 'graphic' del tipo t_window que he creado anteriormente.

Ahora podré trabajar como si lo estuviera haciendo con la instancia graphic, pero ahorrandome el tener que poner los largos nombres de las estructuras.

```c
g->player_dir_x = 0;
g->player_dir_y = 0;
```
Como se puede ver, ahora podemos hacer referencia a la variable `player_dir_x` de una manera mas corta. En cambio, si no hubieramos hecho el truco del puntero, para acceder a la misma variable, tendriamos que hacerlo así
```c
cub->graphic.player_dir_x = 0;
```
