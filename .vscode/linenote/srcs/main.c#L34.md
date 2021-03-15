
La función open abre un fichero ya existente, retornando un descriptor de fichero. La función tiene este prototipo:
```c
int open (char *nombre, int modo, int permisos);
```
El parámetro nombre es la cadena conteniendo el nombre del fichero que se quiere abrir.

El parámetro modo establece la forma en que se va a trabajar con el fichero. Algunas constantes que definen los modos básicos son:


| MODO | QUE HACE
| ------------- | ------------- |
| O_RDONLY  | Abre en modo lectura  |
| O_WRONLY  | Abre en modo escritura  |
| O_RDWR  | Abre en modo lectura-escritura  |
| O_APPEND  | Abre en modo apéndice (escritura desde el final)  |
| O_CREAT  | Crea el fichero y lo abre (si existía, se lo machaca)  |
| O_EXCL  | Usado con O_CREAT. Si el fichero existe, se retorna un error  |
| O_TRUNC  | Abre el fichero y trunca su longitud a 0  |



