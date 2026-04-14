/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:41:32 by salsoysa          #+#    #+#             */
/*   Updated: 2025/10/06 14:41:56 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_rays(t_user *user, t_ray *ray)
{
	int		i;
	float	step;

	step = FOV / (float)NUM_RAYS;
	i = 0;
	while (i < NUM_RAYS)
	{
		ray[i].angle = user->angle - (FOV / 2.0f) + (i * step);
		if (ray[i].angle < 0)
			ray[i].angle += 2 * M_PI;
		else if (ray[i].angle >= 2 * M_PI)
			ray[i].angle -= 2 * M_PI;
		ray[i].hit = 0;
		ray[i].distance = 0.0;
		ray[i].wall_dir = user->facing;
		ray[i].side = 0;
		i++;
	}
}
