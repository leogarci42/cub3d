/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:45:15 by salsoysa          #+#    #+#             */
/*   Updated: 2025/10/06 15:00:00 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_scene(t_map *cub)
{
	t_img	*tmp;

	ft_raycasting(cub);
	downsample_to_window(&cub->ssaa_img, cub->draw_img);
	tmp = cub->display_img;
	cub->display_img = cub->draw_img;
	cub->draw_img = tmp;
	mlx_put_image_to_window(cub->mlx->mlx_ptr, cub->mlx->win_ptr,
		cub->display_img->img_ptr, 0, 0);
	mlx_do_sync(cub->mlx->mlx_ptr);
	return (0);
}

void	destroy_win(t_mlx *mlx, t_img *textures, t_img *img, t_img *ssaa_img)
{
	destroy_textures(mlx, textures);
	destroy_images(mlx, img, ssaa_img);
	destroy_mlx_display(mlx);
}
