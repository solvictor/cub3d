/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:25:42 by tgernez           #+#    #+#             */
/*   Updated: 2023/07/25 12:25:43 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	valid_coordinates(t_map *map, int x, int y)
{
	return (x >= 0 && y >= 0 && x < map->width && y < map->height);
}

static void	set_coords(int x, int y, int coords[2])
{
	coords[0] = x;
	coords[1] = y;
}

static bool	detect_door(t_map *map, t_camera *camera, int coords[2])
{
	const int	map_x = camera->pos.x;
	const int	map_y = camera->pos.y;

	if (valid_coordinates(map, map_x, map_y - 1)
		&& ft_c_in_str(map->map[map_y - 1][map_x], DOOR)
		&& 5 * PI / 4 < camera->angle && camera->angle <= 7 * PI / 4)
		return (set_coords(map_x, map_y - 1, coords), true);
	if (valid_coordinates(map, map_x, map_y + 1)
		&& ft_c_in_str(map->map[map_y + 1][map_x], DOOR)
		&& PI / 4 < camera->angle && camera->angle <= 3 * PI / 4)
		return (set_coords(map_x, map_y + 1, coords), true);
	if (valid_coordinates(map, map_x - 1, map_y)
		&& ft_c_in_str(map->map[map_y][map_x - 1], DOOR)
		&& ((7 * PI / 4 < camera->angle && camera->angle <= 2 * PI / 4)
		|| (0 <= camera->angle && camera->angle <= PI / 4)))
		return (set_coords(map_x - 1, map_y, coords), true);
	if (valid_coordinates(map, map_x + 1, map_y)
		&& ft_c_in_str(map->map[map_y][map_x + 1], DOOR)
		&& 3 * PI / 4 < camera->angle && camera->angle <= 5 * PI / 4)
		return (set_coords(map_x + 1, map_y, coords), true);
	return (false);
}

bool	door(t_map *map, t_camera *camera)
{
	int	coords[2];

	if (detect_door(map, camera, coords) == false)
		return (false);
	return (true);
}

void	door_action(t_display *display, t_map *map, t_camera *camera)
{
	int	coords[2];

	if (detect_door(map, camera, coords))
	{
		if (map->map[coords[1]][coords[0]] == '2')
			map->map[coords[1]][coords[0]] = '3';
		else if (map->map[coords[1]][coords[0]] == '3')
			map->map[coords[1]][coords[0]] = '2';
		display->refresh = true;
	}
}
