#include "cub3d.h"

static bool	check_parameters(t_vars *vars)
{
	const char	ids[6][3] = {"NO", "SO", "WE", "EA", "F", "C"};
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (vars->file_content[i] && j < 6)
	{
		if (!is_line_empty(vars->file_content[i]))
		{
			if (ft_strncmp(vars->file_content[i], (char *)ids[j],
					ft_strlen(ids[j])))
				return (error_str("Wrong parameter in map"), false);
			++j;
		}
		++i;
	}
	return (true);
}

/*
	File opener
	Fills vars->file_content with the content of the map file.
	Returns true on success and false if error
*/
bool	file_opener(char *file_name, t_vars *vars)
{
	int		fd;
	int		i;
	int		lines;
	char	buff[1];
	char	**content;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (error_str("Couldn't find the file"), perror("open"), false);
	lines = 1;
	while (read(fd, buff, 1))
		lines += (buff[0] == '\n' || buff[0] == '\0');
	close(fd);
	content = malloc(sizeof (char *) * (lines + 1));
	if (!content)
		return (perror("malloc"), false);
	content[lines] = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_free_strs(content), perror("open"), false);
	i = 0;
	while (i < lines)
		content[i++] = get_next_line(fd);
	vars->file_content = content;
	return (close(fd), true);
}

bool	parsing(char *file_name, t_vars *vars, t_map *map)
{
	if (ft_strncmp(".cub", file_name + ft_strlen(file_name) - 4, 4) != 0)
		return (error_str("Wrong file format"), false);
	if (file_opener(file_name, vars) == false)
		return (false);
	if (check_parameters(vars) == false)
		return (false);
	show_file(vars);
	if (get_textures_info(vars, map) == false)
		return (false);
	show_texture_info(map);
	if (do_textures_exist(map) == false)
		return (false);
	if (map_size(vars, map) == false)
		return (false);
	show_map_info(map);
	if (create_map(vars, map) == false)
		return (false);
	if (map_correct(map) == false)
		return (false);
	format_map(map);
	show_map(map);
	set_vector(&vars->camera->pos, map->start_coords[0], map->start_coords[1]);
	return (true);
}
