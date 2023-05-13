#include "cub3d.h"

static void	init_map(t_vars *vars, t_map *map)
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
	map->width = 0;
	map->start_coords[0] = -1;
	map->start_coords[1] = -1;
	map->start_direction = '\0';
	map->map = NULL;
	vars->map = map;
}

static void	init_display(t_vars *vars, t_display *display)
{
	display->mlx = NULL;
	display->win = NULL;
	display->img = NULL;
	display->addr = NULL;
	display->heigth = -1;
	display->width = -1;
	display->bpp = -1;
	display->size_line = -1;
	display->endian = -1;
	vars->display = display;
}

static void	init_player(t_vars *vars, t_player *player)
{
	player->x = -1;
	player->y = -1;
	vars->player = player;
}

/*
	Check if no start direction for player
*/

int	main(int ac, char **av)
{
	t_vars		vars;
	t_map		map;
	t_display	display;
	t_player	player;

	if (ac != 2)
		return (error_str("Usage: ./cub3d path/to/map.cub"), EXIT_FAILURE);
	vars.file_content = NULL;
	init_map(&vars, &map);
	init_display(&vars, &display);
	init_player(&vars, &player);
	if (parsing(av[1], &vars, &map) == false)
		return (clean_memory(&vars), EXIT_FAILURE);
	if (start_display(&display, &vars) == false)
		return (clean_memory(&vars), EXIT_FAILURE);
	clean_memory(&vars);
	return (EXIT_SUCCESS);
}
