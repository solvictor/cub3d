#include "cub3d.h"

static bool	clean_map(t_map *map)
{
	int		last_line;
	int		i;
	char	**cleaned_map;

	i = 0;
	show_map(map);
	while (map->map[i])
		++i;
	while (!ft_cset_in_str(MAP_CHARS, map->map[i]))
		--i;
	last_line = i;
	cleaned_map = ft_calloc(i + 2, sizeof(char *));
	if (!cleaned_map)
		return (false);
	cleaned_map[i] = NULL;
	i = 0;
	while (i < last_line + 1)
	{
		cleaned_map[i] = ft_strdup(map->map[i]);
		if (!cleaned_map[i])
			return (ft_free_strs(cleaned_map), false);
		++i;
	}
	ft_free_strs(map->map);
	map->map = cleaned_map;
	return (true);
}

bool	create_map(t_vars *vars, t_map *map)
{
	int			i;
	int			j;
	size_t		len_line;
	const char	**content = (const char **)vars->file_content + map->first_line;

	i = 0;
	map->map = ft_calloc(map->heigth + 2, sizeof (char *));
	if (!map->map)
		return (perror("malloc"), false);
	while (content[i])
	{
		j = 0;
		len_line = ft_strlen(content[i]);
		map->map[i] = ft_calloc(map->width + 2, sizeof (char));
		if (!map->map[i])
			return (ft_free_strs(map->map), perror("malloc"), false);
		while (content[i][j])
		{
			map->map[i][j] = content[i][j];
			++j;
		}
		++i;
	}
	return (clean_map(map));
}
