/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:25:06 by tgernez           #+#    #+#             */
/*   Updated: 2023/07/25 12:25:07 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	init_display(t_display *display)
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

void	set_to_zero_display(t_vars *vars, t_display *display)
{
	display->mlx = NULL;
	display->win = NULL;
	display->img = NULL;
	display->addr = NULL;
	display->height = -1;
	display->width = -1;
	display->bpp = -1;
	display->size_line = -1;
	display->endian = -1;
	display->refresh = false;
	display->minimap_colors[0] = 0xFFFFFF;
	display->minimap_colors[1] = 0xFF0000;
	display->minimap_colors[2] = 0xF07470;
	display->minimap_colors[3] = 0xF6BDC0;
	vars->display = display;
}
