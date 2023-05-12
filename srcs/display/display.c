#include "cub3d.h"

static bool	init(t_display *display)
{
	display->mlx = mlx_init();
	mlx_get_screen_size(display->mlx, &display->width, &display->heigth);
	display->win = mlx_new_window(display->mlx, display->width,
			display->heigth, "Cub3d ouais ouai ouaaaaais");
	ft_printf("No segfault\n");
	display->img = mlx_new_image(display->mlx, display->width, display->heigth);
	display->addr = mlx_get_data_addr(display->img, &display->bpp,
			&display->size_line, &display->endian);
	if (!display->mlx || !display->win || !display->win || !display->addr)
		return (error_str("Fail in MLX"), false);
	return (true);
}

bool	start_display(t_display *display, t_vars *vars)
{
	if (init(display) == false)
		return (false);
	mlx_put_image_to_window(display->mlx, display->win, display->img, 0, 0);
	mlx_hook(display->win, ON_DESTROY, NO_MASK, on_destroy, vars);
	mlx_loop(display->mlx);
	return (true);
}
