/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listeners.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:22:57 by tgernez           #+#    #+#             */
/*   Updated: 2023/07/25 12:22:58 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	return (1);
}
