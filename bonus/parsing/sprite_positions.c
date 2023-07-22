#include "cub3d_bonus.h"

static bool	check_sprite_texture(t_map *map, const char *str_nb_texture,
	t_sprite *sprite)
{
	const int	nb_texture = ft_atoi(str_nb_texture);

	if (nb_texture < 1 || nb_texture > map->total_sprite_textures)
		return (error_str("Bad sprite texture number"), false);
	sprite->nb_texture = nb_texture;
	return (true);
}

static bool	check_sprite_coordinates(t_map *map, const char *str_x,
	const char *str_y, t_sprite *sprite)
{
	double	x;
	double	y;
	bool	atof_status;

	atof_status = false;
	x = ft_atof(str_x, &atof_status);
	if (!atof_status)
		return (error_str("Bad sprite coordinate"), false);
	y = ft_atof(str_y, &atof_status);
	if (!atof_status)
		return (error_str("Bad sprite coordinate"), false);
	if ((x < 0 || x > map->width) || (y < 0 || y > map->height))
		return (false);
	sprite->x = x;
	sprite->y = y;
	return (true);
}

static bool	set_sprite(t_map *map, t_sprite *sprite, const char *raw_sprite)
{
	const char	**data = (const char **)ft_split(raw_sprite, ':');
	int			i;

	if (!data)
		return (perror("malloc"), false);
	i = 0;
	while (data[i])
		++i;
	if (i < 2)
		return (error_str("Too few parameters for sprite"), false);
	if (!check_sprite_coordinates(map, data[0], data[1], sprite)
		|| !check_sprite_texture(map, data[2], sprite))
		return (ft_free_strs((char **)data), false);
	return (true);
}

bool	parse_sprite_positions(t_map *map, char *value)
{
	const char	**positions = (const char **)ft_split(value, ';');
	int			i;

	if (!positions)
		return (perror("malloc"), free(value), false);
	i = 0;
	while (positions[i])
		++i;
	map->sprites = ft_calloc(sizeof(t_sprite), i);
	if (!map->sprites)
		return (perror("malloc"), ft_free_strs((char **)positions), free(value),
			false);
	map->total_sprites = i;
	i = 0;
	while (i < map->total_sprites)
	{
		if (!set_sprite(map, (t_sprite *)(map->sprites + i), positions[i]))
			return (ft_free_strs((char **)positions), free(value), false); //TODO check how to free map->sprites, mayybe init it to NULL and free it if != NULL
		++i; //TODO IMPORTANT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! to clear properly, free until NULL or the ind == map->total_sprites
	}
	return (true);
}

