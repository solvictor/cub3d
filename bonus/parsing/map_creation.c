/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:24:59 by tgernez           #+#    #+#             */
/*   Updated: 2023/07/25 12:25:00 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	recopying(t_map *map, char **cleaned_map,
	int last_line)
{
	int			i;
	int			j;

	i = 0;
	while (i < last_line + 1)
	{
		j = 0;
		cleaned_map[i] = ft_calloc(map->width + 3, sizeof(char));
		if (!cleaned_map[i])
			return (ft_free_strs(cleaned_map), false);
		while (map->map[i][j])
		{
			cleaned_map[i][j] = map->map[i][j];
			++j;
		}
		++i;
	}
	cleaned_map[map->start_coords[1]][map->start_coords[0]] = '0';
	return (true);
}

static bool	clean_map(t_map *map)
{
	int		last_line;
	int		i;
	char	**cleaned_map;

	i = 0;
	while (map->map[i])
		++i;
	while (!ft_cset_in_str(MAP_CHARS, map->map[i]))
		--i;
	last_line = i - (map->map[i] == NULL);
	cleaned_map = ft_calloc(i + 2, sizeof(char *));
	if (!cleaned_map)
		return (false);
	cleaned_map[i] = NULL;
	i = -1;
	recopying(map, cleaned_map, last_line);
	ft_free_strs(map->map);
	map->map = cleaned_map;
	map->height = last_line + 1;
	return (true);
}

bool	create_map(t_vars *vars, t_map *map)
{
	int			i;
	int			j;
	const char	**content = (const char **)vars->file_content
		+ map->first_line_map;

	i = 0;
	map->map = ft_calloc(map->height + 2, sizeof (char *));
	if (!map->map)
		return (perror("malloc"), false);
	while (content[i])
	{
		j = 0;
		map->map[i] = ft_calloc(map->width + 2, sizeof (char));
		if (!map->map[i])
			return (ft_free_strs(map->map), perror("malloc"), false);
		while (content[i][j])
		{
			map->map[i][j] = content[i][j];
			++j;
		}
		++i;
	}
	return (clean_map(map));
}
