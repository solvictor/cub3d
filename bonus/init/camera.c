/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:25:08 by tgernez           #+#    #+#             */
/*   Updated: 2023/08/02 17:57:34 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	set_to_zero_camera(t_vars *vars, t_camera *camera)
{
	set_vector(&camera->pos, 0, 0);
	set_vector(&camera->dir, -1, 0);
	set_vector(&camera->plane, 0, 0.80);
	camera->move_speed = 0.08;
	camera->rot_speed = 0.03;
	camera->w = false;
	camera->a = false;
	camera->s = false;
	camera->d = false;
	camera->r_key = false;
	camera->l_key = false;
	camera->angle = 0.0;
	vars->camera = camera;
}
