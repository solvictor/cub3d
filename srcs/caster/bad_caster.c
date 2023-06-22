#include "cub3d.h"

bool	caster(t_map *map, t_display *display, t_player *player)
{
	double	pos_x = 10, pos_y = 5;
	double	dir_x = -1, dir_y = 0;
	double	plane_x = 0, plane_y = 0.66;

	double	time = 0;
	double	old_time = 0;
	

	while (!done())
	{
		int i = 0;
		//Raycasting
		while (i < display->width)
		{
			double camera_x = 2 * i / (double)display->width;
			double ray_dir_x = dir_x + plane_x * camera_x;
			double ray_dir_y = dir_y + plane_y * camera_x;
			
			int map_x = (int)pos_x;
			int map_y = (int)pos_y;
			
			double side_dist_x;
			double side_dist_y;

			double delta_dist_x;
			if (ray_dir_x == 0)
				delta_dist_x = 1e30;
			else
				abs(1 / ray_dir_x);

			double delta_dist_y;
			if (ray_dir_x == 0)
				delta_dist_y = 1e30;
			else
				abs(1 / ray_dir_y);

			double perp_wall_dist;
			int step_x;
			int step_y;
			int hit = 0;
			int side;

			if (ray_dir_x < 0)
			{
				step_x = -1;
				side_dist_x = (pos_x - map_x) * delta_dist_x;
			}
			else
			{
				step_x = 1;
				side_dist_x = (map_x + 1.0 - pos_x)* delta_dist_x;
			}
			if (ray_dir_y < 0)
			{
				step_y = -1;
				side_dist_y = (pos_y - map_y) * delta_dist_y;
			}
			else
			{
				step_x = 1;
				side_dist_y = (map_x + 1.0 - pos_y)* delta_dist_y;
			}
			++i;
		}
	}
}