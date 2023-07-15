#include "cub3d.h"

bool	do_textures_exist(t_map *map)
{
	int			tmp;

	tmp = open(map->path_north, R_OK);
	if (tmp == -1)
		return (error_str("Problem with north texture"), false);
	close(tmp);
	tmp = open(map->path_south, R_OK);
	if (tmp == -1)
		return (error_str("Problem with south texture"), false);
	close(tmp);
	tmp = open(map->path_west, R_OK);
	if (tmp == -1)
		return (error_str("Problem with west texture"), false);
	close(tmp);
	tmp = open(map->path_east, R_OK);
	if (tmp == -1)
		return (error_str("Problem with east texture"), false);
	close(tmp);
	return (true);
}
