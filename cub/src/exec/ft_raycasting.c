/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leogarci <leogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:13:20 by leogarci          #+#    #+#             */
/*   Updated: 2025/10/06 15:03:20 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(int x, int y, char **map)
{
	int	len;
	int	str;

	str = 0;
	while (map[str])
		str++;
	if (x >= str || x < 0)
		return (0);
	len = ft_strlen(map[x]);
	if (y < 0 || x > str || y >= len)
		return (0);
	if (!map[x])
		return (0);
	return (map[x][y] == '1');
}

void	ft_mathematrics(t_all_ray *all_ray)
{
	all_ray->prev_x = all_ray->x;
	all_ray->prev_y = all_ray->y;
	all_ray->x += all_ray->dir_x * all_ray->step_size;
	all_ray->y += all_ray->dir_y * all_ray->step_size;
	all_ray->distance += all_ray->step_size;
	all_ray->grid_x = (int)all_ray->x;
	all_ray->grid_y = (int)all_ray->y;
}

void	ft_wall_design(t_all_ray *all_ray, t_ray *ray)
{
	all_ray->prev_grid_x = (int)all_ray->prev_x;
	all_ray->prev_grid_y = (int)all_ray->prev_y;
	if (all_ray->grid_x != all_ray->prev_grid_x)
	{
		ray->side = 0;
		if (all_ray->dir_x > 0)
			ray->wall_dir = SOUTH;
		else
			ray->wall_dir = NORTH;
	}
	else if (all_ray->grid_y != all_ray->prev_grid_y)
	{
		ray->side = 1;
		if (all_ray->dir_y > 0)
			ray->wall_dir = EAST;
		else
			ray->wall_dir = WEST;
	}
	ray->hit = 1;
	ray->distance = all_ray->distance;
	ray->x = all_ray->x;
	ray->y = all_ray->y;
}

static void	calculate_colors(t_map *cub, int *floor_color, int *ceiling_color)
{
	*floor_color = (cub->rgb_fc[0][0] << 16) | (cub->rgb_fc[0][1] << 8)
		| cub->rgb_fc[0][2];
	*ceiling_color = (cub->rgb_fc[1][0] << 16) | (cub->rgb_fc[1][1] << 8)
		| cub->rgb_fc[1][2];
}

void	ft_raycasting(t_map *cub)
{
	t_ray	ray[NUM_RAYS];
	int		floor_color;
	int		ceiling_color;

	calculate_colors(cub, &floor_color, &ceiling_color);
	fill_floor_ceiling(&cub->ssaa_img, floor_color, ceiling_color);
	cast_rays(cub->user, ray);
	raycast(ray, cub);
	draw_walls_rec(0, ray, cub, &cub->ssaa_img);
}
