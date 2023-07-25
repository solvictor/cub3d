/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgernez <tgernez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:24:49 by tgernez           #+#    #+#             */
/*   Updated: 2023/07/25 12:24:50 by tgernez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	check_rgb(const char **colors)
{
	int	i;
	int	tmp;

	i = 0;
	while (colors[i])
	{
		tmp = ft_atoi(colors[i]);
		if (0 > tmp || tmp > 255)
			return (error_str("Invalid RGB value"), false);
		i++;
	}
	if (i != 3)
		return (error_str("Wrong RGB format"), false);
	return (true);
}

static bool	assign_to_map_aux(char *id, char *value, t_map *map)
{
	const char	**colors = (const char **)ft_split(value, ',');

	if (!colors)
		return (perror("malloc"), free(value), false);
	if (!check_rgb(colors))
		return (free(value), ft_free_strs((char **)colors), false);
	else if (!ft_strncmp(id, "F", 1))
	{
		map->floor_color = ft_atoi(colors[0]) * 65536;
		map->floor_color += ft_atoi(colors[1]) * 256;
		map->floor_color += ft_atoi(colors[2]);
	}
	else if (!ft_strncmp(id, "C", 1))
	{
		map->ceiling_color = ft_atoi(colors[0]) * 65536;
		map->ceiling_color += ft_atoi(colors[1]) * 256;
		map->ceiling_color += ft_atoi(colors[2]);
	}
	return (free(value), ft_free_strs((char **)colors), true);
}

static bool	assign_to_map(char *id, char *value, t_map *map)
{
	if (!ft_strncmp(id, "NO", 2))
		map->path_north = value;
	else if (!ft_strncmp(id, "SO", 2))
		map->path_south = value;
	else if (!ft_strncmp(id, "EA", 2))
		map->path_east = value;
	else if (!ft_strncmp(id, "WE", 2))
		map->path_west = value;
	else if (!ft_strncmp(id, "DC", 2))
		map->path_door_closed = value;
	else
		return (assign_to_map_aux(id, value, map));
	return (true);
}

static char	*find_id(char *id, char *line, int line_nb, t_map *map)
{
	const size_t	len_id = ft_strlen(id);
	char			*tmp;
	char			*info;
	int				i;

	i = 0;
	while (line[i] && ft_c_in_str(line[i], SPACES))
		++i;
	if (ft_strncmp(id, line + i, len_id) != 0)
		return (NULL);
	tmp = ft_strtrim(line + i + len_id, SPACES);
	i = 0;
	while (tmp[i] && !ft_c_in_str(tmp[i], SPACES))
		++i;
	if (i == 0)
		return (NULL);
	info = malloc(sizeof(char) * i + 1);
	if (!info)
		return (NULL);
	info[i] = '\0';
	while (--i >= 0)
		info[i] = tmp[i];
	free(tmp);
	map->param_lines[map->total_parameters++] = line_nb;
	return (info);
}

bool	get_textures_info(t_vars *vars, t_map *map)
{
	const char	**content = (const char **)vars->file_content;
	const char	ids[PARAMETER_NUMBER][3] = {"NO", "SO", "WE", "EA", "F", "C",
		"DC"};
	int			i;
	int			j;
	char		*tmp;

	i = 0;
	tmp = NULL;
	while (content[i])
	{
		j = 0;
		while (j < PARAMETER_NUMBER)
		{
			tmp = find_id((char *)ids[j], (char *)content[i], i, map);
			if (tmp && !assign_to_map((char *)ids[j], tmp, map))
				return (false);
			++j;
		}
		++i;
	}
	if (map->total_parameters < PARAMETER_NUMBER)
		return (error_str("Not enough parameters"), false);
	return (true);
}
