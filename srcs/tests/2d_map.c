#include "cub3d.h"

void	init_cub3d(t_display *display, t_map *map, t_player *player,
		t_camera *camera)
{
	caster(display, player, map, camera);
	mlx_put_image_to_window(display->mlx, display->win, display->img, 0, 0);
}
