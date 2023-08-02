/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:22:40 by tgernez           #+#    #+#             */
/*   Updated: 2023/08/02 17:55:40 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static void	basic_left(t_display *display, t_camera *camera, t_map *map)
{
	double		new_x;
	double		new_y;

	display->refresh = true;
	new_x = camera->pos.x + camera->dir.y * camera->move_speed;
	new_y = camera->pos.y - camera->dir.x * camera->move_speed;
	if (new_y > 1 && new_y <= map->height - 1)
		camera->pos.y = new_y;
	if (new_x > 1 && new_x <= map->width - 1)
		camera->pos.x = new_x;
}

static void	basic_right(t_display *display, t_camera *camera, t_map *map)
{
	double		new_x;
	double		new_y;

	display->refresh = true;
	new_x = camera->pos.x - camera->dir.y * camera->move_speed;
	new_y = camera->pos.y + camera->dir.x * camera->move_speed;
	if (new_y > 1 && new_y <= map->height - 1)
		camera->pos.y = new_y;
	if (new_x > 1 && new_x <= map->width - 1)
		camera->pos.x = new_x;
}

void	movement_selector(t_display *display, t_camera *camera, t_map *map)
{
	if (camera->w == true)
		basic_up(display, camera, map);
	if (camera->a == true)
		basic_left(display, camera, map);
	if (camera->s == true)
		basic_down(display, camera, map);
	if (camera->d == true)
		basic_right(display, camera, map);
	if (camera->r_key == true)
		r_key(display, camera);
	if (camera->l_key == true)
		l_key(display, camera);
}
