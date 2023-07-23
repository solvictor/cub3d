#include "cub3d_bonus.h"

static void	clean_map(t_map *map)
{
	printf("Clean Map got called\n");
	if (map->path_north)
		free(map->path_north);
	if (map->path_south)
		free(map->path_south);
	if (map->path_east)
		free(map->path_east);
	if (map->path_west)
		free(map->path_west);
	if (map->map)
		ft_free_strs(map->map);
	if (map->sprite_textures)
		free(map->sprite_textures);
	if (map->sprites)
		free(map->sprites);
}

static void	destroy_window(t_display *display)
{
	printf("Destroy Window got called\n");
	mlx_destroy_image(display->mlx, display->img);
	mlx_destroy_window(display->mlx, display->win);
	mlx_destroy_display(display->mlx);
	free(display->mlx);
}

void	destroy_images(t_display *display, t_map *map, const int ind)
{
	int	i;

	i = 1;
	printf("Destroy Images got called\n");
	mlx_destroy_image(display->mlx, map->textures[0].img);
	map->textures[0].img = NULL;
	while (i <= ind)
	{
		mlx_destroy_image(display->mlx, map->textures[i++].img);
	}
}

void	clean_memory(t_vars *vars)
{
	clean_map(vars->map);
	if (vars->map->textures[0].img != NULL)
		destroy_images(vars->display, vars->map, 4);
	if (vars->display->img)
		destroy_window(vars->display);
	ft_free_strs(vars->file_content);
}
