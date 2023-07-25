#include "cub3d_bonus.h"

static void	start_angle(t_camera *camera, char start_dir)
{
	if (start_dir == 'W')
		camera->angle = 0;
	else if (start_dir == 'N')
		camera->angle = 3 * PI / 2;
	else if (start_dir == 'S')
		camera->angle = PI / 2;
	else
		camera->angle = PI;
}

void	init_position(t_camera *camera, char start_dir)
{
	const double	old_dir_x = camera->dir.x;
	const double	old_plane_x = camera->plane.x;
	double			to_add;

	if (start_dir == 'W')
		to_add = 0;
	else if (start_dir == 'N')
		to_add = 3 * PI / 2;
	else if (start_dir == 'S')
		to_add = PI / 2;
	else
		to_add = PI;
	camera->dir.x = old_dir_x * cos(-to_add)
		- camera->dir.y * sin(-to_add);
	camera->dir.y = old_dir_x * sin(-to_add)
		+ camera->dir.y * cos(-to_add);
	camera->plane.x = old_plane_x * cos(-to_add)
		- camera->plane.y * sin(-to_add);
	camera->plane.y = old_plane_x * sin(-to_add)
		+ camera->plane.y * cos(-to_add);
	start_angle(camera, start_dir);
}

bool	init_sprites_requirements(t_camera *camera, t_map *map,
	t_display *display)
{
	camera->z_buffer = ft_calloc(sizeof(double), display->width);
	if (!camera->z_buffer)
		return (perror("malloc"), false);
	camera->sprite_order = ft_calloc(sizeof(int), map->total_sprites);
	if (!camera->sprite_order)
		return (perror("malloc"), false);
	camera->sprite_distance = ft_calloc(sizeof(double), map->total_sprites);
	if (!camera->sprite_distance)
		return (perror("malloc"), false);
	return (true);
}

void	set_to_zero_camera(t_vars *vars, t_camera *camera)
{
	set_vector(&camera->pos, 0, 0);
	set_vector(&camera->dir, -1, 0);
	set_vector(&camera->plane, 0, 0.66);
	camera->move_speed = 0.08;
	camera->rot_speed = 0.03;
	camera->w = false;
	camera->a = false;
	camera->s = false;
	camera->d = false;
	camera->angle = 0.0;
	camera->z_buffer = NULL;
	camera->sprite_order = NULL;
	camera->sprite_distance = NULL;
	vars->camera = camera;
}
