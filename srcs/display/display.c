#include "cub3d.h"

static bool	init(t_display *display)
{
	display->mlx = mlx_init();
	mlx_get_screen_size(display->mlx, &display->width, &display->heigth);
	// display->width = 1200;
	// display->heigth = 200;
	display->win = mlx_new_window(display->mlx, display->width,
			display->heigth, "Cub3d ouais ouais ouaaaaais");
	display->img = mlx_new_image(display->mlx, display->width, display->heigth);
	display->addr = mlx_get_data_addr(display->img, &display->bpp,
			&display->size_line, &display->endian);
	if (!display->mlx || !display->win || !display->win || !display->addr)
		return (error_str("Fail in MLX"), false);
	return (true);
}

void	mlx_spp(t_display *display, int x, int y, int color)
{
	char	*dst;

	dst = display->addr + (y * display->size_line + x * (display->bpp / 8));
	*(unsigned int *)dst = color;
}

void	clear_image(t_display *display)
{
	int	i;
	int	j;

	i = 0;
	while (i < display->heigth)
	{
		j = 0;
		while (j < display->width)
		{
			mlx_spp(display, j, i, 0x000000);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(display->mlx, display->win, display->img, 0, 0);
}

bool	start_display(t_display *display, t_vars *vars)
{
	if (init(display) == false)
		return (false);
	mlx_put_image_to_window(display->mlx, display->win, display->img, 0, 0);
	mlx_hook(display->win, ON_DESTROY, NO_MASK, on_destroy, vars);
	mlx_hook(display->win, ON_KEYDOWN, KEYPRESS_MASK, on_keydown, vars);
	clear_image(display);
	draw_2d(display, vars->map, vars->player);
	mlx_loop(display->mlx);
	return (true);
}
