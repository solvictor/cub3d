#include "cub3d.h"

/*
	Segfaulting when going out of the map, add protections
*/

void	move_player(t_display *display, t_player *player)
{
	mlx_spp(display, player->x, player->y, 0xFFFFFF);
	mlx_spp(display, player->x - 1, player->y, 0xFFFFFF);
	mlx_spp(display, player->x + 1, player->y, 0xFFFFFF);
	mlx_spp(display, player->x, player->y - 1, 0xFFFFFF);
	mlx_spp(display, player->x, player->y + 1, 0xFFFFFF);
}

void	basic_up(t_vars *vars)
{
	// ft_printf("UP Vars->player->y %d /vars->player->y\n", vars->player->y);
	if (vars->player->y <= 1)
		return ;
	mlx_spp(vars->display, vars->player->x, vars->player->y, 0xFF00FF);
	mlx_spp(vars->display, vars->player->x - 1, vars->player->y, 0xFF00FF);
	mlx_spp(vars->display, vars->player->x + 1, vars->player->y, 0xFF00FF);
	mlx_spp(vars->display, vars->player->x, vars->player->y - 1, 0xFF00FF);
	mlx_spp(vars->display, vars->player->x, vars->player->y + 1, 0xFF00FF);
	vars->player->y -= 1;
	move_player(vars->display, vars->player);

	mlx_put_image_to_window(vars->display->mlx, vars->display->win,
		vars->display->img, 0, 0);
	return ;
}

void	basic_down(t_vars *vars)
{
	// ft_printf("DOWN Vars->player->y %d /vars->player->y\n", vars->player->y);
	if (vars->player->y >= vars->display->heigth - 2)
		return ;
	mlx_spp(vars->display, vars->player->x, vars->player->y, 0xFF00FF);
	mlx_spp(vars->display, vars->player->x - 1, vars->player->y, 0xFF00FF);
	mlx_spp(vars->display, vars->player->x + 1, vars->player->y, 0xFF00FF);
	mlx_spp(vars->display, vars->player->x, vars->player->y - 1, 0xFF00FF);
	mlx_spp(vars->display, vars->player->x, vars->player->y + 1, 0xFF00FF);
	vars->player->y += 1;
	move_player(vars->display, vars->player);
	mlx_put_image_to_window(vars->display->mlx, vars->display->win,
		vars->display->img, 0, 0);
	return ;
}

void	basic_left(t_vars *vars)
{
	// ft_printf("LEFT Vars->player->x %d /vars->player->x\n", vars->player->x);
	if (vars->player->x <= 1)
		return ;
	mlx_spp(vars->display, vars->player->x, vars->player->y, 0xFF00FF);
	mlx_spp(vars->display, vars->player->x - 1, vars->player->y, 0xFF00FF);
	mlx_spp(vars->display, vars->player->x + 1, vars->player->y, 0xFF00FF);
	mlx_spp(vars->display, vars->player->x, vars->player->y - 1, 0xFF00FF);
	mlx_spp(vars->display, vars->player->x, vars->player->y + 1, 0xFF00FF);
	vars->player->x -= 1;
	move_player(vars->display, vars->player);
	mlx_put_image_to_window(vars->display->mlx, vars->display->win,
		vars->display->img, 0, 0);
	return ;
}

void	basic_right(t_vars *vars)
{
	// ft_printf("RIGHT Vars->player->x %d /vars->player->x\n", vars->player->x);
	if (vars->player->x <= vars->display->width - 2)
		return ;
	mlx_spp(vars->display, vars->player->x, vars->player->y, 0xFF00FF);
	mlx_spp(vars->display, vars->player->x - 1, vars->player->y, 0xFF00FF);
	mlx_spp(vars->display, vars->player->x + 1, vars->player->y, 0xFF00FF);
	mlx_spp(vars->display, vars->player->x, vars->player->y - 1, 0xFF00FF);
	mlx_spp(vars->display, vars->player->x, vars->player->y + 1, 0xFF00FF);
	vars->player->x += 1;
	move_player(vars->display, vars->player);
	mlx_put_image_to_window(vars->display->mlx, vars->display->win,
		vars->display->img, 0, 0);
	return ;
}
