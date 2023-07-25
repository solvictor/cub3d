/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caster.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:22:37 by tgernez           #+#    #+#             */
/*   Updated: 2023/07/25 12:22:38 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_caster(t_display *display, t_camera *camera, int x)
{
	camera->camera_x = -(2 * x / (double)display->width - 1);
	set_vector(&camera->ray_dir,
		camera->dir.x + camera->plane.x * camera->camera_x,
		camera->dir.y + camera->plane.y * camera->camera_x);
	camera->map_x = (int)camera->pos.x;
	camera->map_y = (int)camera->pos.y;
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
}

static void	camera_step(t_camera *camera)
{
	if (camera->ray_dir.x < 0)
	{
		camera->step_x = -1;
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
}

static void	hit_detection(t_camera *camera, t_map *map,
	int *hit)
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
	if (camera->map_y >= map->height || camera->map_x >= map->width
		|| camera->map_y < 0 || camera->map_x < 0
		|| map->map[camera->map_y][camera->map_x] == '1')
		*hit = 1;
}

void	caster(t_display *display, t_map *map, t_camera *camera)
{
	int	x;
	int	hit;

	x = 0;
	while (x < display->width)
	{
		init_caster(display, camera, x);
		camera_step(camera);
		hit = 0;
		while (hit == 0)
			hit_detection(camera, map, &hit);
		if (camera->side == 0)
			camera->perp_wall_dist = camera->side_dist.x - camera->delta_dist.x;
		else
			camera->perp_wall_dist = camera->side_dist.y - camera->delta_dist.y;
		if (camera->perp_wall_dist == 0)
			camera->perp_wall_dist = 1;
		draw_3d_walls(display, map, camera, x);
		++x;
	}
}
