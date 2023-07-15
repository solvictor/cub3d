#include "cub3d.h"

unsigned int	get_color(t_map *map, int id, int texture_x, int texture_y)
{
	return (((unsigned int *)(map->textures[id].addr))
		[TEXTURE_WIDTH * texture_y + texture_x]);
}
