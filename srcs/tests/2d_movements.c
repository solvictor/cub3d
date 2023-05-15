#include "cub3d.h"

/*
	Segfaulting when going out of the map, add protections
*/

// void	move_player(t_display *display, t_player *player)
// {
// 	mlx_spp(display, player->x, player->y, 0xFFFFFF);
// 	mlx_spp(display, player->x - 1, player->y, 0xFFFFFF);
// 	mlx_spp(display, player->x + 1, player->y, 0xFFFFFF);
// 	mlx_spp(display, player->x, player->y - 1, 0xFFFFFF);
// 	mlx_spp(display, player->x, player->y + 1, 0xFFFFFF);
// }

void	basic_up(t_vars *vars)
{
	// ft_printf("UP Vars->player->y %d /vars->player->y\n", vars->player->y);
	if (vars->player->y <= 2)
		return ;
	if (colliding(UP, vars->map, vars->player, vars->display))
		return ;
	vars->player->y -= 1 * vars->player->speed;
	return ;
}

void	basic_down(t_vars *vars)
{
	// ft_printf("DOWN Vars->player->y %d /vars->player->y\n", vars->player->y);
	if (vars->player->y >= vars->display->height - 3)
		return ;
	if (colliding(DOWN, vars->map, vars->player, vars->display))
		return ;
	vars->player->y += 1 * vars->player->speed;
	return ;
}

void	basic_left(t_vars *vars)
{
	// ft_printf("LEFT Vars->player->x %d /vars->player->x\n", vars->player->x);
	if (vars->player->x <= 2)
		return ;
	if (colliding(LEFT, vars->map, vars->player, vars->display))
		return ;
	vars->player->x -= 1 * vars->player->speed;
	return ;
}


/*
	Add a variable to refresh, piut to 1 if changed
*/

void	basic_right(t_vars *vars)
{
	// ft_printf("RIGHT Vars->player->x %d /vars->player->x\n", vars->player->x);
	// if (vars->player->x >= vars->display->width - 2)
	// 	return ;
	if (colliding(RIGHT, vars->map, vars->player, vars->display))
		return ;
	vars->player->x += 1 * vars->player->speed;
	return ;
}
