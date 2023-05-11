#include "cub3d.h"

static bool	char_mid_map_valid(const char **map_content, unsigned int i,
	unsigned int j, t_map *map)
{
	// ft_printf("Treating Line %d\n", i);
	if (i == 0 || (int)i == map->heigth - 1)
		return (true);
	if (ft_strlen(map_content[i - 1]) > j)
		if (map_content[i - 1][j] == '\0'
			|| ft_c_in_str(map_content[i - 1][j], SPACES))
			return (false);
	if (ft_strlen(map_content[i + 1]) > j)
		if (map_content[i + 1][j] == '\0'
			|| ft_c_in_str(map_content[i + 1][j], SPACES))
			return (false);
	if (0 < j - 1)
		if (map_content[i][j - 1] == '\0'
			|| ft_c_in_str(map_content[i][j - 1], SPACES))
			return (false);
	if (ft_strlen(map_content[i]) >= j)
		if (map_content[i][j + 1] == '\0'
			|| ft_c_in_str(map_content[i][j + 1], SPACES))
			return (false);
	return (true);
}

bool	line_correct(const char **map_content, int i, t_map *map)
{
	const char		*line = map_content[i];
	const size_t	len = ft_strlen(line);
	int				j;

	if (i == 0 || i == map->heigth - 1)
		if (ft_strchr(line, '0') || ft_cset_in_str(PLAYER, (char *)line))
			return (error_str("Map not closed"), false);
	j = 0;
	while (line[j])
	{
		while (line[j] && !ft_c_in_str(line[j], FREE))
			++j;
		if (j == 0 && line[j])
			return (false);
		else if (j == (int)(len - 1) && line[j])
			return (false);
		else if (line[j] && char_mid_map_valid(map_content, i, j, map) == false)
			return (false);
		++j;
	}
	return (true);
}

// bool	find_coords_walls(int coords[2], t_vars *vars, t_map *map)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 2)
// 		return (false);
// 	return (true);
// }

bool	map_correct(t_map *map)
{
	const char	**map_content = (const char **)map->map;
	int			i;

	ft_printf("Map first line\n%s", map->map[0]);
	ft_printf("Map last line\n%s", map->map[map->heigth - 1]);
	i = 0;
	while (map_content[i])
	{
		if (line_correct(map_content, i, map) == false)
			return (ft_printf("Line %d is wrong:\n%s\n", i, (char *)map_content[i]), false);
		++i;
	}
	return (true);
}
