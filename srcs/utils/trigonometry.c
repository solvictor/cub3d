#include "cub3d.h"

//TO DELETE START
double	deg_to_rad(int deg)
{
	return (deg * PI / 180);
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
//TO DELETE END

void	correct_angle(float *angle)
{
	// printf("Input angle %f\n", angle);
	if (*angle < 0)
		*angle += 2 * PI;
	if (*angle > 2 * PI)
		*angle -= 2 * PI;
	// printf("Output angle %f\n", angle);	
}

float	hyp_v(t_vector v1, t_vector v2)
{
	return (sqrt(fabs((v2.x - v1.x) * (v2.x - v1.x)
				- (v2.y - v1.y) * (v2.y - v1.y))));
}

float	hyp(float x1, float y1, float x2, float y2)
{
	return (sqrt(fabs((x2 - x1) * (x2 - x1) - (y2 - y1) * (y2 - y1))));
}
