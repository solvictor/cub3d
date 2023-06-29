#include "cub3d.h"

static void	vertical_check_dep(t_display *display, t_player *player,
	t_caster *caster)
{
	const float	n_tan = -tan(caster->ray_angle);
	t_vector	*ray;
	t_vector	*offset;

	ray = &caster->ray;
	offset = &caster->offset;
	if (caster->ray_angle > P2 && caster->ray_angle < P3)
	{
		ray->x = (((int)player->x / display->square_length)
				* display->square_length) - 0.0003;
		ray->y = (player->x - ray->x) * n_tan + player->y;
		offset->x = -display->square_length;
		offset->y = -offset->y * n_tan;
	}
	if (caster->ray_angle < P2 || caster->ray_angle > P3)
	{
		ray->x = (((int)player->x / display->square_length)
				* display->square_length) + display->square_length - 0.0003;
		ray->y = (player->x - ray->x) * n_tan + player->y;
		offset->x = display->square_length;
		offset->y = -offset->x * n_tan;
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
	caster->ray_length_v = hyp(player->x, player->y,
			caster->ray.x, caster->ray.y);
	if (caster->ray_length_v < caster->ray_length_h)
	{
		caster->impact.x = caster->ray.x;
		caster->impact.y = caster->ray.y;
		caster->impact.color = 0xFF0000;
		caster->origin.color = 0xFF0000;
		caster->ray_length_final = caster->ray_length_v; //Might be deleted 'cause useless
	}
	caster->depth_of_field = map->width;
}

static void	hit_empty(t_caster *caster)
{
	caster->ray.x += caster->offset.x;
	caster->ray.y += caster->offset.y;
	caster->depth_of_field += 1;
}

void	vertical_check(t_display *display, t_map *map, t_player *player,
	t_caster *caster)
{
	int	map_x;
	int	map_y;

	caster->depth_of_field = 0;
	caster->ray_length_v = FLT_MAX;
	vertical_check_dep(display, player, caster);
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