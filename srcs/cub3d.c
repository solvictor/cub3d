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
	map->height = 0;
	map->width = 0;
	map->start_coords[0] = -1;
	map->start_coords[1] = -1;
	map->start_direction = '\0';
	map->map = NULL;
	map->first_line = -1;
	map->islands = 0;
	vars->map = map;
}

static void	init_display(t_vars *vars, t_display *display)
{
	display->mlx = NULL;
	display->win = NULL;
	display->img = NULL;
	display->addr = NULL;
	display->height = -1;
	display->width = -1;
	display->bpp = -1;
	display->size_line = -1;
	display->endian = -1;
	display->refresh = false;
	vars->display = display;
}

static void	init_player(t_vars *vars, t_player *player)
{
	player->x = -1;
	player->y = -1;
	player->speed = 5;
	player->direction = 90;
	player->fov = 66;
	player->square_x = -1;
	player->square_y = -1;
	player->rotate_speed = 90;
	vars->player = player;
}

static void	init_camera(t_vars *vars, t_camera *camera)
{
	set_vector(camera->direction, 0, 0);
	set_vector(camera->plane, 0, 0);
	vars->camera = camera;
}

int	main(int ac, char **av)
{
	t_vars		vars;
	t_map		map;
	t_display	display;
	t_player	player;
	t_camera	camera;

	if (ac != 2)
		return (error_str("Usage: ./cub3d path/to/map.cub"), EXIT_FAILURE);
	vars.file_content = NULL;
	init_map(&vars, &map);
	init_display(&vars, &display);
	init_player(&vars, &player);
	init_camera(&vars, &camera);
	if (parsing(av[1], &vars, &map) == false)
		return (clean_memory(&vars), EXIT_FAILURE);
	if (start_display(&display, &vars) == false)
		return (clean_memory(&vars), EXIT_FAILURE);
	clean_memory(&vars);
	return (EXIT_SUCCESS);
}
