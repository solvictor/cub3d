#include "cub3d.h"

static void	bres_draw_low(t_display *display, t_point p1, t_point p2)
{
	int	x;
	int	y;
	int	bres_val;
	int	sign_delta_y;
	int	delta_y;

	delta_y = abs(p2.y - p1.y);
	sign_delta_y = 1 - (p2.y - p1.y < 0) * 2;
	bres_val = (2 * delta_y) - (p2.x - p1.x);
	x = p1.x;
	y = p1.y;
	while (++x < p2.x)
	{
		mlx_spp(display, x, y, p1.color);
		if (bres_val > 0)
		{
			y += sign_delta_y;
			bres_val += 2 * (delta_y - (p2.x - p1.x));
		}
		else
			bres_val += 2 * delta_y;
	}
}

static void	bres_draw_high(t_display *display, t_point p1, t_point p2)
{
	int	x;
	int	y;
	int	delta_x;
	int	bres_val;
	int	sign_delta_x;

	delta_x = abs(p2.x - p1.x);
	sign_delta_x = 1 - (p2.x - p1.x < 0) * 2;
	bres_val = (2 * delta_x) - (p2.y - p1.y);
	x = p1.x;
	y = p1.y;
	while (++y < p2.y)
	{
		mlx_spp(display, x, y, p1.color);
		if (bres_val > 0)
		{
			x += sign_delta_x;
			bres_val += 2 * (delta_x - (p2.y - p1.y));
		}
		else
			bres_val += 2 * delta_x;
	}
}


void	draw_line(t_display *display, t_point p1, t_point p2)
{
	if (abs(p2.x - p1.x) > abs(p2.y - p1.y))
	{
		if (p2.x > p1.x)
			bres_draw_low(display, p1, p2);
		else
			bres_draw_low(display, p2, p1);
	}
	else
	{
		if (p2.y > p1.y)
			bres_draw_high(display, p1, p2);
		else
			bres_draw_high(display, p2, p1);
	}
}

// static void	bres_draw_low_1(t_display *display, t_point p1, t_point p2)
// {
// 	int	x;
// 	int	y;
// 	int	bres_val;
// 	int	sign_delta_y;
// 	int	delta_y;

// 	delta_y = abs(p2.y - p1.y);
// 	sign_delta_y = 1 - (p2.y - p1.y < 0) * 2;
// 	bres_val = (2 * delta_y) - (p2.x - p1.x);
// 	x = p1.x - 1;
// 	y = p1.y;
// 	while (++x < p2.x)
// 	{
// 		mlx_spp(display, x, y, 0xF0F0F0);
// 		if (bres_val > 0)
// 		{
// 			y += sign_delta_y;
// 			bres_val += 2 * (delta_y - (p2.x - p1.x));
// 		}
// 		else
// 			bres_val += 2 * delta_y;
// 	}
// }

// static void	bres_draw_high_1(t_display *display, t_point p1, t_point p2)
// {
// 	int	x;
// 	int	y;
// 	int	delta_x;
// 	int	bres_val;
// 	int	sign_delta_x;

// 	delta_x = abs(p2.x - p1.x);
// 	sign_delta_x = 1 - (p2.x - p1.x < 0) * 2;
// 	bres_val = (2 * delta_x) - (p2.y - p1.y);
// 	x = p1.x - 1;
// 	y = p1.y;
// 	while (++y < p2.y)
// 	{
// 		mlx_spp(display, x, y, 0x00FFFF);
// 		if (bres_val > 0)
// 		{
// 			x += sign_delta_x;
// 			bres_val += 2 * (delta_x - (p2.y - p1.y));
// 		}
// 		else
// 			bres_val += 2 * delta_x;
// 	}
// }

// static void	bres_draw_low_2(t_display *display, t_point p1, t_point p2)
// {
// 	int	x;
// 	int	y;
// 	int	bres_val;
// 	int	sign_delta_y;
// 	int	delta_y;

// 	delta_y = abs(p2.y - p1.y);
// 	sign_delta_y = 1 - (p2.y - p1.y < 0) * 2;
// 	bres_val = (2 * delta_y) - (p2.x - p1.x);
// 	x = p1.x + 1;
// 	y = p1.y;
// 	while (++x < p2.x)
// 	{
// 		mlx_spp(display, x, y, 0x00FF00);
// 		if (bres_val > 0)
// 		{
// 			y += sign_delta_y;
// 			bres_val += 2 * (delta_y - (p2.x - p1.x));
// 		}
// 		else
// 			bres_val += 2 * delta_y;
// 	}
// }

// static void	bres_draw_high_2(t_display *display, t_point p1, t_point p2)
// {
// 	int	x;
// 	int	y;
// 	int	delta_x;
// 	int	bres_val;
// 	int	sign_delta_x;

// 	delta_x = abs(p2.x - p1.x);
// 	sign_delta_x = 1 - (p2.x - p1.x < 0) * 2;
// 	bres_val = (2 * delta_x) - (p2.y - p1.y);
// 	x = p1.x;
// 	y = p1.y;
// 	while (++y < p2.y)
// 	{
// 		mlx_spp(display, x, y, 0xFF0000);
// 		if (bres_val > 0)
// 		{
// 			x += sign_delta_x;
// 			bres_val += 2 * (delta_x - (p2.y - p1.y));
// 		}
// 		else
// 			bres_val += 2 * delta_x;
// 	}
// }

// void	draw_line(t_display *display, t_point p1, t_point p2)
// {
// 	if (abs(p2.x - p1.x) > abs(p2.y - p1.y))
// 	{
// 		if (p2.x > p1.x)
// 			bres_draw_low_1(display, p1, p2);
// 		else
// 			bres_draw_low_2(display, p2, p1);
// 	}
// 	else
// 	{
// 		if (p2.y > p1.y)
// 			bres_draw_high_1(display, p1, p2);
// 		else
// 			bres_draw_high_2(display, p2, p1);
// 	}
// }



void	draw_vertical_line(int x, int y_start, int y_end, t_display *display)
{
	int		y;

	y = y_end;
	while (y <= y_start)
	{
		mlx_spp(display, x, y, 0xFFFFFF);
		++y;
	}
}