#include "cub3d_bonus.h"

void	clean_camera_variables(t_camera *camera)
{
	if (camera->z_buffer)
		free(camera->z_buffer);
	if (camera->sprite_order)
		free(camera->sprite_order);
	if (camera->sprite_distance)
		free(camera->sprite_distance);
}
