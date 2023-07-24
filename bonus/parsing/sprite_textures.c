#include "cub3d_bonus.h"

static bool	valid_textures(const char **textures)
{
	int	fd;

	while (*textures)
	{
		if (ft_strncmp(".xpm", (char *)(*textures + ft_strlen(*textures) - 4),
			4) != 0)
			return (error_str("Wrong sprite texture file format"), false);
		fd = open(*textures, F_OK);
		if (fd == -1)
			return (error_str("Sprite textures doesn't exist"), false);
		close(fd);
		fd = open(*textures, R_OK);
		if (fd == -1)
			return (error_str("Sprite can't be opened"), false);
		close(fd);
		++textures;
	}
	return (true);
}

static bool	texture_copying(t_map *map, const char **textures)
{
	int	i;

	i = 0;
	while (i < map->total_sprite_textures)
	{
		map->str_sprite_textures[i] = ft_strdup(textures[i]);
		if (!map->str_sprite_textures[i])
			return (perror("malloc"), ft_free_strs((char **)textures), false);
		++i;
	}
	return (ft_free_strs((char **)textures), true);
}

bool	parse_sprite_textures(t_map *map, char *value)
{
	const char	**textures = (const char **)ft_split(value, ';');
	int			i;

	free(value);
	if (!textures)
		return (perror("malloc"), false);
	i = 0;
	while (textures[i])
		++i;
	map->sprite_textures = malloc(sizeof(t_texture) * i);
	if (!map->sprite_textures)
		return (perror("malloc"), ft_free_strs((char **)textures), false);

	map->total_sprite_textures = i;
	if (!valid_textures(textures))
		return (ft_free_strs((char **)textures), false);
	map->str_sprite_textures = ft_calloc(sizeof(char *), i + 1);
	if (!map->str_sprite_textures)
		return (perror("malloc"), ft_free_strs((char **)textures), false);
	return (texture_copying(map, textures));
}
