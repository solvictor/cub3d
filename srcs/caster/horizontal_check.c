#include "cub3d.h"

const void	horizontal_check_setup(t_map *map, t_display *display,
	t_player *player, t_caster *caster)
{
	const float	a_tan = -1 / caster->ray_angle;
	t_vector	ray;
	t_vector	offset;

	caster->depth_of_field = 0;
	caster->ray_length = FLT_MAX;
	if (caster->ray_angle > PI)
	{
		ray.y = (((int)player->y / 64))
	}
}
