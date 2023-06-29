#include "cub3d.h"

static void	horizontal_check_dep(t_display *display, t_player *player,
	t_caster *caster)
{
	const float	a_tan = -1 / tan(caster->ray_angle);
	t_vector	*ray;
	t_vector	*offset;

	ray = &caster->ray;
	offset = &caster->offset;
	if (caster->ray_angle > PI)
	{
		ray->y = (((int)player->y / display->square_length)
				* display->square_length) - 0.0002;
		ray->x = (player->y - ray->y) * a_tan + player->x;
		offset->y = -display->square_length;
		offset->x = -offset->y * a_tan;
	}
	if (caster->ray_angle > 0 && caster->ray_angle < PI)
	{
		ray->y = (((int)player->y / display->square_length)
				* display->square_length) + display->square_length - 0.0002;
		ray->x = (player->y - ray->y) * a_tan + player->x;
		offset->y = display->square_length;
		offset->x = -offset->y * a_tan;
	}
}

static void	inline_check(t_player *player, t_map *map, t_caster *caster)
{
	if (caster->ray_angle == 0 || caster->ray_angle == PI)
	{
		caster->ray.x = player->x;
		caster->ray.y = player->y;
		caster->depth_of_field = map->width;
	}
}

static void	hit_wall(t_map *map, t_player *player, t_caster *caster)
{
	caster->ray_length_h = hyp(player->x, player->y,
			caster->ray.x, caster->ray.y);
	caster->impact.x = caster->ray.x;
	caster->impact.y = caster->ray.y;
	caster->impact.color = 0x00FF00;
	caster->origin.color = 0x00FF00;
	caster->ray_length_final = caster->ray_length_h; //Might be deleted to simplify
	caster->depth_of_field = map->width;
}

static void	hit_empty(t_caster *caster)
{
	caster->ray.x += caster->offset.x;
	caster->ray.y += caster->offset.y;
	caster->depth_of_field += 1;
}

void	horizontal_check(t_display *display, t_map *map, t_player *player,
	t_caster *caster)
{
	int	map_x;
	int	map_y;

	caster->depth_of_field = 0;
	caster->ray_length_h = FLT_MAX;
	caster->ray_length_final = FLT_MAX;
	horizontal_check_dep(display, player, caster);
	inline_check(player, map, caster);
	while (caster->depth_of_field < map->width)
	{
		map_x = (int)caster->ray.x / display->square_length;
		map_y = (int)caster->ray.y / display->square_length;
		if (map_y >= 0 && map_x >= 0
			&& map_x < map->width && map_y < map->height
			&& map->map[map_y][map_x] == '1')
			hit_wall(map, player, caster);
		else
			hit_empty(caster);
	}
}
