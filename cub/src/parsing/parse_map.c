/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leogarci <leogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:44:58 by leogarci          #+#    #+#             */
/*   Updated: 2025/10/14 15:54:09 by leogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_boolean	ft_build_stack_map_recursive(t_stack_params *params)
{
	char	buffer[MAX];

	buffer[MAX - 1] = '\0';
	if (ft_strlen(params->cubd->map[params->i]) > MAX)
		return (ft_free_array(params->src_map), FALSE);
	ft_strlcpy(buffer, params->cubd->map[params->i],
		(ft_strlen(params->cubd->map[params->i]) + 2));
	params->stack_lines[params->i] = buffer;
	params->stack_map[params->i] = params->stack_lines[params->i];
	if (params->i + 1 == params->count)
	{
		params->stack_map[params->i + 1] = NULL;
		params->cubd->map = params->stack_map;
		params->cubd->mlx[0].mlx_ptr = NULL;
		params->cubd->mlx[0].win_ptr = NULL;
		return (finalize_map_setup(params));
	}
	params->i++;
	ft_build_stack_map_recursive(params);
	return (TRUE);
}

void	get_player_coordinate(t_map *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (coords_util(i, j, cub) == 0)
				j++;
			else
				return ;
		}
		i++;
	}
	printf("Player not found in the map.\n");
}

t_boolean	ft_allocate_stack(char **src_map, t_map *cubd)
{
	char			*stack_lines[MAX];
	char			*stack_map[MAX + 1];
	int				i;
	t_stack_params	params;

	i = 0;
	while (cubd->map[i])
	{
		if (i >= MAX)
			return (ft_free_array(src_map), FALSE);
		i++;
	}
	params.src_map = src_map;
	params.i = 0;
	params.count = i;
	params.stack_lines = stack_lines;
	params.stack_map = stack_map;
	params.cubd = cubd;
	return (ft_build_stack_map_recursive(&params));
}

t_boolean	parse_map(char **file, int i, t_map *cubd)
{
	char	**map;

	map = &file[i];
	cubd->map = &file[i];
	if (!check_first_and_last_line(*map++))
		if (!check_in_between(map))
			if (!check_amount_player(map))
				if (!check_horizontal(cubd->map))
					return (ft_allocate_stack(file, cubd));
	return (ft_free_array(file), FALSE);
}
