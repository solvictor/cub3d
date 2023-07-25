/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:25:20 by tgernez           #+#    #+#             */
/*   Updated: 2023/07/25 12:25:21 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	put_image(t_vars *vars)
{
	t_display	*display;

	display = vars->display;
	movement_selector(display, vars->camera, vars->map);
	if (display->refresh == false)
		return (1);
	caster(display, vars->map, vars->camera);
	minimap(display, vars->map, vars->camera);
	mlx_put_image_to_window(display->mlx, display->win, display->img, 0, 0);
	if (door(vars->map, vars->camera))
		mlx_string_put(display->mlx, display->win, display->width / 2.14,
			display->height / 3, 0xFFFFFF, INTERACTION_MESSAGE);
	vars->display->refresh = false;
	return (1);
}

bool	start_display(t_display *display, t_vars *vars)
{
	if (init_display(display) == false)
		return (false);
	if (!get_textures_walls(display, vars->map))
		return (false);
	init_position(vars->camera, vars->map->start_direction);
	mlx_hook(display->win, ON_DESTROY, NO_MASK, on_destroy, vars);
	mlx_hook(display->win, ON_KEYPRESS, KEYPRESS_MASK, on_keypress, vars);
	mlx_hook(display->win, ON_KEYRELEASE, KEYRELEASE_MASK, on_keyrelease, vars);
	mlx_hook(display->win, ON_MOUSEPRESS, MOUSEPRESS_MASK, on_mousepress, vars);
	mlx_hook(display->win, ON_MOUSERELEASE, MOUSERELEASE_MASK, on_mouserelease,
		vars);
	mlx_loop_hook(display->mlx, &put_image, vars);
	vars->display->refresh = true;
	put_image(vars);
	mlx_loop(display->mlx);
	return (true);
}
