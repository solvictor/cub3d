#include "cub3d.h"

/*
	TODO Might replace the exit()
*/
int	on_keydown(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		return (clean_memory(vars), exit(EXIT_SUCCESS), 1);
	if (keycode == 119)
		return (basic_up(vars), 1);
	if (keycode == 97)
		return (basic_left(vars), 1);
	if (keycode == 115)
		return (basic_down(vars), 1);
	if (keycode == 100)
		return (basic_right(vars), 1);
	ft_printf("Keycode %d /Keycode\n", keycode);
	return (0);
}
