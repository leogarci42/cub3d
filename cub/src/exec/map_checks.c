/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:39:46 by salsoysa          #+#    #+#             */
/*   Updated: 2025/10/06 17:45:01 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_boolean	check_first_and_last_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_boolean	ft_check_in_between(char *str, int *start)
{
	int	i;

	i = *start;
	while (str[i])
	{
		if (str[i] == '1' || str[i] == '0')
			i++;
		else if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E'
			|| str[i] == 'W')
			i++;
		else if (ft_isspace(str[i]))
			i++;
		else
			return (FALSE);
	}
	while (ft_isspace(str[i - 1]))
		i--;
	if (str[i - 1] != '1')
		return (FALSE);
	return (TRUE);
}

t_boolean	check_amount_player(char **map)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	t = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
				t++;
			j++;
		}
		i++;
	}
	if (t != 1)
		return (FALSE);
	return (TRUE);
}

t_boolean	check_in_between(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i + 1])
	{
		j = 0;
		while (ft_isspace(map[i][j]))
			j++;
		if (!map[i][j] || map[i][j] != '1')
			return (FALSE);
		else
		{
			if (ft_check_in_between(map[i], &j))
				return (FALSE);
			else
				i++;
		}
	}
	if (check_first_and_last_line(map[i]))
		return (FALSE);
	return (TRUE);
}
