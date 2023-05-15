#include "cub3d.h"


void	move_player(t_display *display, t_player *player)
{
	mlx_spp(display, player->x, player->y, 0xFFFFFF);
	mlx_spp(display, player->x - 1, player->y, 0xFFFFFF);
	mlx_spp(display, player->x + 1, player->y, 0xFFFFFF);
	mlx_spp(display, player->x, player->y - 1, 0xFFFFFF);
	mlx_spp(display, player->x, player->y + 1, 0xFFFFFF);
}

void	draw_2d(t_display *display, t_map *map, t_player *player)
{
	const int	square_length = biggest(display->height, display->width)
		/ biggest(map->height, map->width);
	int			i;
	int			j;
	int			x;
	int			y;

	i = 0;
	y = 0;
	(void)player;
	// ft_printf("Display Heigth %d\n", display->height);
	// ft_printf("Display Width %d\n", display->width);
	// ft_printf("Line %s /Line\n", map->map[map->height - 1]);
	// ft_printf("Square Length %d /Square Length\n", square_length);
	while (i < display->height)
	{
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
			if (j > x * square_length && x < map->width - 1)
				mlx_spp(display, j, i, 0);
			if (i > y * square_length && y < map->height - 1)
				mlx_spp(display, j, i, 0);
			if (j > x * square_length && x < map->width - 1)
				++x;
			++j;
		}
		if (i > y * square_length && y < map->height - 1)
			++y;
		++i;
	}
	// mlx_put_image_to_window(display->mlx, display->win, display->img, 0, 0);
}

void	init_2d(t_display *display, t_map *map, t_player *player)
{
	const int	square_length = biggest(display->height, display->width)
		/ biggest(map->height, map->width);

	display->square_length = biggest(display->height, display->width)
		/ biggest(map->height, map->width);
	draw_2d(display, map, player);
	player->x = player->x * square_length - square_length / 2;
	player->y = player->y * square_length - square_length / 2;
	mlx_spp(display, player->x, player->y, 0xFFFFFF);
	mlx_spp(display, player->x - 1, player->y, 0xFFFFFF);
	mlx_spp(display, player->x + 1, player->y, 0xFFFFFF);
	mlx_spp(display, player->x, player->y - 1, 0xFFFFFF);
	mlx_spp(display, player->x, player->y + 1, 0xFFFFFF);
	mlx_put_image_to_window(display->mlx, display->win, display->img, 0, 0);
}