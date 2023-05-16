#include "cub3d.h"

static void	count_vertical(t_map *map)
{
	(void) map;
}

static void	count_horizontal(t_map *map)
{
	(void) map;
}

void	count_islands(t_map *map)
{
	count_vertical(map);
	count_horizontal(map);
	return ;
}
