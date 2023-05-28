#include "cub3d.h"

void	draw_fov(t_display *display, t_player *player, t_map *map)
{
	t_point	p1;
	t_point	p2;

	(void)map;
	p1.x = player->x;
	p1.y = player->y;
	p1.color = 0xFF0000;
	// p2.x = p1.x + player->delta_x;
	// p2.y = p2.y + player->delta_y;
	// p2.color = 0xFF0000;
	p2.x = player->x + round((cos(player->angle) * player->speed) * 5);
	p2.y = player->y + round((sin(player->angle) * player->speed) * 5);
	p2.color = 0xFF0000;
	// ft_printf("P1 X %d /P1 X\nP1 Y %d /P1 Y\n", p1.x, p1.y);
	// ft_printf("P2 X %d /P2 X\nP2 Y %d /P2 Y\n", p2.x, p2.y);
	//FIXME NOT PERFECT BUT TEMPORARY
	draw_line(display, p1, p2);
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
