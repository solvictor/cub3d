#include "cub3d.h"

void	mark_visited(t_map *map, char **map_copy, int i, int j)
{
	const int	columns = map->width;
	const int	lines = map->height;

	if (i < 0 || i >= lines || j < 0 || j >= columns
		|| !ft_c_in_str(map_copy[i][j], FREE))
		return ;
	map_copy[i][j] = '1';
	mark_visited(map, map_copy, i - 1, j);
	mark_visited(map, map_copy, i + 1, j);
	mark_visited(map, map_copy, i, j - 1);
	mark_visited(map, map_copy, i, j + 1);
}

void	counter(t_map *map, char **map_copy, int i, int j)
{
	if (ft_c_in_str(map_copy[i][j], FREE))
	{
		map->islands++;
		mark_visited(map, map_copy, i, j);
	}
}	

bool	count_islands(t_map *map)
{
	char	**map_copy;	
	int		i;
	int		j;

	map_copy = ft_strsdup((const char **)map->map);
	if (!map_copy)
		return (false);
	i = 0;
	j = 0;
	while (i < map->height)
	{
		while (j < map->width)
		{
			counter(map, map_copy, i, j);
			++j;
		}
		j = 0;
		++i;
	}
	return (true);
}
