#include "cub3d_bonus.h"

static bool	valid_coordinates(t_map *map, int x, int y)
{
	return (x >= 0 && y >= 0 && x < map->width && y < map->height);
}

/*
	Good but only supports one door ; way to fix this would be to check the
	direction of the player (plane)
*/

static bool	detect_door(t_display *display, t_map *map, t_camera *camera,
	int coords[2])
{
	const int	map_x = camera->pos.x;
	const int	map_y = camera->pos.y;
	char		map_char;
	bool		door_found;

	door_found = false;
	if (valid_coordinates(map, map_x, map_y - 1)
		&& (map->map[map_y - 1][map_x] == '2'
		|| map->map[map_y - 1][map_x] == '3'))
	{
		coords[0] = map_x;
		coords[1] = map_y - 1;
		door_found = true;
	}
	if (valid_coordinates(map, map_x, map_y + 1)
		&& (map->map[map_y + 1][map_x] == '2'
		|| map->map[map_y + 1][map_x] == '3'))
	{
		coords[0] = map_x;
		coords[1] = map_y + 1;
		door_found = true;
	}	
	if (valid_coordinates(map, map_x - 1, map_y)
		&& (map->map[map_y][map_x - 1] == '2'
		|| map->map[map_y][map_x - 1] == '3'))
	{
		coords[0] = map_x - 1;
		coords[1] = map_y;
		door_found = true;
	}
	if (valid_coordinates(map, map_x + 1, map_y)
		&& (map->map[map_y][map_x + 1] == '2'
		|| map->map[map_y][map_x + 1] == '3'))
	{
		coords[0] = map_x + 1;
		coords[1] = map_y;
		door_found = true;
	}
	return (door_found);
}

bool	door(t_display *display, t_map *map, t_camera *camera)
{
	int	coords[2];

	if (detect_door(display, map, camera, coords) == false)
		return (false);
	return (true);
}

void	door_action(t_display *display, t_map *map, t_camera *camera)
{
	int	coords[2];

	if (detect_door(display, map, camera, coords))
	{
		if (map->map[coords[1]][coords[0]] == '2')
			map->map[coords[1]][coords[0]] = '3';
		else if (map->map[coords[1]][coords[0]] == '3')
			map->map[coords[1]][coords[0]] = '2';
		display->refresh = true;
	}
}