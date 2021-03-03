La función path_validation va a validar si la extension de los path donde se encuentran las textuaras es una extension valida, y esto es una extension que termina en .cub

Para ello, lo que hago es recorer desde el final el path y compararlo con un string que he creado con el mismo nombre de la extension que se pide. Para entender mejor este proceso, voy a explicarlo con mas detenimiento.


```c
	char *extension;
	int str_len;
	int extension_len;
	int i;
```
Creo un puntero de tipo array llamado 'extension' al cual le asignare el nombre de ".cub" que empleare para compar.
Declaramos 2 variables para guardar la longitud tanto del string que voy a crear como de la linea que contiene el path.
Por último, un iterador para ir recorriendo los 2 string.
<br><br><br>


```c
extension = ".xpm";
```
Como comentabamos anteriormente, asignamos a extension el valor con el que queremos compar la extion del path.
<br><br><br>


```c
str_len = ft_strlen(str);
extension_len = ft_strlen(extension);
```
Calculamos la longitud de la cadena del path como la de extension. Necesitamos su valor para poder ir recorriendolo desde el final ya que empezaremos desde el final.
<br><br><br>


```c
i = 1;// comienza por 1 para obviar el caractr null
while(i < 5)
```
Comenzamos el iterador que recorre las cadenas en 1, ya que no nos interesa comparar el valor del final que es el valor nulo con el que terminan todas las cadenas, queremos empezar comparand la 'b'.
Decimos que mientras el iterador sea menor de 5 porque comenzando desde el final, es la longitud de las letras que hay que comparar. Aunque realmente son 4 los valores a comparar, recuerda que nuesto iterador ha comenzado en la posicon 1, por lo que si a 1 le sumas 4, nos da 5. Hasta aquí facil verdad?
<br><br><br>


```c
if (str[str_len - i] == extension[extension_len - i])
```
El primer valor nos va a situar en el indice de str pero en el final y restandole - i lo que hacemos es restarle 1. Por lo que el iterador del primer valor esta situado exactamente en la última letra de la extension. Lo compara con el valor donde se encuentra el iterador de extension, que en este caso en 'b'. Si los 2 valores coinciden avanza una posicion de atras al comienzo.
En caso de que los valores del iterador no coincidan, gestiona el error y finaliza el programa.
<br><br><br>


```c
return (1);
```

<br><br><br>
