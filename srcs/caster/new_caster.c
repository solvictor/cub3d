#include "cub3d.h"

void	draw_3d_walls(t_display *display, t_camera *camera, int x)
{
	const int	line_height = (int)(display->height / camera->perp_wall_dist) * 1;
	int			draw_start;
	int			draw_end;
	int			color;

	printf("display->height: %f\n", display->height);
	printf("camera->perp_wall_dist: %f\n", camera->perp_wall_dist);
	printf("Line Height: %f\n", line_height);
	draw_start = -line_height / 2 + display->height / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + display->height / 2;
	if (draw_end >= display->height)
		draw_end = display->height - 1;
	color = 0xFF0000;
	if (camera->side == 1)
		color /= 2;
	while (draw_start <= draw_end)
	{
		mlx_spp(display, x, draw_start, color);
		++draw_start;
	}
}

void	caster(t_display *display, t_player *player, t_map *map,
	t_camera *camera)
{
	int	x;
	int	hit;

	x = 0;
	set_vector(&camera->pos, player->x, player->y);
	clear_image(display);
	while (x < display->width)
	{
		// ft_printf("Start X: %d\n", x);
		camera->camera_x = 2 * x / (double)display->width - 1;
		set_vector(&camera->ray_dir,
			camera->dir.x + camera->plane.x * camera->camera_x,
			camera->dir.y + camera->plane.y * camera->camera_x);
		camera->map_x = (int)camera->pos.x;
		camera->map_y = (int)camera->pos.y;
	printf("hey\n");
		if (camera->map_x >= map->width || camera->map_y >= map->height
			|| camera->map_x < 0 || camera->map_y < 0)
			return ;
		if (camera->ray_dir.x == 0 && camera->ray_dir.y == 0)
			set_vector(&camera->delta_dist, DBL_MAX, DBL_MAX);
		else if (camera->ray_dir.x == 0 && camera->ray_dir.y != 0)
			set_vector(&camera->delta_dist, DBL_MAX,
				fabs(1 / camera->ray_dir.y));
		else if (camera->ray_dir.x != 0 && camera->ray_dir.y == 0)
			set_vector(&camera->delta_dist, fabs(1 / camera->ray_dir.x),
				DBL_MAX);
		else
			set_vector(&camera->delta_dist, fabs(1 / camera->ray_dir.x),
				fabs(1 / camera->ray_dir.y));
		ft_printf("Segfault test============================\n");
		hit = 0;
		if (camera->ray_dir.x < 0)
		{
			camera->step_x = -1; // MAybe put the steps as local variables
			camera->side_dist.x = (camera->pos.x - camera->map_x)
				* camera->delta_dist.x;
		}
		else
		{
			camera->step_x = 1;
			camera->side_dist.x = (camera->map_x + 1.0 - camera->pos.x)
				* camera->delta_dist.x;
		}
		if (camera->ray_dir.y < 0)
		{
			camera->step_y = -1;
			camera->side_dist.y = (camera->pos.y - camera->map_y)
				* camera->delta_dist.y;
		}
		else
		{
			camera->step_y = 1;
			camera->side_dist.y = (camera->map_y + 1.0 - camera->pos.y)
				* camera->delta_dist.y;
		}
		// ft_printf("End X: %d\n", x);
		while (hit == 0)
		{
			if (camera->side_dist.x < camera->side_dist.y)
			{
				camera->side_dist.x += camera->delta_dist.x;
				camera->map_x += camera->step_x;
				camera->side = 0;
			}
			else
			{
				camera->side_dist.y += camera->delta_dist.y;
				camera->map_y += camera->step_y;
				camera->side = 1;
			}
			// ft_printf("Map Y / Map X: %d/%d\n", camera->map_x, camera->map_y);
			if (map->map[camera->map_y][camera->map_x] == '1')
				hit = 1;

		}
		// ft_printf("camera side dist x / camera delta dist x: %d / %d\n", camera->side_dist.x, camera->delta_dist.x);
		if (camera->side == 0)
			camera->perp_wall_dist = camera->side_dist.x - camera->delta_dist.x;
		else
			camera->perp_wall_dist = camera->side_dist.y - camera->delta_dist.y;
		if (camera->perp_wall_dist == 0)
			camera->perp_wall_dist = 1;
		draw_3d_walls(display, camera, x);
		++x;
	}
	// mlx_put_image_to_window(display->mlx, display->win, display->img, 0, 0);
}

