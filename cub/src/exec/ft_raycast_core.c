/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leogarci <leogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:40:00 by salsoysa          #+#    #+#             */
/*   Updated: 2025/10/06 18:40:04 by leogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray_params(t_raycast_params *params, t_map *cub, int i)
{
	params->ray_dir_x = cosf(cub->user->angle - FOV_DIV_2 + (i * FOV_));
	params->ray_dir_y = sinf(cub->user->angle - FOV_DIV_2 + (i * FOV_));
	params->map_x = (int)cub->user->x;
	params->map_y = (int)cub->user->y;
	params->delta_dist_x = fabsf(1 / params->ray_dir_x);
	params->delta_dist_y = fabsf(1 / params->ray_dir_y);
}

void	calculate_step_and_side_dist(t_raycast_params *params, t_map *cub)
{
	if (params->ray_dir_x < 0)
	{
		params->step_x = -1;
		params->side_dist_x = (cub->user->x - params->map_x)
			* params->delta_dist_x;
	}
	else
	{
		params->step_x = 1;
		params->side_dist_x = (params->map_x + 1.0 - cub->user->x)
			* params->delta_dist_x;
	}
	if (params->ray_dir_y < 0)
	{
		params->step_y = -1;
		params->side_dist_y = (cub->user->y - params->map_y)
			* params->delta_dist_y;
	}
	else
	{
		params->step_y = 1;
		params->side_dist_y = (params->map_y + 1.0 - cub->user->y)
			* params->delta_dist_y;
	}
}

void	perform_dda(t_raycast_params *params, t_map *cub)
{
	params->hit = 0;
	params->side = 0;
	while (!params->hit)
	{
		if (params->side_dist_x < params->side_dist_y)
		{
			params->side_dist_x += params->delta_dist_x;
			params->map_x += params->step_x;
			params->side = 0;
		}
		else
		{
			params->side_dist_y += params->delta_dist_y;
			params->map_y += params->step_y;
			params->side = 1;
		}
		if (cub->map[params->map_y][params->map_x] == '1')
			params->hit = 1;
	}
}

void	calculate_wall_distance(t_raycast_params *params, t_map *cub)
{
	if (params->side == 0)
		params->perp_wall_dist = (params->map_x - cub->user->x + (1
					- params->step_x) / 2) / params->ray_dir_x;
	else
		params->perp_wall_dist = (params->map_y - cub->user->y + (1
					- params->step_y) / 2) / params->ray_dir_y;
}
