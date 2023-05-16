#include "cub3d.h"

void	move_player(t_display *display, t_player *player)
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
				mlx_spp(display, player->x - i, player->y - j, 0xFFFFFF);
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
	x = 0;
	while (j < display->width)
	{
		if (!map->map[y] || !map->map[y][x])
			break ;
		if (map->map[y] && ft_c_in_str(map->map[y][x], FREE))
			mlx_spp(display, j, i, 0xFF0000);
		else
			mlx_spp(display, j, i, 0x00FF00);
		if (j > x * display->square_length && x < map->width - 1)
			mlx_spp(display, j, i, 0);
		if (i > y * display->square_length && y < map->height - 1)
			mlx_spp(display, j, i, 0);
		if (j > x * display->square_length && x < map->width - 1)
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
	y = 0;
	while (i < display->height)
	{
		draw_2d_pixels(display, map, i, y);
		if (i > y * square_length && y < map->height - 1)
			++y;
		++i;
	}
}

void	init_2d(t_display *display, t_map *map, t_player *player)
{
	const int	height_ratio = display->height / map->height;
	const int	width_ratio = display->width / map->width;

	if (height_ratio > width_ratio)
		display->square_length = width_ratio;
	else
		display->square_length = height_ratio;
	show_display_info(display, map);
	draw_2d(display, map);
	player->x = player->x * display->square_length - display->square_length / 2;
	player->y = player->y * display->square_length - display->square_length / 2;
	mlx_put_image_to_window(display->mlx, display->win, display->img, 0, 0);
}
