#include "cub3d_bonus.h"

void	clean_map_variables(t_map *map)
{
	if (map->path_north)
		free(map->path_north);
	if (map->path_south)
		free(map->path_south);
	if (map->path_east)
		free(map->path_east);
	if (map->path_west)
		free(map->path_west);
	if (map->map)
		ft_free_strs(map->map);
	if (map->sprites)
		free(map->sprites);
	if (map->str_sprite_textures)
		ft_free_strs(map->str_sprite_textures);
	if (map->path_door_closed)
		free(map->path_door_closed);
}
