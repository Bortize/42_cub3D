void	vertical_stripe_sprite_screen(t_cub3d *cub, t_drawsprites drwspr)
{
			while (drwspr.stripe < cub->spr.drawendx)
		{
			drwspr.texx = (int)(256 * (drwspr.stripe - (-cub->spr.spritewidth / 2 + cub->spr.spritescreenx)) * cub->tex.sprite[0].width / cub->spr.spritewidth) / 256;
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) ZBuffer, with perpendicular distance
			if (cub->spr.transformy > 0 && drwspr.stripe > 0 && drwspr.stripe < cub->map.width && cub->spr.transformy < cub->zbuffer[drwspr.stripe])
			{
				drwspr.y = cub->spr.drawstarty;
				while (drwspr.y < cub->spr.drawendy)
				{
					// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
					drwspr.d = drwspr.y * 256 - cub->map.height * 128 + cub->spr.spriteheight * 128;//256 and 128 factors to avoid floats
					drwspr.texy = ((drwspr.d * cub->tex.sprite[0].height) / cub->spr.spriteheight) / 256;
					drwspr.color = cub->tex.sprite[0].addr[cub->tex.sprite[0].width * drwspr.texy + drwspr.texx];
					if((drwspr.color & 0x00FFFFFF) != 0)
						my_mlx_pixel_put(cub, drwspr.stripe, drwspr.y, drwspr.color);
					drwspr.y++;
				}
			}
			drwspr.stripe++;
		}
}
