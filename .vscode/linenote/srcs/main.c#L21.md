Esta funcion gestiona de forma abstracta todo el código.

Para poder trabajar a los largo de todo el cub3d necesito crear nuevas estructuras de las que dispongo en el .h, y esto se hace lo primero de todo.

A continuacion comprueba los argumentos que son pasados por linea de comandos para que, en el caso de que no sean los correctos, devolver error en el programa.

Si lor argumentos que recibe son los correctos, osea 2, ya que el nombre del programam cuenta como un valor mas el ficheros del mapa y ademas el fichero tiene la extension valida (esto es que termine por .cub) entonces se ejecuta lo que hay dentro del if

Una vez entra dentro, llama a la funcion open para que me genere un "file descriptor" y de esta manera poder leer el fichero de texto con la funcion "file_readign" para encontrar y validar los identificadores que contiene el fichero.

Si no ha podido abrir el fichero, gestiona el error.

Por último, añado una función para que me muestre la gestión de los leaks.
