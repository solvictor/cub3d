#include "cub3d.h"

void	draw_2d(t_display *display, t_map *map)
{
	const int	square_length = display->width
		/ biggest(map->heigth, map->width);
	int			i;
	int			j;
	int			x;
	int			y;

	i = 0;
	y = 0;
	while (i < display->heigth - 10)
	{
		j = 0;
		x = 0;
		while (j < display->width - 10)
		{
			if (map->map[x][y] && map->map[x][y] != '0')
				mlx_spp(display, j, i, 0xFF00FF);
			if (j > x * square_length && x < map->width)
				++x;
			++j;
		}
		if (i > y * square_length && y < map->heigth)
			++y;
		++i;
	}
	mlx_put_image_to_window(display->mlx, display->win, display->img, 0, 0);
}


