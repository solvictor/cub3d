#include "cub3d.h"

/*
	TODO Might replace the exit()
*/
int	on_keydown(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		return (clean_memory(vars), exit(EXIT_SUCCESS), 1);
	return (0);
}
