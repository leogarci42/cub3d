/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:57:35 by salsoysa          #+#    #+#             */
/*   Updated: 2025/10/06 14:59:36 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <X11/Xlib.h>
#include <X11/keysym.h>

int	destroy_handler(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx_ptr);
	return (0);
}

void	key_handler_bis(int keycode, t_map *cub)
{
	handle_movement_left_right(keycode, cub);
	if (keycode == XK_Escape)
		destroy_handler(&cub->mlx[0]);
}

int	key_handler(int keycode, t_map *cub)
{
	handle_movement_forward_back(keycode, cub);
	key_handler_bis(keycode, cub);
	if (keycode == XK_Left)
		cub->user->angle -= 0.1;
	if (keycode == XK_Right)
		cub->user->angle += 0.1;
	return (0);
}

int	key_press_handler(int keycode, t_map *cub)
{
	if (keycode >= 0 && keycode < 256)
		cub->user->key_states[keycode] = 1;
	return (0);
}

int	key_release_handler(int keycode, t_map *cub)
{
	if (keycode >= 0 && keycode < 256)
		cub->user->key_states[keycode] = 0;
	return (0);
}
