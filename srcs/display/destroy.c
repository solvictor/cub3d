#include "cub3d.h"

int	on_destroy(t_vars *vars)
{
	clean_memory(vars);
	exit(EXIT_SUCCESS);
	return (1);
}

int	on_keypress(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		return (clean_memory(vars), exit(EXIT_SUCCESS), 1);
	return (0);
}
