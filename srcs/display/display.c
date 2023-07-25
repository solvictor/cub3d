/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:22:55 by tgernez           #+#    #+#             */
/*   Updated: 2023/07/25 12:22:56 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	init(t_display *display)
{
	display->mlx = mlx_init();
	mlx_get_screen_size(display->mlx, &display->width, &display->height);
	display->win = mlx_new_window(display->mlx, display->width,
			display->height, "Cub3d ouuuuuuuuuuuu");
	display->img = mlx_new_image(display->mlx, display->width, display->height);
	display->addr = mlx_get_data_addr(display->img, &display->bpp,
			&display->size_line, &display->endian);
	if (!display->mlx || !display->win || !display->win || !display->addr)
		return (error_str("Fail in MLX"), false);
	return (true);
}

static void	init_position(t_camera *camera, char start_dir)
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
}

int	put_image(t_vars *vars)
{
	movement_selector(vars->display, vars->camera, vars->map);
	if (vars->display->refresh == false)
		return (1);
	caster(vars->display, vars->map, vars->camera);
	mlx_put_image_to_window(vars->display->mlx, vars->display->win,
		vars->display->img, 0, 0);
	vars->display->refresh = false;
	return (1);
}

bool	start_display(t_display *display, t_vars *vars)
{
	if (init(display) == false)
		return (false);
	init_position(vars->camera, vars->map->start_direction);
	mlx_hook(display->win, ON_DESTROY, NO_MASK, on_destroy, vars);
	mlx_hook(display->win, ON_KEYPRESS, KEYPRESS_MASK, on_keypress, vars);
	mlx_hook(display->win, ON_KEYRELEASE, KEYRELEASE_MASK, on_keyrelease, vars);
	mlx_loop_hook(display->mlx, &put_image, vars);
	get_textures(display, vars->map);
	vars->display->refresh = true;
	put_image(vars);
	mlx_loop(display->mlx);
	return (true);
}
