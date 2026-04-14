/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssaa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:30:00 by salsoysa          #+#    #+#             */
/*   Updated: 2025/10/01 16:30:00 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	accumulate_sample_at(t_img *img, int sx, int sy,
				t_color_accum *accum)
{
	char			*src;
	unsigned int	color;

	src = img->data_addr + (sy * img->size_line + sx * (img->bpp_div_8));
	color = *(unsigned int *)src;
	accum->r += (color >> 16) & 0xFF;
	accum->g += (color >> 8) & 0xFF;
	accum->b += color & 0xFF;
}

static void	accumulate_ssaa_block(t_img *img, int x, int y,
				t_color_accum *accum)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;

	dy = 0;
	while (dy < SSAA_FACTOR)
	{
		dx = 0;
		while (dx < SSAA_FACTOR)
		{
			sx = x * SSAA_FACTOR + dx;
			sy = y * SSAA_FACTOR + dy;
			accumulate_sample_at(img, sx, sy, accum);
			dx++;
		}
		dy++;
	}
}

unsigned int	compute_avg_color_for_pixel(t_img *ssaa_img, int x, int y)
{
	t_color_accum	accum;
	unsigned int	avg_color;

	accum.r = 0;
	accum.g = 0;
	accum.b = 0;
	accumulate_ssaa_block(ssaa_img, x, y, &accum);
	accum.r /= (SSAA_FACTOR_DOUBLE);
	accum.g /= (SSAA_FACTOR_DOUBLE);
	accum.b /= (SSAA_FACTOR_DOUBLE);
	avg_color = (accum.r << 16) | (accum.g << 8) | accum.b;
	return (avg_color);
}

void	write_pixel(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->data_addr + (y * img->size_line + x * (img->bpp_div_8));
	*(unsigned int *)dst = color;
}

void	downsample_to_window(t_img *ssaa_img, t_img *window_img)
{
	int				y;
	int				x;
	unsigned int	avg_color;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			avg_color = compute_avg_color_for_pixel(ssaa_img, x, y);
			write_pixel(window_img, x, y, avg_color);
			x++;
		}
		y++;
	}
}
