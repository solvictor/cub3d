#include "cub3d_bonus.h"

static void	clean_map(t_map *map)
{
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
	if (map->sprites)
		free(map->sprites);
	if (map->str_sprite_textures)
		ft_free_strs(map->str_sprite_textures);
	if (map->path_door_closed)
		free(map->path_door_closed);
}

static void	destroy_window(t_display *display)
{
	mlx_destroy_image(display->mlx, display->img);
	mlx_destroy_window(display->mlx, display->win);
	mlx_destroy_display(display->mlx);
	free(display->mlx);
}

void	destroy_wall_images(t_display *display, t_map *map, const int ind)
{
	int	i;

	i = 1;
	mlx_destroy_image(display->mlx, map->textures[0].img);
	map->textures[0].img = NULL;
	while (i <= ind)
		mlx_destroy_image(display->mlx, map->textures[i++].img);
}

void	destroy_sprite_images(t_display *display, t_map *map, const int ind)
{
	int	i;

	i = 0;
	while (i < ind)
	{
		mlx_destroy_image(display->mlx, map->sprite_textures[i].img);
		++i;
	}
	free(map->sprite_textures);
	map->sprite_textures = NULL;	
}

void	clean_memory(t_vars *vars)
{
	clean_map(vars->map);
	if (vars->map->textures[0].img != NULL)
		destroy_wall_images(vars->display, vars->map, 4);
	if (vars->map->sprite_textures)
		destroy_sprite_images(vars->display, vars->map,
			vars->map->total_sprite_textures);
	if (vars->display->img)
		destroy_window(vars->display);
	ft_free_strs(vars->file_content);
}
