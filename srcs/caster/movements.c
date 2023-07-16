#include "cub3d.h"

/*
	TODO deactivate collisions for mandatory
*/

// void	basic_up(t_display *display, t_camera *camera)
// {
// 	t_camera	*camera;
// 	t_map		*map;
// 	int			index_x;
// 	int			index_y;

// 	display->refresh = true;
// 	camera = camera;
// 	map = map;
// 	index_x = camera->pos.x + camera->dir.x * camera->move_speed;
// 	index_y = camera->pos.y + camera->dir.y * camera->move_speed;
// 	if (map->map[(int)camera->pos.y][index_x] == '0')
// 	{
// 		camera->pos.x += camera->dir.x * camera->move_speed;
// 	}
// 	if (map->map[index_y][(int)camera->pos.x] == '0')
// 	{
// 		camera->pos.y += camera->dir.y * camera->move_speed;
// 	}
// }

// void	basic_down(t_display *display, t_camera *camera)
// {
// 	t_map		*map;
// 	int			index_x;
// 	int			index_y;

// 	display->refresh = true;
// 	map = map;
// 	index_x = camera->pos.x - camera->dir.x * camera->move_speed;
// 	index_y = camera->pos.y - camera->dir.y * camera->move_speed;
// 	if (map->map[(int)camera->pos.y][index_x] == '0')
// 	{
// 		camera->pos.x -= camera->dir.x * camera->move_speed;
// 	}
// 	if (map->map[index_y][(int)camera->pos.x] == '0')
// 	{
// 		camera->pos.y -= camera->dir.y * camera->move_speed;
// 	}
// }

// TODO remove, only for bonuses

static void	basic_up(t_display *display, t_camera *camera, t_map *map)
{
	int			index_x;
	int			index_y;

	display->refresh = true;

	index_x = camera->pos.x + camera->dir.x * camera->move_speed;
	index_y = camera->pos.y + camera->dir.y * camera->move_speed;
	if (!((int)camera->pos.y <= 0 || index_x <= 0
			|| camera->pos.y >= map->height - 1
			|| index_x >= map->width - 1))
		camera->pos.x += camera->dir.x * camera->move_speed;
	if (!(index_y <= 0 || (int)camera->pos.x <= 0
			|| index_y >= map->height - 1
			|| (int)camera->pos.x >= map->width - 1))
		camera->pos.y += camera->dir.y * camera->move_speed;
}

static void	basic_down(t_display *display, t_camera *camera, t_map *map)
{
	int			index_x;
	int			index_y;

	display->refresh = true;
	index_x = camera->pos.x - camera->dir.x * camera->move_speed;
	index_y = camera->pos.y - camera->dir.y * camera->move_speed;
	if (!((int)camera->pos.y <= 0 || index_x <= 0
			|| camera->pos.y >= map->height - 1
			|| index_x >= map->width - 1))
		camera->pos.x -= camera->dir.x * camera->move_speed;
	if (!(index_y <= 0 || (int)camera->pos.x <= 0
			|| index_y >= map->height - 1
			|| (int)camera->pos.x >= map->width - 1))
		camera->pos.y -= camera->dir.y * camera->move_speed;
}

static void	basic_left(t_display *display, t_camera *camera)
{
	const double	old_dir_x = camera->dir.x;
	const double	old_plane_x = camera->plane.x;

	display->refresh = true;
	camera->dir.x = old_dir_x * cos(-camera->rot_speed)
		- camera->dir.y * sin(-camera->rot_speed);
	camera->dir.y = old_dir_x * sin(-camera->rot_speed)
		+ camera->dir.y * cos(-camera->rot_speed);
	camera->plane.x = old_plane_x * cos(-camera->rot_speed)
		- camera->plane.y * sin(-camera->rot_speed);
	camera->plane.y = old_plane_x * sin(-camera->rot_speed)
		+ camera->plane.y * cos(-camera->rot_speed);
}


static void	basic_right(t_display *display, t_camera *camera)
{
	const double	old_dir_x = camera->dir.x;
	const double	old_plane_x = camera->plane.x;

	display->refresh = true;
	camera->dir.x = old_dir_x * cos(camera->rot_speed)
		- camera->dir.y * sin(camera->rot_speed);
	camera->dir.y = old_dir_x * sin(camera->rot_speed)
		+ camera->dir.y * cos(camera->rot_speed);
	camera->plane.x = old_plane_x * cos(camera->rot_speed)
		- camera->plane.y * sin(camera->rot_speed);
	camera->plane.y = old_plane_x * sin(camera->rot_speed)
		+ camera->plane.y * cos(camera->rot_speed);
}

void	movement_selector(t_display *display, t_camera *camera, t_map *map)
{
	if (camera->w == true)
		basic_up(display, camera, map);
	if (camera->a == true)
		basic_left(display, camera);
	if (camera->s == true)
		basic_down(display, camera, map);
	if (camera->d == true)
		basic_right(display, camera);
}
