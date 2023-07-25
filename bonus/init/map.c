/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:25:04 by tgernez           #+#    #+#             */
/*   Updated: 2023/07/25 12:25:05 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_to_zero_map(t_vars *vars, t_map *map)
{
	int	i;

	i = 0;
	while (i < PARAMETER_NUMBER)
		map->param_lines[i++] = -1;
	map->path_north = NULL;
	map->path_south = NULL;
	map->path_east = NULL;
	map->path_west = NULL;
	map->path_door_closed = NULL;
	map->floor_color = 0;
	map->ceiling_color = 0;
	map->total_parameters = 0;
	map->height = 0;
	map->width = 0;
	map->start_coords[0] = -1;
	map->start_coords[1] = -1;
	map->start_direction = '\0';
	map->map = NULL;
	map->first_line_map = -1;
	map->textures[0].img = NULL;
	vars->map = map;
}
