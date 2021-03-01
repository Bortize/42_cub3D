```c
double		zbuffer;
```

<br><br><br>


```c
t_identifiers	map;
```

<br><br><br>


```c
t_map			plan;
```

<br><br><br>


```c
t_window		graphic;
```

<br><br><br>


```c
t_controls		move;
```

<br><br><br>


```c
t_image			win;
```

<br><br><br>


```c
t_image			text[4];
```
Las texturas que se tienen que dibujar en los muros. En un array, donde la posicion [0] hace referencia al Norte, [1]Sur, [2]Este, [3]Oeste.
A la hora de crear la dimensión del array, se debe indicar el numero de componentes, pero a la hora de acceder a ellos, el valor '0' cuanta como un indice, por eso se habra notado que a la hora de crear los valores se utiliza hatra el cuatro, pero a la hora de acceder a ellos se hace hasta el '3' porque el valor '0' cuenta como un indice de posición.
<br><br><br>


```c
t_texture			sprite;
```
Se va a utilizar para pintar la textura de los sprites. Creo que podría hacerlo tambien como si fuera un array pero en este caso lo voy a hacer asi.
<br><br><br>


```c

```

<br><br><br>
