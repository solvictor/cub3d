#include "cub3d.h"

void	set_vector(t_vector *vector, double x, double y)
{
	vector->x = x;
	vector->y = y;
}

t_vector	addition(t_vector v_a, t_vector v_b)
{
	t_vector	result;

	result.x = v_a.x + v_b.x;
	result.y = v_a.y + v_b.y;
	return (result);
}