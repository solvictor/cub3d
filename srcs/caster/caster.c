#include "cub3d.h"

void	draw_3d_walls(t_display *display, t_player *player, t_caster *caster)
{
	const float	ca = player->angle - caster->ray_angle;
	float		line_height;
	int			start;
	int			end;

	correct_angle((float *)&ca);
	caster->ray_length_final *= cos(ca);
	line_height = (int)((100 * display->height) / caster->ray_length_final);
	if (line_height > display->height)
		line_height = display->height;
	start = (-line_height + display->height) / 2;
	if (start < 0)
		start = 0;
	end = (line_height + display->height) / 2;
	if (end > display->height)
		end = display->height - 1;
	while (start <= end)
	{
		mlx_spp(display, caster->x_coord, start, 0xFFFFFF);
		++start;
	}
}


static void	init_caster(t_caster *caster)
{
	caster->ray_length_h = 0;
	caster->ray_length_v = 0;
	caster->ray_length_final = 0;
	caster->ray_angle = 0;
	caster->ray_number = 0;
	caster->x_coord = 0;
	caster->depth_of_field = 0;
	set_vector(&caster->ray, 0, 0);
	set_vector(&caster->offset, 0, 0);
	set_point(&caster->impact, 0, 0, 0xFFFFFF);
	set_point(&caster->origin, 0, 0, 0xFFFFFF);
}

void	casting(t_display *display, t_map *map, t_player *player,
	t_caster *caster)
{
	init_caster(caster);
	caster->ray_angle = player->angle - DR * 30;
	correct_angle(&caster->ray_angle);
	// clear_image(display);
	while (caster->ray_number < display->width)
	{
		horizontal_check(display, map, player, caster);
		// vertical_check(display, map, player, caster);
		caster->origin.x = player->x;
		caster->origin.y = player->y;
		draw_line(display, caster->origin, caster->impact);
		// draw_3d_walls(display, player, caster);
		++(caster->x_coord);
		++(caster->ray_number);
		// caster->ray_angle = correct_angle((caster->ray_angle + DR
		// 			/ display->width) * 60);
		caster->ray_angle += (DR / display->width) * 60;
		correct_angle(&caster->ray_angle);
		if (caster->ray_angle < 0)
			caster->ray_angle += 2 * PI;
		if (caster->ray_angle > 2 * PI)
			caster->ray_angle -= 2 * PI;
	}
	printf("Correct Angle: %f\n", caster->ray_angle);
}
