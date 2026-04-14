/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:34:29 by salsoysa          #+#    #+#             */
/*   Updated: 2025/10/06 17:46:39 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	north_coords_up(int i, int j, t_map *cub)
{
	cub->user->x = j + 0.5;
	cub->user->y = i + 0.5;
	cub->user->angle = (3 * M_PI) / 2;
	cub->user->facing = NORTH;
}

static void	south_coords_up(int i, int j, t_map *cub)
{
	cub->user->x = j + 0.5;
	cub->user->y = i + 0.5;
	cub->user->angle = M_PI / 2;
	cub->user->facing = SOUTH;
}

static void	west_coords_up(int i, int j, t_map *cub)
{
	cub->user->x = j + 0.5;
	cub->user->y = i + 0.5;
	cub->user->angle = M_PI;
	cub->user->facing = WEST;
}

static void	east_coords_up(int i, int j, t_map *cub)
{
	cub->user->x = j + 0.5;
	cub->user->y = i + 0.5;
	cub->user->angle = 0;
	cub->user->facing = EAST;
}

int	coords_util(int i, int j, t_map *cub)
{
	if (cub->map[i][j] == 'N')
	{
		north_coords_up(i, j, cub);
		return (-1);
	}
	if (cub->map[i][j] == 'S')
	{
		south_coords_up(i, j, cub);
		return (-1);
	}
	if (cub->map[i][j] == 'W')
	{
		west_coords_up(i, j, cub);
		return (-1);
	}
	if (cub->map[i][j] == 'E')
	{
		east_coords_up(i, j, cub);
		return (-1);
	}
	return (0);
}
