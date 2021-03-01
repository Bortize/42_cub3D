Las condiciones en el if son:

spr.transform_y > 0 	-->	Esta delante del plano de la cámara para que no se vean cosas detrás.

x > 0		-->	Esta en la pantalla "izquierda"

x < cub->map.width	-->	Esta en la pantalla "derecha"

spr.transform_y < cub->zbuffer[x]		-->	ZBuffer, con distancia perpendicular
