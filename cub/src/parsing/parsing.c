/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leogarci <leogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:27:54 by leogarci          #+#    #+#             */
/*   Updated: 2025/10/18 14:26:42 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_boolean	check_valid_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b'
				&& !str[i + 4])
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

char	*ft_get_all_in_one_line(int fd)
{
	char	*str;
	char	*res;

	str = get_next_line(fd);
	if (!str)
		return (NULL);
	res = ft_strdup(str);
	if (!res)
		return (free(str), NULL);
	free(str);
	while (str)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		res = ft_strjoin_free(res, str);
		free(str);
	}
	return (res);
}

t_boolean	ft_parse_element(char **cub, t_map *cubd)
{
	int	i;

	i = 0;
	while (cub[i])
	{
		if (check_no(cub[i], cubd) == TRUE || !check_so(cub[i], cubd))
			i++;
		else if (!check_we(cub[i], cubd) || !check_ea(cub[i], cubd))
			i++;
		else if (!check_f(cub[i], cubd) || !check_c(cub[i], cubd))
			i++;
		else if (!ft_isspacestr(cub[i], cubd))
			i++;
		else if (!check_first_and_last_line(cub[i]))
			break ;
		else if (check_break(cub[i], cubd) == BREAK)
			break ;
		else if (cub[i])
			return (ft_free_array(cub), write(2, "Error\n", 6), FALSE);
	}
	if (i != 6)
		return (ft_free_array(cub), write(2, "Error\n", 6), FALSE);
	if (parse_map(cub, i, cubd))
		return (write(2, "Error\n", 6), FALSE);
	return (TRUE);
}

t_boolean	parse_file(int fd, t_map *cubd)
{
	char	*str;
	char	**cub;

	str = ft_get_all_in_one_line(fd);
	if (!str)
		return (FALSE);
	cub = ft_split(str, 10);
	if (!cub)
		return (free(str), FALSE);
	free(str);
	if (ft_parse_element(cub, cubd))
		return (FALSE);
	return (TRUE);
}

t_boolean	ft_parsing(char *str, t_map *cub)
{
	int	fd;

	if (check_valid_name(str))
		return (printf("Wrong name of map\n"), FALSE);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (perror("Error opening files"), FALSE);
	if (parse_file(fd, cub))
		return (close(fd), FALSE);
	close(fd);
	return (TRUE);
}
