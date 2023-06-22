#include "cub3d.h"

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
	if (ray_angle > PI)
	{
		ray_y = (((int)player->y / display->square_length) * display->square_length) - 0.0002;
		ray_x = (player->y - ray_y) * a_tan + player->x;
		y_offset = -display->square_length;
		x_offset = -y_offset * a_tan;
	}
	if (ray_angle > 0 && ray_angle < PI)
	{
		ray_y = (((int)player->y / display->square_length) * display->square_length) + display->square_length;
		ray_x = (player->y - ray_y) * a_tan + player->x;
		y_offset = display->square_length;
		x_offset = -y_offset * a_tan;
	}
	if (ray_angle == 0 || ray_angle == PI)
	{
		ray_x = player->x;
		ray_y = player->y;
		depth_of_field = map->width; //just the player pos / width (not height as 0 and PI are on width)
	}
	while (depth_of_field < map->width)
	{
		mx = (int)ray_x / display->square_length;
		my = (int)ray_y / display->square_length;
		if (my >= 0 && mx >= 0 && mx < map->width && my < map->height && map->map[my][mx] == '1')
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

static void	vertical_check(t_display *display, t_map *map, t_player *player, float *dist, t_point *point, t_point *player_point, float ray_angle, int *h_or_v)
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
		ray_x = (((int)player->x / display->square_length) * display->square_length) - 0.0003;
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
	if (ray_angle == 0 || ray_angle == PI)
	{
		ray_x = player->x;
		ray_y = player->y;
		depth_of_field = map->width; //just the player pos / width (not height as 0 and PI are on width)
	}
	while (depth_of_field < map->width)
	{
		mx = (int)ray_x / display->square_length;
		my = (int)ray_y / display->square_length;
		if (my >= 0 && mx >= 0 && mx < map->width && my < map->height && map->map[my][mx] == '1')
		{
			set_vector(&player_pos, player->x, player->y);
			set_vector(&vertical, ray_x, ray_y);
			dist_vertical = hyp(player_pos, vertical, ray_angle);
			if (dist_vertical < *dist)
			{
				*h_or_v = 'v';
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

//Window 320x160


void	draw_3d_walls(t_display *display, t_map *map, t_player *player, float dist, int ray_number, float ray_angle, int *x, int h_or_v)
{
	int		line_height;
	int		start;
	int		end;
	int		color; // set color of the wall, white in this case
	if (h_or_v == 'v')
		color = 0x00FFFFFF;
	else
		color = 0x00FFFF00;
	int		y;
	float	ca = player->angle - ray_angle;

	printf("Ray Angle %f /Ray Angle\n", ray_angle);
	printf("Player Angle %f /Player Angle\n", player->angle);
	if (ca < 0)
	{
		ca += 2 * PI;
	}
	if (ca > 2 * PI)
	{
		ca -= 2 * PI;
	}

	(void) map; (void)player; (void)ray_number; (void) ray_angle;
	// Calculate height of line to draw on screen
	for (int i = 0; i < 50; i++)
	{

		line_height = ((int)(display->height / dist)) * 40;

		// calculate lowest and highest pixel to fill in current stripe
		start = -line_height / 2 + display->height / 2;
		if(start < 0)
			start = 0;
		end = (line_height / 2 + display->height / 2) * 1;
		if(end >= display->height)
			end = display->height - 1;

		y = start;
		// draw pixel for each vertical stripe
		while(y <= end)
		{
			mlx_spp(display, *x, y, color);
			y++;
		}
		*x += 1;
	}

}


void	caster(t_display *display, t_map *map, t_player *player)
{
	float	dist;
	float	ray_angle;
	int		ray_number;
	int		x = 0;
	t_point	point;
	t_point	player_point;
	int	h_or_v;

	point.x = 0;
	point.y = 0;
	player_point.x = 0;
	player_point.y = 0;

	ray_number = 0;
	ray_angle = player->angle - DR * 30;
	// ray_angle = player->angle;

	if (ray_angle < 0)
	{
		ray_angle += 2 * PI;
	}
	if (ray_angle > 2 * PI)
	{
		ray_angle -= 2 * PI;
	}
	clear_image(display);

	while (ray_number < 60)
	{
		h_or_v = 'h';
		horizontal_check(display, map, player, &dist, &point, &player_point, ray_angle);
		vertical_check(display, map, player, &dist, &point, &player_point, ray_angle, &h_or_v);
		player_point.x = player->x;
		player_point.y = player->y;
		draw_line(display, player_point, point);
		draw_3d_walls(display, map, player, dist, ray_number, ray_angle, &x, h_or_v);
		++ray_number;
		ray_angle += DR;
		if (ray_angle < 0)
		{
			ray_angle += 2 * PI;
		}
		if (ray_angle > 2 * PI)
		{
			ray_angle -= 2 * PI;
		}
	}
	mlx_put_image_to_window(display->mlx, display->win, display->img, 0, 0);
}
