#include "cub3d.h"

#define P2 M_PI / 2
#define P3 3 * M_PI / 2 //TODO Replace in code 
/*
	Add sprint, that makes FOV greater
*/



static void	horizontal_check(t_display *display, t_map *map, t_player *player, float *dist, t_point *point, t_point	*player_point)
{
	int	mx;
	int	my;
	int	depth_of_field;

	float	ray_x;
	float	ray_y;
	float	ray_angle;
	float	x_offset;
	float	y_offset;
	float	a_tan;
	t_vector	horizontal;
	t_vector	player_pos;

	ray_angle = player->angle;

	depth_of_field = 0;
	*dist = FLT_MAX;
	set_vector(&horizontal, player->x, player->y);
	a_tan = -1 / tan(ray_angle);
	if (ray_angle > M_PI)
	{
		ray_y = (((int)player->y / display->square_length) * display->square_length) - 0.0001;
		ray_x = (player->y - ray_y) * a_tan + player->x;
		y_offset = -display->square_length;
		x_offset = -y_offset * a_tan;
	}
	if (ray_angle < M_PI)
	{
		ray_y = (((int)player->y / display->square_length) * display->square_length) + display->square_length;
		ray_x = (player->y - ray_y) * a_tan + player->x;
		y_offset = display->square_length;
		x_offset = -y_offset * a_tan;
	}
	if (ray_angle == 0 || ray_angle == M_PI)
	{
		ray_x = player->x;
		ray_y = player->y;
		depth_of_field = map->width; //just the player pos / width (not height as 0 and PI are on width)
	}
	while (depth_of_field < map->width)
	{
		mx = (int)ray_x / display->square_length;
		my = (int)ray_y / display->square_length;
		if (my >= 0 && mx > 0 && mx < map->width && my < map->height && map->map[my][mx] == '1')
		{
			set_vector(&player_pos, player->x, player->y);
			set_vector(&horizontal, ray_x, ray_y);
			*dist = hyp(player_pos, horizontal, ray_angle);
			point->x = ray_x;
			point->y = ray_y;
			point->color = 0x00FF00;
			player_point->color = 0x00FF00;
			depth_of_field = map->width;
		}
		else
		{
			ray_x += x_offset;
			ray_y += y_offset;
			depth_of_field += 1;
		}
	}

}

static void	vertical_check(t_display *display, t_map *map, t_player *player, float *dist, t_point *point, t_point *player_point)
{
	int	mx;
	int	my;
	int	depth_of_field;

	float	ray_x;
	float	ray_y;
	float	ray_angle;
	float	x_offset;
	float	y_offset;
	float	n_tan;
	float	dist_vertical;
	t_vector	vertical;
	t_vector	player_pos;


	ray_angle = player->angle;

	depth_of_field = 0;
	dist_vertical = FLT_MAX;
	set_vector(&vertical, player->x, player->y);
	n_tan = -tan(ray_angle);
	if (ray_angle > P2 && ray_angle < P3)
	{
		ray_x = (((int)player->x / display->square_length) * display->square_length) - 0.0001;
		ray_y = (player->x - ray_x) * n_tan + player->y;
		x_offset = -display->square_length;
		y_offset = -x_offset * n_tan;
	}
	if (ray_angle < P2 || ray_angle > P3)
	{
		ray_x = (((int)player->x / display->square_length) * display->square_length) + display->square_length;
		ray_y = (player->x - ray_x) * n_tan + player->y;
		x_offset = display->square_length;
		y_offset = -x_offset * n_tan;
	}
	if (ray_angle == 0 || ray_angle == M_PI)
	{
		ray_x = player->x;
		ray_y = player->y;
		depth_of_field = map->width; //just the player pos / width (not height as 0 and PI are on width)
	}
	while (depth_of_field < map->width)
	{
		mx = (int)ray_x / display->square_length;
		my = (int)ray_y / display->square_length;
		if (my >= 0 && mx > 0 && mx < map->width && my < map->height && map->map[my][mx] == '1')
		{
			set_vector(&player_pos, player->x, player->y);
			set_vector(&vertical, ray_x, ray_y);
			dist_vertical = hyp(player_pos, vertical, ray_angle);
			ft_printf("In Dist %d /In Dist\n", *dist);
			ft_printf("Dist Vert %d /Dist Vert\n", dist_vertical);

			if (dist_vertical < *dist)
			{
				point->x = ray_x;
				point->y = ray_y;
				point->color = 0xFF0000;
				player_point->color = 0xFF0000;
			}
			depth_of_field = map->width;
		}
		else
		{
			ray_x += x_offset;
			ray_y += y_offset;
			depth_of_field += 1;
		}
	}

	
}

void	caster(t_display *display, t_map *map, t_player *player)
{
	float	dist;
	int		ray_number;
	t_point	point;
	t_point	player_point;

	ray_number = 0;
	while (ray_number < 1)
	{
		horizontal_check(display, map, player, &dist, &point, &player_point);
		ft_printf("Dist %d /Dist\n", dist);
		vertical_check(display, map, player, &dist, &point, &player_point);
		player_point.x = player->x;
		player_point.y = player->y;
		draw_line(display, player_point, point);
		++ray_number;
	}
}
