#include "cub3d_bonus.h"

void	clean_memory(t_vars *vars)
{
	clean_map_variables(vars->map);
	clean_camera_variables(vars->camera);
	if (vars->map->textures[0].img != NULL)
		destroy_wall_images(vars->display, vars->map, 4);
	if (vars->map->sprite_textures)
		destroy_sprite_images(vars->display, vars->map,
			vars->map->total_sprite_textures);
	if (vars->display->img)
		destroy_window(vars->display);
	ft_free_strs(vars->file_content);
}
