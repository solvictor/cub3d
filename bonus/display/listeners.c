/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listeners.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:25:17 by tgernez           #+#    #+#             */
/*   Updated: 2023/08/02 17:56:45 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	on_keypress(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		return (clean_memory(vars), exit(EXIT_SUCCESS), 1);
	if (keycode == XK_w)
		vars->camera->w = true;
	if (keycode == XK_a)
		vars->camera->a = true;
	if (keycode == XK_s)
		vars->camera->s = true;
	if (keycode == XK_d)
		vars->camera->d = true;
	if (keycode == XK_e)
		door_action(vars->display, vars->map, vars->camera);
	if (keycode == XK_Left)
		vars->camera->l_key = true;
	if (keycode == XK_Right)
		vars->camera->r_key = true;
	return (1);
}

int	on_keyrelease(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		return (clean_memory(vars), exit(EXIT_SUCCESS), 1);
	if (keycode == XK_w)
		vars->camera->w = false;
	if (keycode == XK_a)
		vars->camera->a = false;
	if (keycode == XK_s)
		vars->camera->s = false;
	if (keycode == XK_d)
		vars->camera->d = false;
	if (keycode == XK_Left)
		vars->camera->l_key = false;
	if (keycode == XK_Right)
		vars->camera->r_key = false;
	return (1);
}

int	on_mousepress(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (button == 1)
		vars->camera->a = true;
	if (button == 3)
		vars->camera->d = true;
	return (1);
}

int	on_mouserelease(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (button == 1)
		vars->camera->a = false;
	if (button == 3)
		vars->camera->d = false;
	return (1);
}
