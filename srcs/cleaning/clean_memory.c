#include "cub3d.h"

static void	clean_map(t_map *map)
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
}

void	clean_memory(t_vars *vars)
{
	clean_map(vars->map);
	ft_free_strs(vars->file_content);
}
