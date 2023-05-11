#include "cub3d.h"

bool	create_map(t_vars *vars, t_map *map)
{
	int			i;
	int			j;
	size_t		len_line;
	const char	**content = (const char **)vars->file_content + map->first_line;

	i = 0;
	map->map = ft_calloc(map->heigth + 1, sizeof (char *));
	if (!map->map)
		return (perror("malloc"), false);
	while (content[i])
	{
		j = 0;
		len_line = ft_strlen(content[i]);
		map->map[i] = ft_calloc(map->length + 2, sizeof (char));
		if (!map->map[i])
			return (ft_free_strs(map->map), perror("malloc"), false);
		while (content[i][j])
		{
			map->map[i][j] = content[i][j];
			++j;
		}
		++i;
	}
	return (true);
}
