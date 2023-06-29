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

void	draw_2d(t_display *display, t_map *map)
{
	const int	square_length = display->square_length;
	int			i;
	int			j;

	i = 0;
	while (i < map->height * square_length)
	{
		j = 0;
		while (j < map->width * square_length)
		{
			if (ft_c_in_str(map->map[i / square_length][j / square_length],
				FREE))
				mlx_spp(display, j, i, 0xFFFFFF);
			else
				mlx_spp(display, j, i, 0x000000);
			if (j % square_length == 0 || i % square_length == 0)
				mlx_spp(display, j, i, 0);
			++j;
		}
		++i;
	}
}

void	init_2d(t_display *display, t_map *map, t_player *player,
		t_camera *camera)
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
	player->delta_x = cos(player->angle) * player->speed;
	player->delta_y = sin(player->angle) * player->speed;
	draw_player(display, player);
	caster(display, player, map, camera);
	mlx_put_image_to_window(display->mlx, display->win, display->img, 0, 0);
}
