#include "cub3d.h"

void	draw_player(t_display *display, t_player *player)
{
	int	i;
	int	j;

	i = -CURSOR_RADIUS;
	while (i <= CURSOR_RADIUS)
	{
		j = -CURSOR_RADIUS;
		while (j <= CURSOR_RADIUS)
		{
			if (i * i + j * j <= CURSOR_RADIUS * CURSOR_RADIUS)
				mlx_spp(display, player->x - i, player->y - j, 0xFF0000);
			++j;
		}
		++i;
	}
}

void	draw_2d_pixels(t_display *display, t_map *map, int i, int y)
{
	int	j;
	int	x;

	j = 0;
	x = 1;
	while (j < display->width)
	{
		if (map->map[y - 1] && ft_c_in_str(map->map[y - 1][x - 1], FREE))
			mlx_spp(display, j, i, 0xFFFFFF);
		else
			mlx_spp(display, j, i, 0x000000);
		if (j > x * display->square_length && x < map->width)
			mlx_spp(display, j, i, 0);
		if (i > y * display->square_length && y < map->height)
			mlx_spp(display, j, i, 0);
		if (j > x * display->square_length && x < map->width)
			++x;
		++j;
	}
}

void	draw_2d(t_display *display, t_map *map)
{
	const int	square_length = display->square_length;
	int			i;
	int			y;

	i = 0;
	y = 1;
	while (i < display->height)
	{
		draw_2d_pixels(display, map, i, y);
		if (i > y * square_length && y < map->height)
			++y;
		++i;
	}
}

void	init_2d(t_display *display, t_map *map, t_player *player)
{
	const int	height_ratio = display->height / (map->height + map->isles + 1);
	const int	width_ratio = display->width / (map->width + map->isles + 1);

	if (height_ratio > width_ratio)
		display->square_length = width_ratio;
	else
		display->square_length = height_ratio;
	show_display_info(display, map);
	draw_2d(display, map);
	player->x = player->x * display->square_length + display->square_length / 2;
	player->y = player->y * display->square_length + display->square_length / 2;
	draw_player(display, player);
	mlx_put_image_to_window(display->mlx, display->win, display->img, 0, 0);
}
