/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:35:00 by salsoysa          #+#    #+#             */
/*   Updated: 2025/10/01 16:35:00 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	dst = img->data_addr + (y * img->size_line + x * (img->bpp_div_8));
	*(unsigned int *)dst = color;
}

void	draw_wall_column(t_wall_draw_params *params)
{
	int		texture_y;
	int		color;
	char	*pixel;

	while (params->y < params->end)
	{
		texture_y = (int)params->tex_pos;
		if (texture_y < 0)
			texture_y = 0;
		if (texture_y >= params->texture->height)
			texture_y = params->texture->height - 1;
		pixel = params->texture->data_addr + ((int)texture_y
				* params->texture->size_line + (int)params->texture_x
				* (params->texture->bpp_div_8));
		color = *(unsigned int *)pixel;
		put_pixel_to_image(params->img, params->i, params->y, color);
		params->y++;
		params->tex_pos += params->step;
	}
}

void	fill_floor_ceiling_line(t_img *img, int y, int floor_color,
		int ceiling_color)
{
	char	*dst;
	int		x;

	x = 0;
	while (x < img->width)
	{
		dst = img->data_addr + (y * img->size_line + x * (img->bpp_div_8));
		if (y < img->height / 2)
			*(unsigned int *)dst = ceiling_color;
		else
			*(unsigned int *)dst = floor_color;
		x++;
	}
}

void	fill_floor_ceiling(t_img *img, int floor_color, int ceiling_color)
{
	int	y;

	y = 0;
	while (y < img->height)
	{
		fill_floor_ceiling_line(img, y, floor_color, ceiling_color);
		y++;
	}
}
