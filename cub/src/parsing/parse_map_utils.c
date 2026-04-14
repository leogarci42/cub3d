/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leogarci <leogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:40:51 by leogarci          #+#    #+#             */
/*   Updated: 2025/07/12 19:02:13 by leogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_boolean	check_horizontal_line(char *line, int len)
{
	int	j;

	j = 0;
	while (line[j])
	{
		while (j < len && line[j])
			j++;
		if (!line[j])
			break ;
		if (line[j] != '1' && !ft_isspace(line[j]) && line[j])
			return (FALSE);
		j++;
	}
	return (TRUE);
}

t_boolean	check_horizontal(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (check_horizontal_line(map[i], len))
			return (FALSE);
		if (map[i + 1] && map[i + 2])
		{
			if (ft_strlen(map[i + 2]) > ft_strlen(map[i]))
				len = ft_strlen(map[i]);
			else
				len = ft_strlen(map[i + 2]);
		}
		i++;
	}
	return (TRUE);
}
