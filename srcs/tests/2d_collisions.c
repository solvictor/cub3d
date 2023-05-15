#include "cub3d.h"

bool	does_collide(int direction,
		t_map *map, t_player *player, t_display *display)
{
	int	x;
	int	y;

	if (direction == UP || direction == DOWN)
	{
		x = player->x / display->square_length;
		if (direction == UP)
			y = (player->y - 1 * player->speed + CURSOR_RADIUS)
				/ display->square_length;
		else
			y = (player->y + 1 * player->speed + CURSOR_RADIUS)
				/ display->square_length;
		return (map->map[y + 1][x + 1] == '1');
	}
	y = player->y / display->square_length;
	if (direction == LEFT)
		x = (player->x - 1 * player->speed + CURSOR_RADIUS)
			/ display->square_length;
	else
		x = (player->x + 1 * player->speed + CURSOR_RADIUS)
			/ display->square_length;
	return (map->map[y + 1][x + 1] == '1');
}

bool	colliding(int direction,
		t_map *map, t_player *player, t_display *display)
{
	const bool	collide = does_collide(direction, map, player, display);

	if (!collide)
		return (false);
	if (direction == UP)
		player->y = (player->y / display->square_length - 1)
			* display->square_length + CURSOR_RADIUS;
	else if (direction == DOWN)
		player->y = (player->y / display->square_length + 1)
			* display->square_length - CURSOR_RADIUS;
	else if (direction == LEFT)
		player->x = (player->x / display->square_length - 1) //FIXME goes out of boundaries
			* display->square_length + CURSOR_RADIUS;
	else if (direction == RIGHT)
		player->x = (player->x / display->square_length + 1)
			* display->square_length - CURSOR_RADIUS;
	return (true);
}
