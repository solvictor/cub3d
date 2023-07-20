#include "cub3d_bonus.h"

/*
	Check if textires are XPM files
*/

int	main(int ac, char **av)
{
	t_vars		vars;
	t_map		map;
	t_display	display;
	t_camera	camera;

	if (ac != 2)
		return (error_str("Usage: ./cub3d path/to/map.cub"), EXIT_FAILURE);
	vars.file_content = NULL;
	set_to_zero_map(&vars, &map);
	set_to_zero_display(&vars, &display);
	set_to_zero_camera(&vars, &camera);
	if (parsing(av[1], &vars, &map) == false)
		return (clean_memory(&vars), EXIT_FAILURE);
	if (start_display(&display, &vars) == false)
		return (clean_memory(&vars), EXIT_FAILURE);
	clean_memory(&vars);
	return (EXIT_SUCCESS);
}
