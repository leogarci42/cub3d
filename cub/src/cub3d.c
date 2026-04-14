/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leogarci <leogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:57:40 by leogarci          #+#    #+#             */
/*   Updated: 2025/09/25 17:40:46 by salsoysa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map	cub;

	if (argc == 2)
	{
		if (ft_parsing(argv[1], &cub))
			return (1);
	}
	else
		return (printf("No input\n"), 1);
	return (0);
}
