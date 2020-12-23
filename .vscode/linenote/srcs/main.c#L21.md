Esta funcion va a inicializar las variables de las estructuras.

A continuacion comprueba los argumentos que son pasados por linea de comandos para que, en el caso de que no sean los correctos, devolver error en el programa.

Si lor argumentos que recibe son los correctos, osea 2, ya que el nombre del programam cuenta como un valor mas el ficheros del mapa y ademas el fichero tiene la extension valida (esto es que termine por .cub) entonces se ejecuta lo que hay dentro del if

Una vez entra dentro, llama a la funcion open para que me genere un "file descriptor" y de esta manera poder leer el fichero de texto con la funcion "file_readign_identifiers" para enconbrar y validar los identificadores que contiene el fichero.
