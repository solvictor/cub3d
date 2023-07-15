#include "cub3d.h"

int	on_keydown(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		return (clean_memory(vars), exit(EXIT_SUCCESS), 1);
	if (keycode == XK_w)
		return (basic_up(vars), 1);
	if (keycode == XK_a)
		return (basic_left(vars), 1);
	if (keycode == XK_s)
		return (basic_down(vars), 1);
	if (keycode == XK_d)
		return (basic_right(vars), 1);
	ft_printf("Keycode %d /Keycode\n", keycode);
	return (0);
}
