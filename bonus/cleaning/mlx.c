#include "cub3d_bonus.h"
 
void	destroy_window(t_display *display)
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