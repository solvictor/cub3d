/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:25:12 by tgernez           #+#    #+#             */
/*   Updated: 2023/07/25 12:25:13 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	get_addresses_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < TOTAL_WALL_TEXTURES)
	{
		map->textures[i].addr = mlx_get_data_addr(map->textures[i].img,
				&(map->textures[i].bpp), &(map->textures[i].size_line),
				&(map->textures[i].endian));
		if (!map->textures[i].addr)
			return (false);
		++i;
	}
	return (true);
}

bool	get_textures_walls(t_display *display, t_map *map)
{
	map->textures[0].img = mlx_xpm_file_to_image(display->mlx, map->path_north,
			&(map->textures[0].width), &(map->textures[0].height));
	if (!map->textures[0].img)
		return (destroy_wall_images(display, map, 0), false);
	map->textures[1].img = mlx_xpm_file_to_image(display->mlx, map->path_south,
			&(map->textures[1].width), &(map->textures[1].height));
	if (!map->textures[1].img)
		return (destroy_wall_images(display, map, 1), false);
	map->textures[2].img = mlx_xpm_file_to_image(display->mlx, map->path_west,
			&(map->textures[2].width), &(map->textures[2].height));
	if (!map->textures[2].img)
		return (destroy_wall_images(display, map, 2), false);
	map->textures[3].img = mlx_xpm_file_to_image(display->mlx, map->path_east,
			&(map->textures[3].width), &(map->textures[3].height));
	if (!map->textures[3].img)
		return (destroy_wall_images(display, map, 3), false);
	map->textures[4].img = mlx_xpm_file_to_image(display->mlx,
			map->path_door_closed, &(map->textures[4].width),
			&(map->textures[4].height));
	if (!map->textures[4].img || !get_addresses_walls(map))
		return (destroy_wall_images(display, map, 4), false);
	return (true);
}
