/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:22:45 by tgernez           #+#    #+#             */
/*   Updated: 2023/07/25 12:22:46 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	mlx_spp(t_display *display, int x, int y, int color)
{
	char	*dst;

	dst = display->addr + (y * display->size_line + x * (display->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	initialize_column(t_display *display, t_column *column,
		t_camera *camera, const int line_height)
{
	column->draw_start = -line_height / 2 + display->height / 2;
	if (column->draw_start < 0)
		column->draw_start = 0;
	column->draw_end = line_height / 2 + display->height / 2;
	if (column->draw_end >= display->height)
		column->draw_end = display->height - 1;
	column->texture_number = select_texture(camera);
	if (camera->side == 0)
		column->wall_x = camera->pos.y + camera->perp_wall_dist
			* camera->ray_dir.y;
	else
		column->wall_x = camera->pos.x + camera->perp_wall_dist
			* camera->ray_dir.x;
	column->wall_x -= floor((column->wall_x));
	column->texture_x = (int)(column->wall_x * (double)TEXTURE_WIDTH);
	if (camera->side == 0 && camera->ray_dir.x > 0)
		column->texture_x = TEXTURE_WIDTH - column->texture_x - 1;
	if (camera->side == 1 && camera->ray_dir.y < 0)
		column->texture_x = TEXTURE_WIDTH - column->texture_x - 1;
	column->step = 1.0 * TEXTURE_HEIGHT / line_height;
	column->texture_pos = (column->draw_start - display->height
			/ 2 + line_height / 2) * column->step;
}

void	draw_3d_walls(t_display *display, t_map *map, t_camera *camera, int x)
{
	const int		line_height = (int)(display->height
			/ camera->perp_wall_dist);
	int				y;
	t_column		column;

	initialize_column(display, &column, camera, line_height);
	y = 0;
	while (y < column.draw_start)
		mlx_spp(display, x, y++, map->ceiling_color);
	y = column.draw_start;
	while (y < column.draw_end)
	{
		column.texture_y = (int)column.texture_pos & (TEXTURE_HEIGHT - 1);
		column.texture_pos += column.step;
		column.color = get_color(map, column.texture_number, column.texture_x,
				column.texture_y);
		if (camera->side == 1)
			column.color = (column.color >> 1) & 8355711;
		mlx_spp(display, x, y, column.color);
		++y;
	}
	y = column.draw_end;
	while (y < display->height)
		mlx_spp(display, x, y++, map->floor_color);
}
