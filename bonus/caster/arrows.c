/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:21:43 by tgernez           #+#    #+#             */
/*   Updated: 2023/08/02 18:08:48 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	l_key(t_display *display, t_camera *camera)
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
	camera->angle += camera->rot_speed;
	if (camera->angle > 2 * PI)
		camera->angle = 0;
}

void	r_key(t_display *display, t_camera *camera)
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
	camera->angle -= camera->rot_speed;
	if (camera->angle < 0)
		camera->angle = 2 * PI;
}
