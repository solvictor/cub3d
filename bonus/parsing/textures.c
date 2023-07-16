#include "cub3d.h"

bool	find_extra_parameter(t_map *map, t_vars *vars)
{
	int	i;
	int	tmp;

	tmp = map->param_lines[0];
	i = 0;
	while (++i < map->param_number)
		if (map->param_lines[i] >= tmp)
			tmp = map->param_lines[i];
	tmp += 1;
	while (vars->file_content[tmp])
	{
		i = 0;
		while (vars->file_content[tmp][i] && vars->file_content[tmp][i] != '\n')
		{
			if (!ft_c_in_str(vars->file_content[tmp][i], SPACES)
					&& !ft_c_in_str(vars->file_content[tmp][i], WALL_TYPES))
				if (!ft_c_in_str(vars->file_content[tmp][i], PLAYER))
					return (error_str("Wrong parameter in file"), false);
			++i;
		}
		++tmp;
	}
	return (true);
}

bool	do_textures_exist(t_map *map)
{
	int			tmp;

	tmp = open(map->path_north, R_OK);
	if (tmp == -1)
		return (error_str("Problem with north texture"), false);
	close(tmp);
	tmp = open(map->path_south, R_OK);
	if (tmp == -1)
		return (error_str("Problem with south texture"), false);
	close(tmp);
	tmp = open(map->path_west, R_OK);
	if (tmp == -1)
		return (error_str("Problem with west texture"), false);
	close(tmp);
	tmp = open(map->path_east, R_OK);
	if (tmp == -1)
		return (error_str("Problem with east texture"), false);
	close(tmp);
	return (true);
}