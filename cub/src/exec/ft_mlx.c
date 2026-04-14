/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leogarci <leogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:16:53 by leogarci          #+#    #+#             */
/*   Updated: 2025/10/06 15:02:38 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <X11/Xlib.h>
#include <X11/keysym.h>

static void	destroy_win_test_textures(t_mlx *mlx, t_img *textures)
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

static void	destroy_win_test_images(t_mlx *mlx, t_img *img, t_img *ssaa_img)
{
	if (img->img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, img->img_ptr);
	if (ssaa_img->img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, ssaa_img->img_ptr);
}

void	destroy_additional_image(t_mlx *mlx, t_img *test)
{
	if (test->img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, test->img_ptr);
}

void	destroy_win_test(t_mlx *mlx, t_img *textures, t_img *img,
		t_img *ssaa_img)
{
	destroy_win_test_textures(mlx, textures);
	destroy_win_test_images(mlx, img, ssaa_img);
	destroy_mlx_display(mlx);
}

t_boolean	init_win(t_map *cub)
{
	mlx_hook(cub->mlx[0].win_ptr, DestroyNotify, 0, destroy_handler,
		&cub->mlx[0]);
	mlx_hook(cub->mlx[0].win_ptr, KeyPress, KeyPressMask, key_handler, cub);
	mlx_loop_hook(cub->mlx[0].mlx_ptr, render_scene, cub);
	mlx_loop(cub->mlx[0].mlx_ptr);
	destroy_additional_image(&cub->mlx[0], &cub->final_b);
	destroy_win_test(&cub->mlx[0], cub->nsew, &cub->final_a, &cub->ssaa_img);
	return (TRUE);
}
