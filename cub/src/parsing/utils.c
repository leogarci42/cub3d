/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leogarci <leogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:33:04 by leogarci          #+#    #+#             */
/*   Updated: 2025/10/17 16:26:08 by leogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		fprintf(stdout, "tableau: [%d]: %s\n", i, array[i]);
		i++;
	}
}

t_boolean	check_break(char *cub, t_map *cubd)
{
	if (check_no(cub, cubd) == BREAK || check_so(cub, cubd) == BREAK)
		return (BREAK);
	else if (check_we(cub, cubd) == BREAK || check_ea(cub, cubd) == BREAK)
		return (BREAK);
	else if (check_f(cub, cubd) == BREAK || check_c(cub, cubd) == BREAK)
		return (BREAK);
	return (TRUE);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

t_boolean	ft_check_digit(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_isdigit((int)rgb[i][j]) && !ft_isspace((int)rgb[i][j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

void	new_pos(t_map *cub, float new_x, float new_y)
{
	cub->user->x = new_x;
	cub->user->y = new_y;
}
