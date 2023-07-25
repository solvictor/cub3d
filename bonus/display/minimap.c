/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:25:15 by tgernez           #+#    #+#             */
/*   Updated: 2023/07/25 12:25:16 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_tile(t_display *display, int x, int y, int color)
{
	int		dx;
	int		dy;

	dx = 0;
	while (dx < TILE_SIZE)
	{
		dy = 0;
		while (dy < TILE_SIZE)
		{
			mlx_spp(display, x * TILE_SIZE + dx, y * TILE_SIZE + dy, color);
			++dy;
		}
		++dx;
	}
}

void	draw_player(t_display *display, t_camera *camera, int color)
{
	int		cx;
	int		cy;
	int		r_squared;
	int		x;
	int		y;

	cx = (int)(camera->pos.x * TILE_SIZE);
	cy = (int)(camera->pos.y * TILE_SIZE);
	r_squared = PLAYER_RADIUS * PLAYER_RADIUS;
	x = cx - PLAYER_RADIUS - 1;
	while (++x <= cx + PLAYER_RADIUS)
	{
		y = cy - PLAYER_RADIUS - 1;
		while (++y <= cy + PLAYER_RADIUS)
			if ((x - cx) * (x - cx) + (y - cy) * (y - cy) <= r_squared)
				mlx_spp(display, x, y, color);
	}
}

void	minimap(t_display *display, t_map *map, t_camera *camera)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == '0')
				draw_tile(display, j, i, display->minimap_colors[0]);
			else if (map->map[i][j] == '2')
				draw_tile(display, j, i, display->minimap_colors[2]);
			else if (map->map[i][j] == '3')
				draw_tile(display, j, i, display->minimap_colors[3]);
			++j;
		}
		++i;
	}
	draw_player(display, camera, display->minimap_colors[1]);
}
