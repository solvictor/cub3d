#include "cub3d.h"

void	show_file(t_vars *vars)
{
	const char	**map_file = (const char **) vars->file_content;
	int			i;

	i = 0;
	ft_printf("========================Start file==========================\n");
	while (map_file[i])
		ft_printf("%s", map_file[i++]);
	ft_printf("=========================End file===========================\n");
}

void	show_texture_info(t_map *map)
{
	ft_printf("Texture NO %s\n", map->path_north);
	ft_printf("Texture SO %s\n", map->path_south);
	ft_printf("Texture EA %s\n", map->path_east);
	ft_printf("Texture WE %s\n", map->path_west);
	ft_printf("Texture Floor %d %d %d\n", map->floor_color[0],
		map->floor_color[1], map->floor_color[2]);
	ft_printf("Texture Ceiling %d %d %d\n", map->ceiling_color[0],
		map->ceiling_color[1], map->ceiling_color[2]);
}

void	show_map_info(t_map *map)
{
	ft_printf("Map height %d\n", map->height);
	ft_printf("Map width %d\n", map->width);
	ft_printf("Start x %d\nStart y %d\n", map->start_coords[0],
		map->start_coords[1]);
	ft_printf("Start Direction %c\n", map->start_direction);
}

void	show_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map || !map->map)
		return ;
	ft_printf("========================Start Map==========================\n");
	while (map->map[i])
		ft_printf("%s", map->map[i++]);
	ft_printf("=========================End Map===========================\n");
}
