#include "cub3d.h"

#define P2 M_PI / 2
#define P3 3 * M_PI / 2 //TODO replace with actual values
#define DR 0.0174533 //1 deg to rad
/*
	Add sprint, that makes FOV greater
*/



static void	horizontal_check(t_display *display, t_map *map, t_player *player, float *dist, t_point *point, t_point	*player_point, float ray_angle)
{
	int	mx;
	int	my;
	int	depth_of_field;

	float	ray_x;
	float	ray_y;
	float	x_offset;
	float	y_offset;
	float	a_tan;
	t_vector	horizontal;
	t_vector	player_pos;

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

static void	vertical_check(t_display *display, t_map *map, t_player *player, float *dist, t_point *point, t_point *player_point, float ray_angle)
{
	int	mx;
	int	my;
	int	depth_of_field;

	float	ray_x;
	float	ray_y;
	float	x_offset;
	float	y_offset;
	float	n_tan;
	float	dist_vertical;
	t_vector	vertical;
	t_vector	player_pos;

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
			if (dist_vertical < *dist)
			{
				point->x = ray_x;
				point->y = ray_y;
				point->color = 0xFF0000;
				player_point->color = 0xFF0000;
				*dist = dist_vertical;
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

void	draw_3d_walls(t_display *display, t_map *map, t_player *player, float dist, int ray_number, float ray_angle)
{
	float	line_height;
	// float	line_offset;
	float	ca = player->angle - ray_angle;

	if (ca < 0)
	{
		ca += 2 * M_PI;
	}
	if (ca > 2 * M_PI)
	{
		ca -= 2 * M_PI;
	}
	dist = dist * cos(ca); //FIx fisheye
	(void)player;
	(void)map;
	line_height = (60 * display->height) / dist;
	if (line_height > display->height)
		line_height = display->height;
	// line_offset = display->height - line_height / 2; // Returned everything
	int i = 0;
	t_point	p1;
	t_point	p2;
	while (i < 20)
	{
		p1.x = ray_number * 20 + i;
		p1.y = 0;
		p2.x = ray_number * 20 + i;
		p2.y = p1.y + line_height + 0;
		p1.color = 0xFF0000;
		p2.color = 0xFF0000;
		draw_line(display, p1, p2);
		++i;
	}
	mlx_put_image_to_window(display->mlx, display->win, display->img, 0, 0);
}

void	caster(t_display *display, t_map *map, t_player *player)
{
	float	dist;
	float	ray_angle;
	int		ray_number;
	t_point	point;
	t_point	player_point;

	ray_number = 0;
	ray_angle = player->angle - DR * 30;
	if (ray_angle < 0)
	{
		ray_angle += 2 * M_PI;
	}
	if (ray_angle > 2 * M_PI)
	{
		ray_angle -= 2 * M_PI;
	}
	clear_image(display);

	while (ray_number < 60)
	{
		horizontal_check(display, map, player, &dist, &point, &player_point, ray_angle);
		vertical_check(display, map, player, &dist, &point, &player_point, ray_angle);
		player_point.x = player->x;
		player_point.y = player->y;
		// draw_line(display, player_point, point);
		draw_3d_walls(display, map, player, dist, ray_number, ray_angle);
		++ray_number;
		ray_angle += DR;
		if (ray_angle < 0)
		{
			ray_angle += 2 * M_PI;
		}
		if (ray_angle > 2 * M_PI)
		{
			ray_angle -= 2 * M_PI;
		}
	}
}
