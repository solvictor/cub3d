#include "cub3d.h"

double	deg_to_rad(int deg)
{
	return (deg * M_PI / 180);
}

int	quadrant_of_angle(int deg)
{
	if (0 <= deg && deg < 90)
		return (1);
	else if (90 <= deg && deg < 180)
		return (2);
	else if (180 <= deg && deg < 270)
		return (3);
	return (4);
}
