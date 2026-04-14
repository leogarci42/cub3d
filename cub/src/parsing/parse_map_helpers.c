/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leogarci <leogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:50:00 by salsoysa          #+#    #+#             */
/*   Updated: 2025/10/14 16:01:00 by leogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_all_textures(t_img *img, t_mlx *mlx, t_img *text, t_img *ssaa_img)
{
	int	i;

	i = 0;
	ssaa_img->img_ptr = NULL;
	while (i < 4)
	{
		if (load_texture_image(img, mlx, i) == -1)
			return (perror("Failed to load textures"),
				destroy_win(mlx, img, text, ssaa_img), -1);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (get_texture_data_addr(img, i) == -1)
			return (perror("Failed to get data_addr"),
				destroy_win(mlx, img, text, ssaa_img), -1);
		i++;
	}
	return (0);
}

int	init_ssaa_image(t_img *ssaa_img, t_mlx *mlx, t_img *img, t_img *text)
{
	ssaa_img->img_ptr = mlx_new_image(mlx->mlx_ptr, SSAA_WIDTH, SSAA_HEIGHT);
	if (!ssaa_img->img_ptr)
		return (perror("Failed to init ssaa"),
			destroy_win(mlx, img, text, ssaa_img), -1);
	ssaa_img->data_addr = mlx_get_data_addr(ssaa_img->img_ptr,
			&ssaa_img->bpp, &ssaa_img->size_line, &ssaa_img->endian);
	if (!ssaa_img->data_addr)
		return (perror("Failed to get data_addr"),
			destroy_win(mlx, img, text, ssaa_img), -1);
	ssaa_img->width = SSAA_WIDTH;
	ssaa_img->height = SSAA_HEIGHT;
	ssaa_img->bpp_div_8 = ssaa_img->bpp / 8;
	return (0);
}

int	ft_init_img(t_img *img, t_mlx *mlx, t_img *text, t_img *ssaa_img)
{
	if (load_all_textures(img, mlx, text, ssaa_img) == -1)
		return (-1);
	if (init_ssaa_image(ssaa_img, mlx, img, text) == -1)
		return (-1);
	return (0);
}

int	ft_init_win(t_mlx *mlx, t_img *textures, t_img *img, t_img *ssaa_img)
{
	mlx->mlx_ptr = mlx_init();
	img->img_ptr = NULL;
	if (!mlx->mlx_ptr)
	{
		destroy_win(mlx, textures, img, ssaa_img);
		return (-1);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (!mlx->win_ptr)
	{
		destroy_win(mlx, textures, img, ssaa_img);
		return (-1);
	}
	return (0);
}

t_boolean	finalize_map_setup(t_stack_params *params)
{
	if (ft_init_win(&params->cubd->mlx[0], params->cubd->nsew,
			&params->cubd->final_a, &params->cubd->ssaa_img) == -1)
		return (ft_free_array(params->src_map), FALSE);
	if (ft_init_img(params->cubd->nsew, &params->cubd->mlx[0],
			&params->cubd->final_a, &params->cubd->ssaa_img) == -1)
		return (ft_free_array(params->src_map), FALSE);
	init_final_images_a(params->cubd);
	init_final_images_b(params->cubd);
	params->cubd->display_img = &params->cubd->final_a;
	params->cubd->draw_img = &params->cubd->final_b;
	ft_free_array(params->src_map);
	get_player_coordinate(params->cubd);
	return (init_win(params->cubd));
}
