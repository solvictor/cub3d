#include "cub3d.h"

int	on_destroy(t_vars *vars)
{
	clean_memory(vars);
	exit(EXIT_SUCCESS);
	return (1);
}
