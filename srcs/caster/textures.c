/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:22:42 by tgernez           #+#    #+#             */
/*   Updated: 2023/07/25 12:22:43 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_color(t_map *map, int id, int texture_x, int texture_y)
{
	return (((unsigned int *)(map->textures[id].addr))
		[TEXTURE_WIDTH * texture_y + texture_x]);
}

int	select_texture(t_camera *camera)
{
	int	wall_face;

	if (camera->side == 0)
	{
		if (camera->step_x > 0)
			wall_face = WEST;
		else
			wall_face = EAST;
	}
	else
	{
		if (camera->step_y > 0)
			wall_face = NORTH;
		else
			wall_face = SOUTH;
	}
	return (wall_face);
}
