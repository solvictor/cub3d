#include "cub3d.h"

int	find_wall_distance_x(t_display *display, t_player *player, t_map *map)
{
	int	x;

	x = player->x;
	if ((player->direction >= 315 || player->direction < 45))
	{
		while (map->map[player->square_y][x / display->square_length] != '1')
			++x;
		return (x + 1);
	}
	while (map->map[player->square_y][x / display->square_length] != '1')
		--x;
	return (x);
}

int	find_wall_distance_y(t_display *display, t_player *player, t_map *map)
{
	int	y;

	y = player->y;
	if ((player->direction >= 45 && player->direction < 135))
	{
		while (map->map[y / display->square_length][player->square_x] != '1')
			++y;
		return (y + 1);
	}
	while (map->map[y / display->square_length][player->square_x] != '1')
		--y;
	return (y + 1);
}

void	draw_fov(t_display *display, t_player *player, t_map *map)
{
	t_point	player_pos;
	t_point	left_fov;
	// t_point	right_fov;

	ft_printf("Player direction %d\n", player->direction);
	left_fov.x = player->x;
	left_fov.y = player->y;
	if ((player->direction >= 315 || player->direction < 45)
		|| (player->direction >= 135 && player->direction < 225))
		left_fov.x = find_wall_distance_x(display, player, map);
	else
		left_fov.y = find_wall_distance_y(display, player, map);
	player_pos.x = player->x;
	player_pos.y = player->y;
	player_pos.color = 0x0000FF;
	left_fov.color = 0x0000FF;
	draw_line(display, player_pos, left_fov);

}

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

static void	draw_2d_pixels(t_display *display, t_map *map, int i, int y)
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
	const int	height_ratio = display->height
		/ (map->height + map->islands);
	const int	width_ratio = display->width
		/ (map->width + map->islands);

	if (height_ratio > width_ratio)
		display->square_length = width_ratio;
	else
		display->square_length = height_ratio;
	show_display_info(display, map);
	draw_2d(display, map);
	player->x = player->x * display->square_length + display->square_length / 2;
	player->y = player->y * display->square_length + display->square_length / 2;
	draw_fov(display, player, map);
	draw_player(display, player);
	mlx_put_image_to_window(display->mlx, display->win, display->img, 0, 0);
}
