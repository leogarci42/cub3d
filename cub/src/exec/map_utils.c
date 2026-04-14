/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leogarci <leogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:08:55 by salsoysa          #+#    #+#             */
/*   Updated: 2025/10/14 16:00:43 by leogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_final_images_a(t_map *cubd)
{
	cubd->final_a.img_ptr = mlx_new_image(cubd->mlx->mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT);
	cubd->final_a.data_addr = mlx_get_data_addr(cubd->final_a.img_ptr,
			&cubd->final_a.bpp, &cubd->final_a.size_line,
			&cubd->final_a.endian);
	cubd->final_a.bpp_div_8 = cubd->final_a.bpp / 8;
	return (0);
}

int	init_final_images_b(t_map *cubd)
{
	cubd->final_b.img_ptr = mlx_new_image(cubd->mlx->mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT);
	cubd->final_b.data_addr = mlx_get_data_addr(cubd->final_b.img_ptr,
			&cubd->final_b.bpp, &cubd->final_b.size_line,
			&cubd->final_b.endian);
	cubd->final_b.bpp_div_8 = cubd->final_b.bpp / 8;
	return (0);
}

int	load_texture_image(t_img *img, t_mlx *mlx, int index)
{
	img[index].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, img[index].pwd,
			&img[index].width, &img[index].height);
	if (!img[index].img_ptr)
		return (-1);
	return (0);
}

int	get_texture_data_addr(t_img *img, int index)
{
	img[index].data_addr = mlx_get_data_addr(img[index].img_ptr,
			&img[index].bpp, &img[index].size_line, &img[index].endian);
	if (!img[index].data_addr)
		return (-1);
	img[index].bpp_div_8 = img[index].bpp / 8;
	return (0);
}
