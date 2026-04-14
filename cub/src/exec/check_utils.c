/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salsoysa <salsoysa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:08:26 by salsoysa          #+#    #+#             */
/*   Updated: 2025/10/18 17:12:37 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_boolean	_check_f_utils(char **rgb, t_map *cubd)
{
	if (!rgb || count_strings(rgb) != 3)
		return (ft_free_array(rgb), FALSE);
	if (exec_atoi_cub(rgb, cubd, 0))
		return (ft_free_array(rgb), FALSE);
	if (ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[1]) < 0
		|| ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[2]) < 0
		|| ft_atoi(rgb[2]) > 255)
		return (ft_free_array(rgb), FALSE);
	return (TRUE);
}

t_boolean	_check_c_utils(char **rgb, t_map *cubd)
{
	if (!rgb || count_strings(rgb) != 3)
		return (ft_free_array(rgb), FALSE);
	if (exec_atoi_cub(rgb, cubd, 1))
		return (ft_free_array(rgb), FALSE);
	if (ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[1]) < 0
		|| ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[2]) < 0
		|| ft_atoi(rgb[2]) > 255)
		return (ft_free_array(rgb), FALSE);
	return (TRUE);
}
