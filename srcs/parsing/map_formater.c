#include "cub3d.h"

void	format_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	if (!map)
		return ;
	while (map->map[i])
	{
		j = 0;
		ft_printf("Len Line  %d /Len Line\n", ft_strlen(map->map[i]));
		while (map->map[i][j])
		{
			if (map->map[i][j] == ' ')
				map->map[i][j] = 1;
			++j;
		}
		++i;
	}
	show_map(map);
}