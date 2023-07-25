/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_formater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:24:57 by tgernez           #+#    #+#             */
/*   Updated: 2023/07/25 12:24:58 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	format_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	if (!map)
		return ;
	map->width += 2;
	while (map->map[i])
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == ' ' || map->map[i][j] == '\0' ||
				map->map[i][j] == '\n')
				map->map[i][j] = '1';
			if (j == map->width - 2)
				map->map[i][j] = '\n';
			if (j == map->width - 1)
				map->map[i][j] = '\0';
			++j;
		}
		++i;
	}
	map->width -= 2;
}
