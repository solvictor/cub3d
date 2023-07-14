#include "cub3d.h"

void	basic_up(t_vars *vars)
{
	t_camera	*camera;
	t_map		*map;
	int			index_x;
	int			index_y;

	vars->display->refresh = true;
	camera = vars->camera;
	map = vars->map;
	index_x = camera->pos.x + camera->dir.x * camera->move_speed;
	index_y = camera->pos.y + camera->dir.y * camera->move_speed;
	// if ((0 > index_x || map->height < index_x)
	// 	|| (0 > index_y || map->width < index_y))
	// 	return ;
	//TODO protect for index < 0 and index > bigger size map
	if (map->map[(int)camera->pos.y][index_x] == '0')
	{
		camera->pos.x += camera->dir.x * camera->move_speed;
	}
	if (map->map[index_y][(int)camera->pos.x] == '0')
	{
		camera->pos.y += camera->dir.y * camera->move_speed;
	}
}

void	basic_down(t_vars *vars)
{
	t_camera	*camera;
	t_map		*map;
	int			index_x;
	int			index_y;

	vars->display->refresh = true;
	camera = vars->camera;
	map = vars->map;
	index_x = camera->pos.x - camera->dir.x * camera->move_speed;
	index_y = camera->pos.y - camera->dir.y * camera->move_speed;
	// if ((0 > index_x || map->height < index_x)
	// 	|| (0 > index_y || map->width < index_y))
	// 	return ;
	//TODO protect for index < 0 and index > bigger size map
	if (map->map[(int)camera->pos.y][index_x] == '0')
	{
		camera->pos.x -= camera->dir.x * camera->move_speed;
	}
	if (map->map[index_y][(int)camera->pos.x] == '0')
	{
		camera->pos.y -= camera->dir.y * camera->move_speed;
	}
}

void	basic_left(t_vars *vars)
{
	const double	old_dir_x = vars->camera->dir.x;
	const double	old_plane_x = vars->camera->plane.x;
	t_camera		*camera;

	camera = vars->camera;
	vars->display->refresh = true;
	camera->dir.x = old_dir_x * cos(camera->rot_speed)
		- camera->dir.y * sin(camera->rot_speed);
	camera->dir.y = old_dir_x * sin(camera->rot_speed)
		+ camera->dir.y * cos(camera->rot_speed);
	camera->plane.x = old_plane_x * cos(camera->rot_speed)
		- camera->plane.y * sin(camera->rot_speed);
	camera->plane.y = old_plane_x * sin(camera->rot_speed)
		+ camera->plane.y * cos(camera->rot_speed);
}

void	basic_right(t_vars *vars)
{
	const double	old_dir_x = vars->camera->dir.x;
	const double	old_plane_x = vars->camera->plane.x;
	t_camera		*camera;


	camera = vars->camera;
	vars->display->refresh = true;
	camera->dir.x = old_dir_x * cos(-camera->rot_speed)
		- camera->dir.y * sin(-camera->rot_speed);
	camera->dir.y = old_dir_x * sin(-camera->rot_speed)
		+ camera->dir.y * cos(-camera->rot_speed);
	camera->plane.x = old_plane_x * cos(-camera->rot_speed)
		- camera->plane.y * sin(-camera->rot_speed);
	camera->plane.y = old_plane_x * sin(-camera->rot_speed)
		+ camera->plane.y * cos(-camera->rot_speed);
}
