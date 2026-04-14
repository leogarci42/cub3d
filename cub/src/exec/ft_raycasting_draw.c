/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_draw.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leogarci <leogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:35:00 by salsoysa          #+#    #+#             */
/*   Updated: 2025/10/06 15:42:44 by leogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_wall_params(t_ray *ray, t_wall_calc *calc)
{
	if (ray->distance < 0.00001)
		ray->distance = 0.00001;
	calc->wall_height = (int)(SSAA_HEIGHT / ray->distance);
	calc->wall_height_div_2 = calc->wall_height / 2;
	calc->start = SSAA_HEIGHT_DIV_2 - calc->wall_height_div_2;
	calc->end = SSAA_HEIGHT_DIV_2 + calc->wall_height_div_2;
	if (calc->start < 0)
		calc->start = 0;
	if (calc->end >= SSAA_HEIGHT)
		calc->end = SSAA_HEIGHT - 1;
}

static void	calculate_texture_params(t_ray *ray, t_img *texture,
			t_wall_calc *calc)
{
	float	wall_x;

	if (ray->side == 0)
		wall_x = ray->y;
	else
		wall_x = ray->x;
	wall_x -= floorf(wall_x);
	calc->texture_x = (int)(ray->wall_x * texture->width);
	if (calc->texture_x < 0)
		calc->texture_x = 0;
	if (calc->texture_x >= texture->width)
		calc->texture_x = texture->width - 1;
	calc->step = (float)texture->height / calc->wall_height;
	calc->tex_pos = (calc->start - SSAA_HEIGHT_DIV_2
			+ calc->wall_height_div_2) * calc->step;
}

void	draw_walls_single(int i, t_ray *ray, t_map *cub, t_img *target_img)
{
	t_wall_calc			calc;
	t_wall_draw_params	params;
	t_img				*texture;

	if (i >= NUM_RAYS || !ray[i].hit)
		return ;
	calculate_wall_params(&ray[i], &calc);
	texture = &cub->nsew[ray[i].wall_dir];
	calculate_texture_params(&ray[i], texture, &calc);
	params.i = i;
	params.y = calc.start;
	params.end = calc.end;
	params.tex_pos = calc.tex_pos;
	params.step = calc.step;
	params.texture = texture;
	params.img = target_img;
	params.texture_x = calc.texture_x;
	draw_wall_column(&params);
}

void	draw_walls_rec(int i, t_ray *ray, t_map *cub, t_img *target_img)
{
	if (i >= NUM_RAYS)
		return ;
	draw_walls_single(i, ray, cub, target_img);
	draw_walls_rec(i + 1, ray, cub, target_img);
}
