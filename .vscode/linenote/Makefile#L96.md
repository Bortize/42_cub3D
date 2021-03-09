-L${INCLUDE}	->	Le dice al compilador que busque es ese lugar pero tiene que ir acompañado de -lftprintf

-L${INCLUDE2}	->	Le dice al compilador que busque en ese lugar pero tiene que ir acompañado de -lmlx

-lftprintf		->	Esta relacionado con el primer include. Le dice que busque el archivo libftprintf.a que se genero. Se omite el lib y solo se pone -l para indicar que es un archivo de libreria. Tampoco hace falta poner la extion .a ya que es lo bastante inteligente para entenderlo.

-lmlx			-> Lo mismo el anterior.
