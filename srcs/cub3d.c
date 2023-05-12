#include "cub3d.h"

static void	set_to_zero(t_vars *vars, t_map *map)
{
	map->path_north = NULL;
	map->path_south = NULL;
	map->path_east = NULL;
	map->path_west = NULL;
	map->ceiling_color[0] = 0;
	map->ceiling_color[1] = 0;
	map->ceiling_color[2] = 0;
	map->floor_color[0] = 0;
	map->floor_color[1] = 0;
	map->floor_color[2] = 0;
	map->param_number = 0;
	map->heigth = 0;
	map->length = 0;
	map->start_coords[0] = -1;
	map->start_coords[1] = -1;
	map->start_direction = '\0';
	map->map = NULL;
	vars->file_content = NULL;
	vars->map = map;
}

/*
	Check if no start direction for player
*/

int	main(int ac, char **av)
{
	t_vars	vars;
	t_map	map;

	if (ac != 2)
		return (error_str("Usage: ./cub3d path/to/map.cub"), EXIT_FAILURE);
	set_to_zero(&vars, &map);
	if (parsing(av[1], &vars, &map) == false)
		return (clean_memory(&vars), EXIT_FAILURE);
	clean_memory(&vars);
	return (EXIT_SUCCESS);
}
