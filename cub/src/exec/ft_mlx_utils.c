/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leogarci <leogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:30:00 by salsoysa          #+#    #+#             */
/*   Updated: 2025/10/15 17:02:01 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <X11/Xlib.h>
#include <X11/keysym.h>

void	destroy_textures(t_mlx *mlx, t_img *textures)
{
	if (textures[0].img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, textures[0].img_ptr);
	if (textures[1].img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, textures[1].img_ptr);
	if (textures[2].img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, textures[2].img_ptr);
	if (textures[3].img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, textures[3].img_ptr);
}

void	destroy_images(t_mlx *mlx, t_img *img, t_img *ssaa_img)
{
	if (img->img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, img->img_ptr);
	if (ssaa_img->img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, ssaa_img->img_ptr);
}

void	destroy_mlx_display(t_mlx *mlx)
{
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
		mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
}

void	handle_movement_forward_back(int keycode, t_map *cub)
{
	float	new_x;
	float	new_y;

	if (keycode == XK_a)
	{
		new_x = cub->user->x + sinf(cub->user->angle) * 0.2;
		new_y = cub->user->y - cosf(cub->user->angle) * 0.2;
		if ((cub->map[(int)new_y][(int)new_x] != '1')
			&& (cub->map[(int)new_y][(int)cub->user->x] != '1')
			&& (cub->map[(int)cub->user->y][(int)new_x] != '1'))
			new_pos(cub, new_x, new_y);
	}
	if (keycode == XK_d)
	{
		new_x = cub->user->x - sinf(cub->user->angle) * 0.2;
		new_y = cub->user->y + cosf(cub->user->angle) * 0.2;
		if ((cub->map[(int)new_y][(int)new_x] != '1')
			&& (cub->map[(int)new_y][(int)cub->user->x] != '1')
			&& (cub->map[(int)cub->user->y][(int)new_x] != '1'))
			new_pos(cub, new_x, new_y);
	}
}

void	handle_movement_left_right(int keycode, t_map *cub)
{
	float	new_x;
	float	new_y;

	if (keycode == XK_w)
	{
		new_x = cub->user->x + cosf(cub->user->angle) * 0.2;
		new_y = cub->user->y + sinf(cub->user->angle) * 0.2;
		if ((cub->map[(int)new_y][(int)new_x] != '1')
			&& (cub->map[(int)new_y][(int)cub->user->x] != '1')
			&& (cub->map[(int)cub->user->y][(int)new_x] != '1'))
			new_pos(cub, new_x, new_y);
	}
	if (keycode == XK_s)
	{
		new_x = cub->user->x - cosf(cub->user->angle) * 0.2;
		new_y = cub->user->y - sinf(cub->user->angle) * 0.2;
		if ((cub->map[(int)new_y][(int)new_x] != '1')
			&& (cub->map[(int)new_y][(int)cub->user->x] != '1')
			&& (cub->map[(int)cub->user->y][(int)new_x] != '1'))
			new_pos(cub, new_x, new_y);
	}
}
