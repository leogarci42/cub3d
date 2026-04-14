/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leogarci <leogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:11:24 by leogarci          #+#    #+#             */
/*   Updated: 2025/10/18 17:09:39 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_strings(char **arr)
{
	int	count;

	count = 0;
	if (!arr)
		return (0);
	while (arr[count])
		count++;
	return (count);
}

t_boolean	exec_atoi_cub(char **rgb, t_map *cubd, int i)
{
	if (ft_check_digit(rgb))
		return (FALSE);
	if (i == 0)
	{
		cubd->rgb_fc[0][0] = ft_atoi(rgb[0]);
		cubd->rgb_fc[0][1] = ft_atoi(rgb[1]);
		cubd->rgb_fc[0][2] = ft_atoi(rgb[2]);
	}
	else
	{
		cubd->rgb_fc[1][0] = ft_atoi(rgb[0]);
		cubd->rgb_fc[1][1] = ft_atoi(rgb[1]);
		cubd->rgb_fc[1][2] = ft_atoi(rgb[2]);
	}
	return (TRUE);
}

t_boolean	check_f(char *str, t_map *cubd)
{
	int			i;
	char		**rgb;
	static int	j = 0;

	if (j != 0)
		return (BREAK);
	j += 1;
	i = 0;
	(void)cubd;
	while (ft_isspace(str[i]) && str[i])
		i++;
	if (str[i] != 'F')
		return (FALSE);
	i++;
	while (ft_isspace(str[i]) && str[i])
		i++;
	rgb = ft_split(&str[i], ',');
	if (_check_f_utils(rgb, cubd) == FALSE)
		return (FALSE);
	ft_free_array(rgb);
	return (TRUE);
}

t_boolean	check_c(char *str, t_map *cubd)
{
	int			i;
	char		**rgb;
	static int	j = 0;

	if (j != 0)
		return (BREAK);
	j += 1;
	i = 0;
	(void)cubd;
	while (ft_isspace(str[i]) && str[i])
		i++;
	if (str[i] != 'C')
		return (FALSE);
	i++;
	while (ft_isspace(str[i]) && str[i])
		i++;
	rgb = ft_split(&str[i], ',');
	if (_check_c_utils(rgb, cubd) == FALSE)
		return (FALSE);
	ft_free_array(rgb);
	return (TRUE);
}

t_boolean	ft_isspacestr(char *str, t_map *cubd)
{
	int	i;

	i = 0;
	(void)cubd;
	while (str[i])
		if (!ft_isspace(str[i++]))
			return (FALSE);
	return (TRUE);
}
