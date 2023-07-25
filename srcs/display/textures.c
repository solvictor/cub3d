/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:22:59 by tgernez           #+#    #+#             */
/*   Updated: 2023/07/25 12:23:00 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	get_addresses(t_map *map)
{
	map->textures[0].addr = mlx_get_data_addr(map->textures[0].img,
			&(map->textures[0].bpp), &(map->textures[0].size_line),
			&(map->textures[0].endian));
	if (!map->textures[0].addr)
		return (false);
	map->textures[1].addr = mlx_get_data_addr(map->textures[1].img,
			&(map->textures[1].bpp), &(map->textures[1].size_line),
			&(map->textures[1].endian));
	if (!map->textures[1].addr)
		return (false);
	map->textures[2].addr = mlx_get_data_addr(map->textures[2].img,
			&(map->textures[2].bpp), &(map->textures[2].size_line),
			&(map->textures[2].endian));
	if (!map->textures[2].addr)
		return (false);
	map->textures[3].addr = mlx_get_data_addr(map->textures[3].img,
			&(map->textures[3].bpp), &(map->textures[3].size_line),
			&(map->textures[3].endian));
	if (!map->textures[3].addr)
		return (false);
	return (true);
}

bool	get_textures(t_display *display, t_map *map)
{
	map->textures[0].img = mlx_xpm_file_to_image(display->mlx, map->path_north,
			&(map->textures[0].width), &(map->textures[0].height));
	if (!map->textures[0].img)
		return (destroy_images(display, map, 0), false);
	map->textures[1].img = mlx_xpm_file_to_image(display->mlx, map->path_south,
			&(map->textures[1].width), &(map->textures[1].height));
	if (!map->textures[1].img)
		return (destroy_images(display, map, 1), false);
	map->textures[2].img = mlx_xpm_file_to_image(display->mlx, map->path_west,
			&(map->textures[2].width), &(map->textures[2].height));
	if (!map->textures[2].img)
		return (destroy_images(display, map, 2), false);
	map->textures[3].img = mlx_xpm_file_to_image(display->mlx, map->path_east,
			&(map->textures[3].width), &(map->textures[3].height));
	if (!map->textures[3].img)
		return (destroy_images(display, map, 3), false);
	if (!get_addresses(map))
		return (destroy_images(display, map, 3), false);
	return (true);
}
