#include "cub3d.h"

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
		return (perror("open"), false);
	lines = 0;
	while (read(fd, buff, 1))
		lines += buff[0] == '\n';
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
		return (error_str("Wrong file extension"), false);
	if (file_opener(file_name, vars) == false)
		return (false);
	int i = 0;
	const char **map_file = (const char **) vars->file_content;

	ft_printf("========================Start file==========================\n");
	while (map_file[i])
		printf("%s", map_file[i++]);
	ft_printf("=========================End file===========================\n");
	if (get_textures_info(vars, map) == false)
		return (false);
	ft_printf("After NO %s\n", map->path_north);
	ft_printf("After SO %s\n", map->path_south);
	ft_printf("After EA %s\n", map->path_east);
	ft_printf("After WE %s\n", map->path_west);
	ft_printf("After Floor %d %d %d\n", map->floor_color[0], map->floor_color[1], map->floor_color[2]);
	ft_printf("After Ceiling %d %d %d\n", map->ceiling_color[0], map->ceiling_color[1], map->ceiling_color[2]);
	if (map_size(vars, map) == false)
		return (false);
	ft_printf("Map heigth %d\n", map->heigth);
	ft_printf("Map length %d\n", map->length);
	ft_printf("Start x %d\nStart y %d\n", map->start_coords[0], map->start_coords[1]);
	ft_printf("Start Direction %c\n", map->start_direction);

	// if (map_correct(vars, map) == false)
	// 	return (false);
	if (create_map(vars, map) == false)
		return (false);
	i = 0;
	ft_printf("========================Start Map==========================\n");
	while (map->map[i])
		printf("%s", map->map[i++]);
	ft_printf("=========================End Map===========================\n");
	if (map_correct(map) == false)
		return (false);
	return (true);
}
