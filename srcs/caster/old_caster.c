#include "cub3d.h"

/*
	Add sprint, that makes FOV greater
*/

static void	horizontal_check_c(t_display *display, t_map *map, t_player *player, float *dist, t_point *point, t_point	*player_point, float ray_angle)
{
	int	mx;
	int	my;
	int	depth_of_field;

	float		ray_x;
	float		ray_y;
	float		x_offset;
	float		y_offset;
	float		a_tan;
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
			*dist = hyp_v(player_pos, horizontal);

			point->x = ray_x;
			point->y = ray_y;
			point->color = 0x00FFFF;
			player_point->color = 0x00FFFF;
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

static void	vertical_check_c(t_display *display, t_map *map, t_player *player, float *dist, t_point *point, t_point *player_point, float ray_angle, int *h_or_v)
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

	(void)vertical_check_c;
	depth_of_field = 0;
	dist_vertical = FLT_MAX;
	set_vector(&vertical, player->x, player->y);
	n_tan = -tan(ray_angle);
	if (ray_angle > P2 && ray_angle < P3)
	{
		ray_x = (((int)player->x / display->square_length)
				* display->square_length) - 0.0002;
		ray_y = (player->x - ray_x) * n_tan + player->y;
		x_offset = -display->square_length;
		y_offset = -x_offset * n_tan;
	}
	if (ray_angle < P2 || ray_angle > P3)
	{
		ray_x = (((int)player->x / display->square_length)
				* display->square_length) + display->square_length;
		ray_y = (player->x - ray_x) * n_tan + player->y - 0.0003;
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
			dist_vertical = hyp_v(player_pos, vertical);
			if (dist_vertical < *dist)
			{
				*h_or_v = 'v';
				point->x = ray_x;
				point->y = ray_y;
				point->color = 0xFF00FF;
				player_point->color = 0xFF00FF;
				*dist = dist_vertical;
				return ;
				printf("Dist Vertical %f /Dist Vertical\n", dist_vertical);
			}
			printf("Dist %f /Dist \n", *dist);
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

void	draw_3d_walls_c(t_display *display, t_player *player, float dist, float ray_angle, int *x, int h_or_v)
{
	float	line_height;
	int		start;
	int		end;
	int		color;
	int		y;
	float	ca =  player->angle - ray_angle;

	if (ca < 0)
	{
		ca += 2 * PI;
	}
	if (ca > 2 * PI)
	{
		ca -= 2 * PI;
	}
	dist = dist * -cos(ca);
	if (h_or_v == 'v')
		color = 0x00FFFFFF;
	else
		color = 0x00FFFF00;

	line_height = (int)((100 * display->height) / dist);
	if (line_height > display->height)
		line_height = display->height;
	start = (-line_height + display->height) / 2;
	if (start < 0)
		start = 0;
	end = (line_height + display->height) / 2;
	if (end > display->height)
		end = display->height - 1;
	y = start;
	while (y <= end)
	{
		mlx_spp(display, *x, y, color);
		y++;
	}
}

void	old_caster(t_display *display, t_map *map, t_player *player)
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
	printf("Player Angle %f /Player Angle\n", player->angle);
	if (ray_angle < 0)
		ray_angle += 2 * PI;
	if (ray_angle > 2 * PI)
		ray_angle -= 2 * PI;
	printf("Ray Angle %f /Ray Angle\n", ray_angle);	
	// clear_image(display);

	while (ray_number < display->width)
	{
		h_or_v = 'h';
		horizontal_check_c(display, map, player, &dist, &point, &player_point, ray_angle);
		vertical_check_c(display, map, player, &dist, &point, &player_point, ray_angle, &h_or_v);
		player_point.x = player->x;
		player_point.y = player->y;
		draw_line(display, player_point, point);
		// draw_3d_walls_c(display, player, dist, ray_angle, &x, h_or_v);
		++x;
		++ray_number;
		ray_angle += (DR / display->width) * 60;
		if (ray_angle < 0)
			ray_angle += 2 * PI;
		if (ray_angle > 2 * PI)
			ray_angle -= 2 * PI;
	}
}
