/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leogarci <leogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:41:45 by leogarci          #+#    #+#             */
/*   Updated: 2025/10/17 16:25:45 by leogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_boolean	check_xpm(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{	
			if (str[i + 1] == 'x' && str[i + 2] == 'p'
				&& str[i + 3] == 'm' && !str[i + 4])
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

t_boolean	check_no(char *str, t_map *cubd)
{
	int			i;
	char		*str1;
	static int	j = 0;

	if (j != 0)
		return (BREAK);
	i = 0;
	while (ft_isspace(str[i]) && str[i])
		i++;
	if (str[i] != 'N' || str[i + 1] != 'O')
		return (FALSE);
	i += 2;
	while (ft_isspace(str[i]) && str[i])
		i++;
	str1 = &str[i];
	i = 0;
	while (str1[i] && !ft_isspace(str1[i]))
		i++;
	str1[i] = 0;
	if (check_xpm(str1))
		return (j += 1, FALSE);
	return (cubd->nsew[0].pwd = str1, j += 1, TRUE);
}

t_boolean	check_so(char *str, t_map *cubd)
{
	int			i;
	char		*str1;
	static int	j = 0;

	if (j != 0)
		return (BREAK);
	i = 0;
	while (ft_isspace(str[i]) && str[i])
		i++;
	if (str[i] != 'S' || str[i + 1] != 'O')
		return (FALSE);
	i += 2;
	while (ft_isspace(str[i]) && str[i])
		i++;
	str1 = &str[i];
	i = 0;
	while (str1[i] && !ft_isspace(str1[i]))
		i++;
	str1[i] = 0;
	if (check_xpm(str1))
		return (j += 1, FALSE);
	return (cubd->nsew[1].pwd = str1, j += 1, TRUE);
}

t_boolean	check_we(char *str, t_map *cubd)
{
	int			i;
	char		*str1;
	static int	j = 0;

	if (j != 0)
		return (BREAK);
	i = 0;
	while (ft_isspace(str[i]) && str[i])
		i++;
	if (str[i] != 'W' || str[i + 1] != 'E')
		return (FALSE);
	i += 2;
	while (ft_isspace(str[i]) && str[i])
		i++;
	str1 = &str[i];
	i = 0;
	while (str1[i] && !ft_isspace(str1[i]))
		i++;
	str1[i] = 0;
	if (check_xpm(str1))
		return (j += 1, FALSE);
	return (cubd->nsew[3].pwd = str1, j += 1, TRUE);
}

t_boolean	check_ea(char *str, t_map *cubd)
{
	int			i;
	char		*str1;
	static int	j = 0;

	if (j != 0)
		return (BREAK);
	i = 0;
	while (ft_isspace(str[i]) && str[i])
		i++;
	if (str[i] != 'E' || str[i + 1] != 'A')
		return (FALSE);
	i += 2;
	while (ft_isspace(str[i]) && str[i])
		i++;
	str1 = &str[i];
	i = 0;
	while (str1[i] && !ft_isspace(str1[i]))
		i++;
	str1[i] = 0;
	if (check_xpm(str1))
		return (j += 1, FALSE);
	return (cubd->nsew[2].pwd = str1, j += 1, TRUE);
}
