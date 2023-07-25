/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:24:53 by tgernez           #+#    #+#             */
/*   Updated: 2023/07/25 12:24:54 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	is_too_short(const char **content, t_map *map)
{
	int	i;
	int	height;

	i = map->first_line_map;
	height = 0;
	while (content[i])
	{
		++height;
		++i;
	}
	map->height = height;
	return (height < 3);
}

static bool	bad_line(char *line, int line_nb, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!ft_c_in_str(line[i], SPACES) && !ft_c_in_str(line[i], WALL_TYPES))
		{
			if (!ft_c_in_str(line[i], PLAYER))
				return (error_str("Bad char in map"), true);
			else if (map->start_coords[0] != -1)
				return (error_str("Too many players in map"), true);
			map->start_coords[0] = i;
			map->start_coords[1] = line_nb - map->first_line_map;
			map->start_direction = line[i];
		}
		++i;
	}
	if (i > map->width)
		map->width = i;
	++map->height;
	return (false);
}

static bool	is_line_a_texture(int line_nb, t_map *map)
{
	int	i;

	i = 0;
	while (i < PARAMETER_NUMBER)
		if (line_nb == map->param_lines[i++])
			return (true);
	return (false);
}

bool	map_size(t_vars *vars, t_map *map)
{
	const char	**content = (const char **)vars->file_content;
	int			i;

	i = 0;
	while (content[i])
	{
		if (!is_line_a_texture(i, map))
		{
			if (bad_line((char *)content[i], i, map))
				return (false);
			else if (map->first_line_map == -1 && !is_line_empty(content[i]))
				map->first_line_map = i;
		}
		++i;
	}
	if (map->first_line_map == -1)
		return (error_str("No map found"), false);
	if (is_too_short(content, map) || map->width < 3)
		return (error_str("Map too small"), false);
	if (map->start_direction == '\0')
		return (error_str("No start position"), false);
	return (true);
}
