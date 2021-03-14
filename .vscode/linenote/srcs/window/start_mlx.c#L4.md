	// TODO: Viendo que ya usas bmp_flag, tendremos que mejorar alguna parte del
	// código para que funcione segun el subject. Si usamos --save, no tendremos que ajustar la resolución
	// al máximo de la pantalla. Importante, cuando se use --save, no se debe
	// mostrar ninguna ventana, eso quiere decir que mlx_new_window no debe ser
	// llamado y, por tanto, ninguna función que dependa de cub->mlx.win
	// IMPORTANTE: Esto va a petar el programa cuando se use --save. Dos motivos esencialmente:
	// 	1. se usará mlx_hook..... para el teclado y para ver si la ventana se ha cerrado.
	// 	2. se usará mlx_image_to_window.
