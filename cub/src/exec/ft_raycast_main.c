/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:45:00 by salsoysa          #+#    #+#             */
/*   Updated: 2025/10/01 16:45:00 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	setup_ray_result(t_raycast_params *params, t_ray *ray, int i)
{
	ray[i].hit = params->hit;
	ray[i].distance = params->perp_wall_dist;
	ray[i].side = params->side;
	if (params->side == 0)
	{
		if (params->ray_dir_x > 0)
			ray[i].wall_dir = EAST;
		else
			ray[i].wall_dir = WEST;
	}
	else
	{
		if (params->ray_dir_y > 0)
			ray[i].wall_dir = SOUTH;
		else
			ray[i].wall_dir = NORTH;
	}
}

static void	calculate_wall_x_coordinate(t_raycast_params *params, t_ray *ray,
			t_map *cub, int i)
{
	if (params->side == 0)
		params->wall_x = cub->user->y + params->perp_wall_dist
			* params->ray_dir_y;
	else
		params->wall_x = cub->user->x + params->perp_wall_dist
			* params->ray_dir_x;
	params->wall_x -= floorf(params->wall_x);
	ray[i].wall_x = params->wall_x;
	ray[i].x = cub->user->x + params->perp_wall_dist * params->ray_dir_x;
	ray[i].y = cub->user->y + params->perp_wall_dist * params->ray_dir_y;
}

static void	process_single_ray(t_raycast_params *params, t_ray *ray,
			t_map *cub, int i)
{
	calculate_step_and_side_dist(params, cub);
	perform_dda(params, cub);
	calculate_wall_distance(params, cub);
	calculate_wall_x_coordinate(params, ray, cub, i);
	setup_ray_result(params, ray, i);
}

void	raycast_loop(t_ray *ray, t_map *cub)
{
	t_raycast_params	params;
	int					i;

	i = 0;
	while (i < NUM_RAYS)
	{
		init_ray_params(&params, cub, i);
		process_single_ray(&params, ray, cub, i);
		i++;
	}
}

void	raycast(t_ray *ray, t_map *cub)
{
	raycast_loop(ray, cub);
}
